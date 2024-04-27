#include "file.h"

bool FileInfo::OpenTheFile() {
	DWORD share_mode = 0, create_disposition = 0, access = 0, attribute = 0;
	if (read) {
		share_mode |= FILE_SHARE_READ;
		access = GENERIC_READ;
	}
	if (write) {
		share_mode |= FILE_SHARE_WRITE;
		access = GENERIC_WRITE;
	}
	create_disposition = OPEN_ALWAYS;
	attribute = FILE_ATTRIBUTE_NORMAL;
	// Creating the file with the specified flags;
	file_handle = CreateFileA(file_name.c_str(), access, share_mode, NULL, create_disposition, attribute, NULL);
	if (file_handle == 0 || file_handle == INVALID_HANDLE_VALUE) {
		return false;
	}
	else {
		return true;
	}
}

std::vector<char> FileInfo::ReadTheFile() {
	if (!IsFileOpen()) {
		return {};
	}
	char buffer[BUFFER_LENGTH];
	DWORD bytes_to_read = BUFFER_LENGTH - 1;
	DWORD read_bytes = 1;
	bool res = true;
	std::vector<char> result = {  };

	while (read_bytes > 0) {
		ZeroMemory(buffer, sizeof(buffer));
		res = ReadFile(file_handle, buffer, bytes_to_read - 1, &read_bytes, NULL);
		for (int i = 0; i < read_bytes; i++) {
			result.push_back(buffer[i]);
		}
	}
	return result;
}

bool FileInfo::IsFileOpen() {
	return file_handle != 0 && file_handle != INVALID_HANDLE_VALUE;
}

bool FileInfo::Close() {
	return CloseHandle(this->file_handle);
}

bool FileInfo::WriteToFile(std::vector<char>& content) {
	if (file_handle == NULL || file_handle == INVALID_HANDLE_VALUE) {
		return false;
	}
	if (write) {
		size_t buffer_length = content.size();
		char* buffer = new char[buffer_length];
		for (int i = 0; i < buffer_length; i++) {
			buffer[i] = content[i];
		}
		DWORD written_bytes = 0;
		bool res =  WriteFile(file_handle, buffer, buffer_length, &written_bytes, NULL);
		return res;
	}
	else {
		std::cout << "This operation is impossible" << '\n';
	}
}
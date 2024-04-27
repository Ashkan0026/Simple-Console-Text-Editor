#include <Windows.h>
#include <iostream>
#include <vector>

#define BUFFER_LENGTH 512

class FileInfo {
public:
	FileInfo(std::string file_name, bool read, bool write) {
		this->file_name = file_name;
		this->read = read;
		this->write = write;
		this->file_handle = INVALID_HANDLE_VALUE;
	}

	/// <summary>
	/// Opens the file, if file exists just opens it otherwise it will create that file
	/// </summary>
	/// <returns>If the creation or opening was successful it return true</returns>
	bool OpenTheFile();

	/// <summary>
	/// Reads the file and return an vector array of that file
	/// </summary>
	/// <returns>contents of file</returns>
	std::vector<char> ReadTheFile();

	/// <summary>
	/// checks whether the file is open or not, with the file_handle attribute
	/// </summary>
	/// <returns>A bool whether the file is open or not</returns>
	bool IsFileOpen();

	/// <summary>
	/// Closing the file
	/// </summary>
	/// <returns>True if Closing was successful</returns>
	bool Close();

	/// <summary>
	/// Writing the file to the file
	/// </summary>
	/// <param name="content">The specified content to write to file</param>
	/// <returns></returns>
	bool WriteToFile(std::vector<char>& content);

private:
	HANDLE file_handle;
	std::string file_name;
	bool read;
	bool write;
};
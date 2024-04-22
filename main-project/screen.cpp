#include "screen.h"

void screen_related::SetTheColor(Color foreground, Color background) {
	
}

int screen_related::GetWidthLimit() {
	CONSOLE_SCREEN_BUFFER_INFO buffer_info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buffer_info);
	return buffer_info.srWindow.Right - buffer_info.srWindow.Left + 1;
}

int screen_related::GetHeightLimit() {
	CONSOLE_SCREEN_BUFFER_INFO buffer_info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buffer_info);
	return buffer_info.srWindow.Bottom - buffer_info.srWindow.Top + 1;
}

void screen_related::PrintChar(char ch) {
	std::cout << ch;
}

void screen_related::SetConsolePosition(int x, int y) {
	COORD coord = {};
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void screen_related::ClearConsole() {
	system("cls");
}

void screen_related::PrintTheLine(Line* line) {
	auto contents = line->GetTheContent();
	for (int i = 0; i < contents.size(); i++) {
		std::cout << contents[i];
	}
}
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

void screen_related::CleanTheLine(int y, int line_limit) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	SMALL_RECT rect;
	COORD scroll_target;
	CHAR_INFO fill;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
		return;
	}

	rect.Left = 0;
	rect.Top = 0;
	rect.Right = line_limit;
	rect.Bottom = 0;
	
	scroll_target.X = line_limit;
	scroll_target.Y = 0;
	
	fill.Char.AsciiChar = '\0';
	fill.Attributes = csbi.wAttributes;

	ScrollConsoleScreenBufferA(hConsole, &rect, NULL, scroll_target, &fill);

	csbi.dwCursorPosition.X = 0;
	csbi.dwCursorPosition.Y = 0;

	SetConsoleCursorPosition(hConsole, csbi.dwCursorPosition);

}
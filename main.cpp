#include <iostream>
#include "editor.h"
#include "screen.h"
#include "input.h"
#include "file.h"
#include <filesystem>

using namespace editor_obj;
using namespace screen_related;
using namespace keyboard_input;

void PrintVector(std::vector<char> list, std::string msg) {
	std::cout << msg;
	for (char i : list) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

int main() {
	
	/*Editor editor = Editor();
	editor.InitializeFirstLine();
	editor.MainLoop();
	int ch = _getch();
	std::cout << ch << '\n';*/
	std::filesystem::remove("C:\\Users\\Ashkan\\Documents\\keykavous.txt");
}
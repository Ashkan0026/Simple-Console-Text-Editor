#include <iostream>
#include "editor.h"
#include "screen.h"
#include "input.h"

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
	
	Editor editor = Editor();
	editor.InitializeFirstLine();
	editor.MainLoop();
	
}
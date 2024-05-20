#include <iostream>
#include "editor.h"
#include <conio.h>

using namespace editor_obj;

void PrintVector(std::vector<char> list, std::string msg) {
	std::cout << msg;
	for (char i : list) {
		std::cout << i << ' ';
	}
	std::cout << '\n';
}

int main(char* argv[], int argc) {

	/*if (argc < 1) {
		std::cout << "Incorrect command" << '\n';
		return 1;
	}*/
	/*std::string file_name = "C:\\Users\\Ashkan\\Documents\\keykavousian.txt";
	Editor editor = Editor(file_name);
	editor.InitializeFirstLine();
	editor.MainLoop();*/
	
}
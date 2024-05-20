#include "editor.h"
#include "screen.h"
#include "input.h"
#include "file.h"

using namespace editor_obj;
using namespace screen_related;
using namespace keyboard_input;

bool Line::AddToTheLine(char ch, int x) {
	this->line_contents.insert(line_contents.begin() + x, ch);
	return true;
}

int Line::GetLineNumber() {
	return this->line_number;
}

bool Line::DeleteFromLine(int x) {
	if (x >= 0) {
		this->line_contents.erase(line_contents.begin() + x);
		return true;
	}
	else {
		return false;
	}
}

void Line::SetWidthLimit(int width_limit) {
	this->width_limit = width_limit;
}

bool Line::IsLineContentOver() {
	return this->line_contents.size() >= width_limit;
}

std::vector<char> Line::GetTheOvers() {
	std::vector<char> overs;
	for (int i = width_limit; i < line_contents.size(); i++) {
		overs.push_back(line_contents[i]);
	}

	for (int i = line_contents.size() - 1; i >= width_limit; i--) {
		line_contents.pop_back();
	}
	return overs;
}

std::vector<char> Line::GetTheOvers(int start_index) {
	std::vector<char> overs;
	for (int i = start_index; i < line_contents.size(); i++) {
		overs.push_back(line_contents[i]);
	}
	for (int i = line_contents.size() - 1; i >= start_index; i--) {
		line_contents.pop_back();
	}
	return overs;
}

std::vector<char> Line::GetTheContent() {
	return this->line_contents;
}

void Line::InsertAtBeginning(std::vector<char> begin) {
	for (int i = begin.size() - 1; i >= 0; i--) {
		line_contents.insert(line_contents.begin(), begin[i]);
	}
}

void Line::Clear() {
	this->line_contents.clear();
}

int Line::GetLineLimit() {
	return this->line_contents.size();
}

void Editor::InitializeFirstLine() {
	Line* first_line = new Line(line_counter++, screen_related::GetWidthLimit());
	this->lines.push_back(first_line);
}

void Editor::MainLoop() {
	/// This variables stands for coordinate of console
	int x = 0, y = 0;
	while (true) {
		int ch = GetInputFromUser();
		KeyState state = SetTheKeyState(ch);
		if (state == KeyState::EXIT) {
			break;
		}
		else if (state == KeyState::ARROW_LEFT) {
			ArrowLeftPressed(x, y, lines[y]->GetLineLimit(), lines.size());
		}
		else if (state == KeyState::ARROW_RIGHT) {
			ArrowRightPressed(x, y, lines[y]->GetLineLimit(), lines.size());
		}
		else if (state == KeyState::ARROW_UP) {
			ArrowUpPressed(y, x, lines.size());
		}
		else if (state == KeyState::ARROW_DOWN) {
			ArrowDownPressed(y, x, lines.size());
		}
		else if (state == KeyState::IGNORE_CASE) {
			/// Just ignore this shit
		}
		else if (state == KeyState::COPY) {

		}
		else if (state == KeyState::CUT) {

		}
		else if (state == KeyState::PASTE) {

		}
		else if (state == KeyState::NEXT_LINE) {
			GoToNextLine(x, y);
			ClearConsole();
			PrintAllTheLines();
			y++;
			x = 0;
		}
		else if (state == KeyState::SAVE) {
			SaveToFile(this->file_name);
		}
		else if (state == KeyState::BACKSPACE) {
			DeleteTheChar(y, x);
			ClearConsole();
			PrintAllTheLines();
			ArrowLeftPressed(x, y, lines[y]->GetLineLimit(), lines.size());
		}
		else if (state == KeyState::REGULAR) {
			bool val = AddCharacterToLine(ch, y, x);
			if (val) {
				ClearConsole();
				PrintAllTheLines();
			}
			else {
				SetConsolePosition(0, y);
				PrintTheLine(lines[y]);
			}
			ArrowRightPressed(x, y, GetWidthLimit(), lines.size());
		}
		SetConsolePosition(x, y);
	}
}

void editor_obj::Editor::ArrowLeftPressed(int& x, int& y, int max_width, int line_limit) {
	if (x <= 0) {
		if (y > 0) {
			y--;
			x = lines[y]->GetLineLimit();
		}
		else {
			// nothing
		}
	}
	else {
		x--;
	}
}

void editor_obj::Editor::ArrowRightPressed(int& x, int& y, int max_width, int line_limit) {
	if (x >= max_width) {
		if (y < line_limit - 1) {
			x = 0;
			y++;
		}
		else {
			// nothing
		}
	}
	else {
		x++;
	}
}

void editor_obj::Editor::ArrowUpPressed(int& y, int& x, int line_limit) {
	if (y <= 0) {
		// nothing
	}
	else {
		y--;
		x = x < lines[y]->GetLineLimit() ? x : lines[y]->GetLineLimit();
	}
}

void editor_obj::Editor::ArrowDownPressed(int& y, int& x, int line_limit) {
	if (y < line_limit - 1) {
		y++;
		x = x < lines[y]->GetLineLimit() ? x : lines[y]->GetLineLimit();
	}
	else {
		// nothing
	}
}

bool editor_obj::Editor::AddCharacterToLine(int ch, int& y, int& x) {
	this->lines[y]->AddToTheLine((char)ch, x);
	int line_number = y;
	while (lines[y]->IsLineContentOver()) {
		std::vector<char> overs = this->lines[line_number]->GetTheOvers();
		line_number++;
		if (line_number < lines.size()) {
			lines[line_number]->InsertAtBeginning(overs);
		}
		else {
			Line* new_line = new Line(lines.size(), GetWidthLimit());
			new_line->InsertAtBeginning(overs);
			lines.push_back(new_line);
			break;
		}
	}
	return line_number > y;
}

void editor_obj::Editor::PrintAllTheLines() {
	for (int i = 0;i<lines.size();i++) {
		SetConsolePosition(0, i);
		PrintTheLine(lines[i]);
	}
}

void editor_obj::Editor::GoToNextLine(int& x, int& y) {
	Line* new_line = new Line(y + 1, GetWidthLimit());
	std::vector<char> overs = lines[y]->GetTheOvers(x + 1);
	new_line->InsertAtBeginning(overs);
	lines.insert(lines.begin() + y + 1, new_line);
}

void editor_obj::Editor::DeleteTheChar(int& y, int& x) {
	while (y >= 0 && !lines[y]->DeleteFromLine(x - 1)) {
		y--;
		if (y < 0) {
			y = 0;
			break;
		}
		x = lines[y]->GetLineLimit();
	}
}

bool editor_obj::Editor::SaveToFile(std::string file_name) {
	FileInfo file = FileInfo(file_name, 1, 1);
	bool opening = file.OpenTheFile();
	if (!opening) {
		return false;
	}
	for (int i = 0; i < lines.size(); i++) {
		std::vector<char> new_arr = lines[i]->GetTheContent();
		new_arr.push_back('\n');
		bool res = file.WriteToFile(new_arr);
		if (!res) {
			return false;
		}
	}
	file.Close();
	return true;
}
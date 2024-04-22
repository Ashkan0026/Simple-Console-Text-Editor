#include "input.h"

int keyboard_input::GetInputFromUser() {
	int ch = _getch();
	return ch;
}

keyboard_input::KeyState keyboard_input::SetTheKeyState(int ch) {
	switch (ch)
	{
	case 27:
		return keyboard_input::KeyState::EXIT;
	case 3:
		return keyboard_input::KeyState::COPY;
	case 22:
		return keyboard_input::KeyState::PASTE;
	case 24:
		return keyboard_input::KeyState::CUT;
	case 4:
		return keyboard_input::KeyState::COLOR_CHANGE;
	case 75:
		return keyboard_input::KeyState::ARROW_LEFT;
	case 77:
		return keyboard_input::KeyState::ARROW_RIGHT;
	case 72:
		return keyboard_input::KeyState::ARROW_UP;
	case 80:
		return keyboard_input::KeyState::ARROW_DOWN;
	case 224:
		return keyboard_input::KeyState::IGNORE_CASE;
	case 13:
		return keyboard_input::KeyState::NEXT_LINE;
	default:
		return keyboard_input::KeyState::REGULAR;
	}
}
#pragma once
#include <conio.h>

namespace keyboard_input {
	/// <summary>
	/// Show the work that is going to be done
	/// </summary>
	enum KeyState
	{
		EXIT = 27, COPY = 3, PASTE = 22, CUT = 24, COLOR_CHANGE = 4, REGULAR = 0, ARROW_LEFT = 75, ARROW_RIGHT = 77, ARROW_UP = 72, ARROW_DOWN = 80, IGNORE_CASE = 224, NEXT_LINE = 13, BACKSPACE = 8
	};

	/// <summary>
	/// Get the input from the user
	/// </summary>
	/// <returns>Character input received from the user</returns>
	int GetInputFromUser();

	/// <summary>
	/// Map the input to the specified input
	/// </summary>
	/// <param name="ch">The character input received from the user</param>
	/// <returns>Return the key state</returns>
	KeyState SetTheKeyState(int ch);
}
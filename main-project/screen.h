#pragma once
#include <Windows.h>
#include "editor.h"
#include <iostream>

using namespace editor_obj;

namespace screen_related
{
	enum Color
	{
		GREEN, BLUE, RED, WHITE, BLACK, GRAY
	};
	
	// Set the background and foreground color of the console
	void SetTheColor(Color foreground, Color background);

	// Clear the Console
	void ClearConsole();

	/// <summary>
	/// Print the character on the screen
	/// </summary>
	/// <param name="ch">the character to be printed</param>
	void PrintChar(char ch);

	// Print The Line
	void PrintTheLine(Line* line);

	// Go To the Next Window
	void NextWindow(Editor& editor);

	/// <summary>
	/// Get the maximum width
	/// </summary>
	/// <returns>Returns the maximum width</returns>
	int GetWidthLimit();

	/// <summary>
	/// Get the maximum height limit
	/// </summary>
	/// <returns>Returns the maximum height limit</returns>
	int GetHeightLimit();

	/// <summary>
	/// Set the console cursor position
	/// </summary>
	/// <param name="x">The column</param>
	/// <param name="y">The row</param>
	void SetConsolePosition(int x, int y);
}
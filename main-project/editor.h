#pragma once
#include <vector>
#include <conio.h>

namespace editor_obj
{
	class Line
	{
	public:

		Line(int line_number, int width_limit) {
			this->line_number = line_number;
			this->width_limit = width_limit;
		}

		/// <summary>
		///  Adding the character to the line
		/// </summary>
		/// <param name="ch"></param>
		/// <returns>if the add was successful return true, otherwise go to next line</returns>
		bool AddToTheLine(char ch, int x);

		/// <summary>
		/// Delete the character at current_position - 1
		/// </summary>
		/// <returns>If the deletion was successful return true</returns>
		bool DeleteFromLine(int x);

		/// <summary>
		/// Get the current Line number
		/// </summary>
		/// <returns>The line number</returns>
		int GetLineNumber();

		/// <summary>
		/// Set the current width limit
		/// </summary>
		/// <param name="width_limit">the width limit to set to the field</param>
		void SetWidthLimit(int width_limit);

		/// <summary>
		/// Check if the vector length is higher than console width
		/// </summary>
		/// <returns>If the line have overlapped return true</returns>
		bool IsLineContentOver();

		/// <summary>
		/// return the Over characters
		/// </summary>
		/// <returns>Return the Overs</returns>
		std::vector<char> GetTheOvers();

		/// <summary>
		/// Return an array of overs when next line is pressed
		/// </summary>
		/// <param name="start_index">The start postion</param>
		/// <returns>a vector of characters</returns>
		std::vector<char> GetTheOvers(int start_index);

		/// <summary>
		/// Used to get the line content
		/// </summary>
		/// <returns>Returns the line content</returns>
		std::vector<char> GetTheContent();

		/// <summary>
		/// Gets a list and insert it at the zero index
		/// </summary>
		/// <param name="insertion"></param>
		void InsertAtBeginning(std::vector<char> insertion);

		/// <summary>
		/// Clearing the line
		/// </summary>
		void Clear();

		/// <summary>
		/// The contents size to traverse through
		/// </summary>
		/// <returns>Returns the line limit</returns>
		int GetLineLimit();

	private:
		std::vector<char> line_contents;
		int line_number;
		int width_limit;
	};

	class Editor
	{
	public:

		Editor(int number_of_lines) {
			this->number_of_lines = number_of_lines;
			this->line_counter = 0;
		}

		Editor() {
			this->number_of_lines = 1;
			this->line_counter = 0;
		}
		
		/// <summary>
		/// Initializing the first Line after first
		/// </summary>
		void InitializeFirstLine();
		/// <summary>
		/// The main function of the program
		/// </summary>
		void MainLoop();
		/// <summary>
		/// Decrease the x when the arrow left key is pressed
		/// </summary>
		/// <param name="x">The column of console</param>
		/// <param name="y">The row of console</param>
		void ArrowLeftPressed(int& x, int& y, int max_width, int line_limit);
		/// <summary>
		/// Increase the x when the arrow right key is pressed
		/// </summary>
		/// <param name="x"></param>
		/// <param name="y"></param>
		void ArrowRightPressed(int& x, int& y, int max_width, int line_limit);
		/// <summary>
		/// Decrease the y when the arrow up is pressed
		/// </summary>
		/// <param name="y">The row to change</param>
		void ArrowUpPressed(int& y, int& x, int line_limit);
		/// <summary>
		/// Increase the y when the arrow down is pressed
		/// </summary>
		/// <param name="y">The row to change</param>
		void ArrowDownPressed(int& y, int& x, int line_limit);
		/// <summary>
		/// Add the character to the line
		/// </summary>
		/// <param name="ch">The specified character to add to the line</param>
		/// <param name="x">The place to insert the characeter</param>
		/// <returns>If the value is added or not</returns>
		bool AddCharacterToLine(int ch, int& x, int& y);
		
		/// <summary>
		/// Printing all the lines
		/// </summary>
		void PrintAllTheLines();

		/// <summary>
		/// Go to the next line if there is, if there isn't create a new one
		/// </summary>
		/// <param name="x">The x coordinate</param>
		/// <param name="y">The specified line</param>
		void GoToNextLine(int& x, int& y);
	private:
		// the lines here
		std::vector<Line*> lines;
		// maximum lines of the window
		int number_of_lines;
		/// <summary>
		/// When we try to add newLine this will work
		/// </summary>
		int line_counter;
	};
}
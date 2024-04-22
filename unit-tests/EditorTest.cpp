#include "pch.h"
#include "CppUnitTest.h"
#include "../Editor/editor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EditorTest
{
	TEST_CLASS(EditorTest)
	{
	public:
		
		bool CheckIfEqual(std::vector<char>& overs, std::vector<char>& expected) {
			if (overs.size() != expected.size()) {
				return false;
			}
			for (int i = 0; i < overs.size(); i++) {
				if (overs[i] != expected[i]) {
					return false;
				}
			}
			return true;
		}

		TEST_METHOD(TestMethod1)
		{
			using namespace editor_obj;
			/// Line Tests
			/// Test1 GetTheOvers
			std::vector<char> example = {'1', '2', '4', '3', 'k', 't', 'r', 'e', 'u', 'a', 'e', 'A', 'R', '%', ';'};
			Line line = Line(2, 10);
			for (int i = 0; i < example.size(); i++) {
				line.AddToTheLine(example[i], i);
			}

			std::vector<char> expected = { 'e', 'A', 'R', '%', ';' };
			std::vector<char> overs = line.GetTheOvers();
			Assert::AreEqual(true, CheckIfEqual(overs, expected));

			/// Test2
			/// Get The Overs with index
			example.clear();
			example = {'5', 'J', 't', '^', '$', '#', 'M', '{', '}', '\\', '?'};
			line = Line(3, 7);
			for (int i = 0; i < example.size(); i++) {
				line.AddToTheLine(example[i], i);
			}
			expected.clear();
			expected = { '#', 'M', '{', '}', '\\', '?' };
			overs = line.GetTheOvers(5);
			Assert::AreEqual(true, CheckIfEqual(overs, expected));

			/// Test3
			/// Delete the character
			example.clear();
			example = {'d', 'a', 'v', 'i', 'd', 'd', 'a', 'v', 'i', 'd', 'o', 's', 'a', '%', '4', '#'};
			line = Line(4, 8);
			for (int i = 0; i < example.size(); i++) {
				line.AddToTheLine(example[i], i);
			}
			expected.clear();
			line.DeleteFromLine(3);
			line.DeleteFromLine(3);
			expected = { 'd', 'a', 'v', 'd', 'a', 'v', 'i', 'd', 'o', 's', 'a', '%', '4', '#' };
			Assert::AreEqual(true, CheckIfEqual(line.GetTheContent(), expected));
		}
	};
}

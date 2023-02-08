#include <iostream>
using namespace std;

#pragma region CenterText
	void CenterText()
	{
		bool front = true;
		string message = "Hello World";
		int totalSpace = 33;
		//using borders to show its centered
		cout << "|"; //Border before

		//i = message.length(), it skips enough spaces for text to be in middle
		for (int i = message.length(); i < totalSpace; i++)
		{
			if (front)
			{
				//Add space before message
				message = " " + message;
			}
			else
			{
				//add space after message
				message = message + " ";
			}
			//To change from front and back every go
			//Sets if false = true and if true = false
			front = !front;
		}
		//Prints message << border to show its centered
		cout << message.c_str() << "|";
	}
#pragma endregion

void main()
{
	CenterText();
}
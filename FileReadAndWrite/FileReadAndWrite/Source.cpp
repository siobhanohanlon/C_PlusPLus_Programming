#include <iostream> //Input&Output
#include <fstream> //File Access

using namespace std; //Needed for includes

//Define Functions- as functions only called once can also just put main function at end
void WritetoFile();
void WritetoFileStr();
void ReadfromFileStr();

void main()
{
	//Numbers Saved
	WritetoFile();

	//Skip Line
	cout << endl << endl;

	//String Saved
	WritetoFileStr();
	ReadfromFileStr();
}

#pragma region Numbers
void ReadfromFile(int l)
{
	ifstream fileIn; // Create Instance

	int num; //Variable for input value

	fileIn.open("FileName.txt"); //Open File you want to read

	//If file couldnt be opened
	if (!fileIn)
	{
		//cerr prints error message
		cerr << "File could not be opened!";
	}

	fileIn >> num;

	for (int j = 0; j < l; j++) //Keeps reading until end of file
	{
		cout << num; //Prints File Data
		fileIn >> num;
	}

	fileIn.close(); //Close file
}
void WritetoFile()
{
	ofstream fileOut; //Create Instance

	int length, num[] = { 1,2,3,4,5 }; //Array to Save

	fileOut.open("FileName.txt"); //Open File you want to write to

	//If file couldnt be opened
	if (!fileOut)
	{
		//cerr prints error message
		cerr << "File could not be opened!";
		exit(1);
	}

	//Fing length of array
	length = sizeof(num)/sizeof(num[0]);

	//Save full array
	for (int i = 0; i < length; i++)
	{
		fileOut << num[i]; //Write to File
		fileOut << " ";
	}

	fileOut.close(); //Close File

	ReadfromFile(length);
}
#pragma endregion

#pragma region String
void WritetoFileStr()
{
	ofstream fileOutStr; //Create Instance

	fileOutStr.open("FileNameStr.txt"); //Open File you want to write to

	fileOutStr << "Write HereQ"; //Write to File, Q used to end loop when reading

	fileOutStr.close(); //Close File
}

void ReadfromFileStr()
{
	ifstream fileInStr; // Create Instance

	char letter; //Variable for input value

	fileInStr.open("FileNameStr.txt"); //Open File you want to read

	//If file couldnt be opened
	if (!fileInStr)
	{
		//cerr prints error message
		cerr << "File could not be opened!";
	}

	fileInStr >> letter;

	while (letter != 'Q') //Keeps reading until end of file
	{
		cout << letter; //Prints File Data
		fileInStr >> letter;
	}
	cout << endl << endl; //2 New lines

	fileInStr.close(); //Close file
}
#pragma endregion
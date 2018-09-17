// Joshua Smith
// COSC 2030
// Lab 01

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

int main() {
	int count = 0;
	double temp = 0;
	double first1 = 0;
	double first2 = 0;
	double last1 = 0;
	double last2 = 0;
	string filename = "0"; //set to 0 to be compared to see if it's been changed
	ifstream buffer;

	while (filename == "0") { //while the filename goes unchanged
		cout << "Type the filename of your number list: ";
		cin >> filename; //does not ask questions beyond, barely any error checking
	}
	buffer.open(filename); //opens user input filename
	buffer >> first1; //takes first number in file and stores it into first1
	count++; //increases count so the loop doesn't miss the beginning
	buffer >> first2; // again for the 2nd
	count++;
	buffer >> last2; //sets the 3rd number to the very last
	count++;
	while (buffer >> temp)
	{
		last1 = last2; //sets the 2nd to last to previous last
		last2 = temp; //then sets last to whatever was just read
		count++;//increase count for each number read
	}
	cout << "First number: " << first1 << endl;
	cout << "Second number: " << first2 << endl;
	cout << "Second to last number: " << last1 << endl;
	cout << "Last number: " << last2 << endl;
	cout << "Number count: " << count << endl;
	//this code would break if there was less than 4 numbers in the file
	buffer.close();
	system("pause");
	return 0;
}
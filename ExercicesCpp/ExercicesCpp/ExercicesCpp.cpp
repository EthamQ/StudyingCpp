// "ConsoleApplication3.cpp": Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "string"
#include <iostream>

using namespace std;

//Task: 
//Coding Interview Question: Given an integer, 
//write a function to return its roman numeral representation.

//Define functions
string roman(int value);


//returns the roman representation in a string depending on the position within the int value you want to convert
//the first digit of the int value has the highest position and the last digit has the position 0
//Example: 367: position(7) = 0, position(6) = 1, position(3) = 2
string convert(int currentValue, int position) {
	if (position == 0) {
		switch (currentValue) {
		case 0: return ""; break;
		case 1: return "I"; break;
		case 2: return "II"; break;
		case 3: return "III"; break;
		case 4: return "IV"; break;
		case 5: return "V"; break;
		case 6: return "VI"; break;
		case 7: return "VII"; break;
		case 8: return "VIII"; break;
		case 9: return "IX"; break;
		}
	}

	if (position == 1) {
		switch (currentValue) {
		case 0: return ""; break;
		case 1: return "X"; break;
		case 2: return "XX"; break;
		case 3: return "XXX"; break;
		case 4: return "XL"; break;
		case 5: return "L"; break;
		case 6: return "LX"; break;
		case 7: return "LXX"; break;
		case 8: return "LXXX"; break;
		case 9: return "XC"; break;
		}
	}

	if (position == 2) {
		switch (currentValue) {
		case 0: return ""; break;
		case 1: return "C"; break;
		case 2: return "CC"; break;
		case 3: return "CCC"; break;
		case 4: return "CD"; break;
		case 5: return "D"; break;
		case 6: return "DC"; break;
		case 7: return "DCC"; break;
		case 8: return "DCCC"; break;
		case 9: return "CM"; break;
		}
	}


}

string roman(int value) {
	//Hint: for a definition of the variable position look at the documentation of the convert function

	//initializing the string i want to return with its last digit in roman representation
	int position = 0;
	string ret = convert(value % 10, position);

	//remove the last digit in order to access position 1 during the next steps
	value /= 10;

	//temp will be used to access the last digit in the while loop with modulo
	int temp = value;


	while (value != 0) {
		//one position to the left
		position++;

		//call the convert function with the last digit of value
		temp = value % 10;
		ret = convert(temp, position) + ret;

		//remove last digit, exit the while loop if there's no digit left
		value /= 10;
	}

	return ret;



}



int main()
{

	cout << roman(854);
	cin.get();
	return 0;
}




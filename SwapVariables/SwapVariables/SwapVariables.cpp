// "SwapVariables.cpp": Definiert den Einstiegspunkt für die Konsolenanwendung.
//

//--------------------------------------------------------------------------------------------
//TASK:
//Given two integers, write a function that swaps them without using any temporary variables.
//--------------------------------------------------------------------------------------------


#include "stdafx.h"
#include <iostream>


void swap(int* a, int* b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;

}

void swapREF(int& a, int& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

int main()
{

	//3 possibilities:

	//1
	int a = 5;
	int b = 9;
	std::cout << "Before swap: " << "\na: " << a << "\nb: " << b << std::endl;
	swap(&a, &b);
	std::cout << "After swap: " << "\na: " << a << "\nb: " << b << "\n\n";
	
	//2
	int k = 0;
	int j = 8;
	std::cout << "Before swapREF: " << "\nk: " << k << "\nj: " << j << std::endl;
	swapREF(k, j);
	std::cout << "After swapREF: " << "\nk: " << k << "\nj: " << j << "\n\n";

	//3
	int n = -5;
	int m = -12;
	int& nREF = n;
	int& mREF = m;
	std::cout << "Before swapREF: " << "\nn: " << n << "\nm: " << m << std::endl;
	swapREF(nREF, mREF);
	std::cout << "After swapREF: " << "\nn: " << n << "\nm: " << m << "\n\n";
	

	

	std::cin.get();
    return 0;
}


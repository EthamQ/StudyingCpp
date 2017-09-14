// "Fibonacci.cpp": Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>

//recursive
int fibR(int n) {
	if (n <= 0) {
		return 0;
	}

	if (n == 1) {
		return 1;
	}
	return fibR(n - 2) + fibR(n - 1);
}

//iterative
int fibI(int n) {
	if (n == 1) {
		return 1;
	}

	if (n < 1) {
		return 0;
	}

	int ret;
	int prev = 1;
	int pprev = 0;

	for (int i = 2; i <= n; i++) {
	ret = prev + pprev;
	pprev = prev;
	prev = ret;
}
	return ret;	
}



//dynamic
int fibD(int n, int result, int prev) {

	if (n == 0) {
		return result;
	}
	return fibD(n-1, (result + prev), result);
	
}

//dynamic helper
int fibD(int n) {
	return (fibD(n, 0, 1));
}




int main()
{
	for (int i = 1; i <= 10; i++) {
		std::cout << i << ": " <<fibR(i) << ", " << fibI(i) << ", " << fibD(i) << std::endl;
	}

std::cin.get();
    return 0;
}


#include "Chapter6.h"
#include<iostream>

int fact(int x) {
	int result = 1;
	for (int i = 1; i <= x; ++i) {
		result *= i;
	}

	return result;
}

int fact_interact() {
	int result = 1;
	int a;
	std::cout << "Enter a number:";
	std::cin >> a;
	for (int i = 1; i <= a; ++i) {
		result *= i;
	}

	return result;
}

int abs_test(int a)
{
	return (a >= 0 ? a : -a);
}
#include<iostream>
#include "Sales_item.h"

int main()
{
	Sales_item sum, item;
	while (std::cin >> item) {
		sum = sum + item;
	}

	std::cout << sum << std::endl;

	return 0;
}
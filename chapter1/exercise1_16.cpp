#include<iostream>

int main()
{
	std::cout << "Enter a group of number: " << std::endl;
	int value = 0, sum = 0;
	while (std::cin >> value) {
		sum += value;
	}

	std::cout << "Sum of the numbers is " << sum;
	
	return 0;
}
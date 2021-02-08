#include<iostream>

int abs(int a) 
{
	if (a >= 0) {
		return a;
	}
	else {
		return -a;
	}
}

int main()
{
	int x = -5;
	std::cout << x << " " << abs(x) << std::endl;
	return 0;
}
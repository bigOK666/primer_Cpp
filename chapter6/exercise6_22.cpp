#include<iostream>

void swapPointer(int* &a, int* &b)
{
	int* temp = b;
	b = a;
	a = temp;
}

int main()
{
	int i = 10, j = 20;
	int* ip = &i;
	int* jp = &j;
	swapPointer(ip, jp);

	std::cout << *ip << " " << *jp;

	return 0;


}
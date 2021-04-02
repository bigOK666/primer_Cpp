#include<typeinfo>
#include<iostream>
#include<string>
int main()
{
	int i = 0;
	int arr[10];
	std::string s;

	std::cout << typeid(i).name() << " " << typeid(arr).name() << " " << typeid(s).name() << std::endl;

}
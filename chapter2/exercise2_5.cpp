#include<typeinfo>
#include<iostream>

int main()
{

	std::cout << typeid("a").name() << std::endl;
	std::cout << typeid(L"a").name() << std::endl;

	std::cout << "F\145rgus?\012" << std::endl;

	std::cout << "F\145rgus?\12" << std::endl;

	std::cout << "2\x4d\12" << std::endl;
	std::cout << "2\t\x4d\n" << std::endl;

	return 0;
}
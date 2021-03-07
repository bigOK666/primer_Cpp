#include<iostream>

int main()
{
	std::cout << "Enter the size of a string that you want:" << std::endl;
	int size(0);
	std::cin >> size;
	char* store = new char[size+1]();
	//std::cin.ignore();
	std::cout << "Enter the string:" << std::endl;
	//从输入流中只获取size个字符+1个终结符，存到store中
	std::cin.get(store, size + 1);
	//std::cin >> store;

	std::cout << store;

	delete[] store;


}
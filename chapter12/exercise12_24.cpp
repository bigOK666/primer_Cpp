#include<iostream>

int main()
{
	std::cout << "Enter the size of a string that you want:" << std::endl;
	int size(0);
	std::cin >> size;
	char* store = new char[size+1]();
	//std::cin.ignore();
	std::cout << "Enter the string:" << std::endl;
	//����������ֻ��ȡsize���ַ�+1���ս�����浽store��
	std::cin.get(store, size + 1);
	//std::cin >> store;

	std::cout << store;

	delete[] store;


}
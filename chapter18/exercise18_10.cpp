#include"exercise18_9.h"
#include<iostream>
int main()
{
	Sales_data item1("book1", 10, 20);
	Sales_data item2("book2", 20, 30);
	//����������쳣������ֱ����ֹ�ڵڰ���
	//item1 += item2;

	std::cout << "catch exception" << std::endl;
	try {
		item1 += item2;
	}
	catch (const isbn_mismatch& e) {
		std::cerr << e.what() << ":left isbn is " << e.left << " right isbn is " << e.right << std::endl;
	}
	
}
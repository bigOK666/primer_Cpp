#include"exercise7_53.h"
#include<string>
#include<iostream>
struct Data {
	int ival;
	
};

int main()
{
	constexpr Debug io_sub(false, true, false);
	//io_sub 对象被创建为constexpr时不可更改，但可以声明为无constexpr的形式
	//io_sub.set_io(true);
	
	//7
	Data t = {0};
	
	std::cout << std::is_literal_type<int>::value;
}
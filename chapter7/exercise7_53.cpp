#include"exercise7_53.h"
#include<string>
#include<iostream>
struct Data {
	int ival;
	
};

int main()
{
	constexpr Debug io_sub(false, true, false);
	//io_sub ���󱻴���Ϊconstexprʱ���ɸ��ģ�����������Ϊ��constexpr����ʽ
	//io_sub.set_io(true);
	
	//7
	Data t = {0};
	
	std::cout << std::is_literal_type<int>::value;
}
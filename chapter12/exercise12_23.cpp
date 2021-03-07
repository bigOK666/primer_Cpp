#include<new>
#include<memory>
#include<string>
#include<cstring>
#include<iostream>

int main()
{
	const char* a = "Test1";
	const char* b = "Test2";
	char* combine = new char[strlen(a) + strlen(b) + 1]();//()使得值初始化为空字符串
	std::cout << combine << std::endl;
	strcat(combine, a);
	std::cout << combine << std::endl;
	strcat(combine, b);

	std::cout << combine << std::endl;

	
	delete[] combine;

	std::string s1("STest1");
	std::string s2("STest2");

	char* scombine = new char[s1.size() + s2.size() + 1]();

	strcat(scombine, s1.c_str());
	strcat(scombine, s2.c_str());

	std::cout << scombine << std::endl;

	delete[] scombine;

}
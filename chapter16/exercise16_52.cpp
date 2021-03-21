#include<iostream>

template<typename T, typename... Args>
void foo(const T& t, const Args&... rest) {
	std::cout << sizeof...(Args) << std::endl;
	std::cout << sizeof...(rest) << std::endl;
}


int main()
{
	int i = 0; double d = 2.3; std::string s("How");

	foo(i, s, 40, d);
	foo(s, 42, "hi");
	foo(d, s);
	foo("sdf");
}
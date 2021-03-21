#include<iostream>

template<typename T>std::ostream& 
print(std::ostream& os, const T& t)
{
	return os << t;
}

template<typename T, typename... Args>
std::ostream& print(std::ostream& os, const T& t, const Args&... rest)
{
	os << t << ", ";
	return print(os, rest...);
}

int main()
{
	int i = 0; double d = 2.3; std::string s("test"); long l = 3352;

	print(std::cout, i, d, s, l);
}
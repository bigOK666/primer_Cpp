#include<iostream>
#include<string>
#include<sstream>

std::string debup_rep(const std::string&);
template<typename T> std::string debug_rep(const T& t) {
	std::ostringstream ret;
	ret << t;
	return ret.str();
}

template<typename T>std::string debug_rep(T* p)
{
	std::ostringstream ret;
	ret << "pointer:: " << p;
	if (p)
		ret << " " << debug_rep(*p);
	else
		ret << " null pointer";
	return ret.str();
}

std::string debup_rep(const std::string& s) {
	return '"' + s + '"';
}

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


template<typename... Args>
std::ostream& errMsg(std::ostream& os, const Args&... rest)
{
	return print(os, debug_rep(rest)...);
}

int main()
{
	int i = 2, * p = &i;
	double d = 2.3, *pd = &d;
	std::string s("test");

	errMsg(std::cout, i, p, d, pd, s);
}
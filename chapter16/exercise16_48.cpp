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
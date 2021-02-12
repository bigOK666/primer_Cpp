#include<string>
#include<iostream>
using std::string;

constexpr bool isShorter(const string& s1, const string& s2) {
	//wrong, because size() does not return constexpr
	return s1.size() < s2.size();
}

int main()
{
	std::cout<<isShorter("Test", "Test2");
}
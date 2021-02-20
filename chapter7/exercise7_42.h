#include<string>
#include<iostream>
class Date {
public:
	
	Date(std::string y, std::string m, std::string d) : year(y), month(m), day(d) {}
	//delegating constructor
	Date() :Date("0000", "Feb", "01") { std::cout << "Default delegating constructor"; }
	void get_date() { std::cout << year << " " << month << " " << day; }
private:
	std::string year{ "0000" };
	//std::string yea("asdf");//类内初始值不能用圆括号
	std::string month{ "Jan" };
	std::string day{ "01" };
};
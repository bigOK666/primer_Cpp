#include<string>

class Book {
public:
	Book() = default;
	Book(std::string bn, unsigned us, double pr) :bookNo(bn), units_sold(us), revenue(pr*us) {};
private:
	std::string bookNo;
	int units_sold = 0;
	double revenue = 0;
};
class Date {
public:
	Date() = default;
	Date(std::string y, std::string m, std::string d) : year(y), month(m), day(d) {};
private:
	std::string year{ "0000" };
	//std::string yea("asdf");//类内初始值不能用圆括号
	std::string month{ "Jan" };
	std::string day{ "01" };
};

class Employee {
public:
	Employee() = default;
	Employee(std::string n, std::string p, double s) :name(n), position(p), salary(s) {};
private:
	std::string name;
	std::string position;
	double salary;
};

class Vehicle {
private:
	std::string name;
	double price = 0;
};

class Object {

};

class Tree {

};
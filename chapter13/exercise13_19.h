#include<string>
#include<iostream>
class Employee {
public:
	Employee(const std::string& n) :name(n), id(++nr_incr) {}
	Employee() :Employee(std::string()) {}
	Employee(const Employee&)=delete;
	Employee& operator=(Employee&) = delete;
	void displayID() { std::cout << id << std::endl; }
private:
	std::string name;
	unsigned id = 0;
	static unsigned nr_incr;
};

unsigned Employee::nr_incr = 0;
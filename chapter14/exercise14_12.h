#include<string>
#include<iostream>
class Employee {

	friend std::ostream& operator<<(std::ostream& os, const Employee&);
	friend std::istream& operator>>(std::istream& is, Employee&);
public:
	Employee() :Employee("", "", 0) {};
	Employee(const std::string& n, const std::string& d, double s) :name(n), department(d), salary(0) {};


private:
	std::string name;
	std::string department;
	double salary = 0;

};

std::ostream& operator<<(std::ostream& os, const Employee& e)
{
	os << e.name << " " << e.department << " " << e.salary;
	return os;
}

std::istream& operator>>(std::istream& is, Employee& e)
{
	is >> e.name >> e.department >> e.salary;
	if (!is) {
		e = Employee();
		std::cout << "invalid input";
	}

	return is;

}
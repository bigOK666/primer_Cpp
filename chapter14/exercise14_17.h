#include<string>
#include<iostream>
class Employee {

	friend std::ostream& operator<<(std::ostream& os, const Employee&);
	friend std::istream& operator>>(std::istream& is, Employee&);
	friend bool operator==(const Employee&, const Employee&);
	friend bool operator!=(const Employee&, const Employee&);

public:
	Employee() :Employee("", "","", 0) {};
	Employee(const std::string& n, const std::string& d, const std::string& i, double s) :name(n), department(d), id(i), salary(0) {};


private:
	std::string name;
	std::string department;
	std::string id;
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

bool operator==(const Employee& e1, const Employee& e2)
{
	return e1.id == e2.id;
}

bool operator!=(const Employee& e1, const Employee& e2)
{
	return !(e1 == e2);
}
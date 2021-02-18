#include<string>
#include<iostream>


struct Person {
	friend std::istream& read(std::istream& is, Person& aPerson);
	friend std::ostream& print(std::ostream& os, const Person& aPerson);
private:
	std::string name;
	std::string adress;
	//get_name 和get_adr可以声明为const，也可以不声明为const，都能编译。 但最好声明为const，因为他们只返回值，不会做更改。
public:
	const std::string get_name() const { return name; }
	const std::string get_adr() const { return adress; }
};

std::istream& read(std::istream& is, Person& aPerson)
{
	is >> aPerson.name >> aPerson.adress;
	return is;
}

std::ostream& print(std::ostream& os, const Person& aPerson)
{
	os << aPerson.get_name() << aPerson.get_adr();
	return os;
}
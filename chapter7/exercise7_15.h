#include<string>
#include<iostream>

struct Person;

std::istream& read(std::istream& is, Person& p)
{
	is >> p.name >> p.adress;
	return is;
}

struct Person {
	Person() = default;
	Person(const std::string& n, const std::string& a) :name(n), adress(a) {};
	Person(std::istream& is) { read(is, *this); }
	std::string name;
	std::string adress;
	//get_name 和get_adr可以声明为const，也可以不声明为const，都能编译。 但最好声明为const，因为他们只返回值，不会做更改。
	const std::string get_name() const { return name; }
	const std::string get_adr() const { return adress; }
};
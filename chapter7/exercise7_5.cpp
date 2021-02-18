#include<string>
#include<iostream>
using std::string;

struct Person {
	string firstName;
	string lastName;
	string adress;
	//get_name 和get_adr可以声明为const，也可以不声明为const，都能编译。 但最好声明为const，因为他们只返回值，不会做更改。
	const string get_name() const { return firstName + " " + lastName; }
	string get_adr() const { return adress; }
};

int main()
{
	Person a;
	a.adress = "Astreet.2";

	const string aAdr = a.get_adr();

	std::cout << aAdr;
}
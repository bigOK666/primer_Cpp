#include<string>
#include<iostream>
using std::string;

struct Person {
	string firstName;
	string lastName;
	string adress;
	//get_name ��get_adr��������Ϊconst��Ҳ���Բ�����Ϊconst�����ܱ��롣 ���������Ϊconst����Ϊ����ֻ����ֵ�����������ġ�
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
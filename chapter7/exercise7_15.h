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
	//get_name ��get_adr��������Ϊconst��Ҳ���Բ�����Ϊconst�����ܱ��롣 ���������Ϊconst����Ϊ����ֻ����ֵ�����������ġ�
	const std::string get_name() const { return name; }
	const std::string get_adr() const { return adress; }
};
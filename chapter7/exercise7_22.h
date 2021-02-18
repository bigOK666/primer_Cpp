#include<string>
#include<iostream>


struct Person {
	friend std::istream& read(std::istream& is, Person& aPerson);
	friend std::ostream& print(std::ostream& os, const Person& aPerson);
private:
	std::string name;
	std::string adress;
	//get_name ��get_adr��������Ϊconst��Ҳ���Բ�����Ϊconst�����ܱ��롣 ���������Ϊconst����Ϊ����ֻ����ֵ�����������ġ�
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
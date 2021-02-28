#include<string>
#include<iostream>
using namespace std;
void findWithFirst(const string& s)
{
	string numbers{ "0123456789" };
	string alphabetes{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };

	string::size_type pos = 0;
	cout << "Numbers are at position " << endl;
	while ((pos = s.find_first_of(numbers,pos)) != string::npos) {
		cout << pos << endl;
		++pos;
	}
	
	string::size_type pos_a = 0;
	cout << "Alphabeta is at position " << endl;
	while ((pos_a = s.find_first_of(alphabetes, pos_a)) != string::npos){
		cout << pos_a << endl;
		++pos_a;
	}
	
}

void findWithFirstNot(const string& s)
{
	string numbers{ "0123456789" };
	string alphabetes{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };

	string::size_type pos = 0;
	cout << "Numbers are at position " << endl;
	while ((pos = s.find_first_not_of(alphabetes, pos)) != string::npos) {
		cout << pos << endl;
		++pos;
	}
	auto pos_a = 0;
	cout << "Alphabeta is at position " << endl;
	while ((pos_a = s.find_first_not_of(numbers, pos_a)) != string::npos) {
		cout << pos_a << endl;
		++pos_a;
	}
}

int main()
{
	string s("ab2c3d7R4E6");

	findWithFirst(s);
	findWithFirstNot(s);
}
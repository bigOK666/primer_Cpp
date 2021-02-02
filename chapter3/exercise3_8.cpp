#include<iostream>
#include<string>
#include<typeinfo>
using std::string;
using std::cout;
using std::endl;
int main()
{
	string s("This should be X"), t = s;
	decltype(s.size()) i = 0;
	while (i < s.size()) {
		cout << typeid(s[i]).name() << endl;
		s[i] = 'X';
		++i;
	}
	cout << s<<endl;

	for (decltype(t.size()) j = 0; j < t.size(); ++j) {
		t[j] = 'X';
		
	}

	cout << t << endl;

	string a;
	cout << "a is "<< a[0] << endl;

	const string cs("Keep constant");
	cout << typeid(cs).name() << endl;
	for (auto& c : cs) {
			cout << typeid(c).name() << endl;
	}

	return 0;
}
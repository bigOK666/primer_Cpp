#include<string>
#include<iostream>
using namespace std;
void findAndReplace(string& s, const string& oldValue, const string& newValue)
{
	int pos = 0;
	auto n_o = oldValue.size();
	auto n_n = newValue.size();

	while (pos < (s.size() - n_o)) {
		if (oldValue == string(s, pos, n_o)) {
			s.replace(pos, n_o, newValue);
			pos += n_n;
		}
		else {
			++pos;
		}
	}
}

int main()
{
	std::string s{ "This is a test for abbreation. thx is thanks. ur is your" };
	std::string old{ "thx " };
	std::string new_v{ "Thanks " };

	findAndReplace(s, old, new_v);
	std::cout << s << std::endl;
	findAndReplace(s, "ur ", "your ");
	std::cout << s << std::endl;
}
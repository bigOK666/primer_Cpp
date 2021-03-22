#include<regex>
#include<string>
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
class Person_info {
public:
	std::string phones{"123-234-2334"};
};
bool valid(const smatch& m) {
	if (m[1].matched)
		return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[4].str() == m[6].str();
}

int main()
{
	string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?(\\d{4})";

	regex r(phone);
	string s;
	//smatch m;
	vector<Person_info> people;
	for (const auto& entry : people) {
		ostringstream formatted, badNums;
		for (auto& nums : entry.phones) {
			for (sregex_iterator it(nums.begin(), nums.end(), r), end_it; it != end_it; ++it) {
				if (valid(*it)) {
					cout << "valid: " << it->str() << endl;
					badNums << " " << nums;
				}
				else {
					cout << "not valid" << it->str() << endl;
				}
			}
		}
	}

	while (getline(cin, s)) {
		
	}
}

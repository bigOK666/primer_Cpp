#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

int main()
{
	vector<string> grades{ "F", "D", "C", "B", "A", "A++" };
	int score = 0;
	while (cin >> score) {
		score < 60 ? (cout << grades[0] << endl) : (cout<<grades[(score - 50) / 10]);
	}
	return 0;
}
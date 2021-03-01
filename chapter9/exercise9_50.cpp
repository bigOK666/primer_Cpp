#include<string>
#include<vector>
#include<iostream>
using namespace std;

int sumInt(const vector<string>& s)
{
	int sum = 0;

	for (auto i : s) {
		sum += stoi(i);
	}

	return sum;
}

double sumDouble(const vector<string>& s)
{
	double sum = 0;
	for (auto i : s) {
		sum += stod(i);
	}

	return sum;
}

int main()
{
	vector<string> v_i{ "1","2","3","4","5" };
	vector<string> v_d{ "1.1","2.2","3.3" };

	cout << sumInt(v_i) << endl;
	cout << sumDouble(v_d) << endl;
}
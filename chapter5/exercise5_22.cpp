#include<iostream>
#include<string>

using std::string;
int main()
{
	string s(3, 'c');
begin:
	int sz = s.size();
	if (sz <= 0) {
		goto begin;
	}

	//while ¸ÄÐ´
	int sz = s.size();
	while (sz <= 0) {
		s = s.size();
	}

	return 0;
}
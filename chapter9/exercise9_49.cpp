#include<fstream>
#include<string>
#include<iostream>
using namespace std;
bool isNoAscenDescen(const string& s)
{
	string ascender{ "bdfhijklt" };
	string descender{ "gjpqy" };

	return (s.find_first_of(ascender) == string::npos) && (s.find_first_of(descender) == string::npos);
}

int main(int argc, char **argv)
{
	ifstream ifs(argv[1], ifstream::in);
	string temp;
	string longest;
	while (ifs >> temp) {
		if (isNoAscenDescen(temp)&&(temp.size()>longest.size())) {
			longest = temp;
		}
	}

	cout << longest << endl;
}
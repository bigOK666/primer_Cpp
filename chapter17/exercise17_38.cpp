#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main(int argc, char** argv)
{
	ifstream infile("infile");
	cout << "file ready" << endl;
	char sink[40];
	cout << "char ready" << endl;
	while (infile.getline(sink, 39,' ')) {
		cout << "while ready" << endl;
		cout << sink[0];
		cout << sink;
	}
}
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int main(int argc, char** argv)
{
	ifstream infile("infile");
	
	char sink[40];
	while (infile.getline(sink, 39)) {
		cout << sink;
	}
}
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	cout <<right
		<<setw(12)<< hexfloat << uppercase << 100 * sqrt(2.0)<<'\n'
		<<setw(12)<<scientific<<100*sqrt(3.0)<<'\n'
		<<setw(12)<<defaultfloat<<100*sqrt(5)<<'\n'
		<<nouppercase<<left;
}
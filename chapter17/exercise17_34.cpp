#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int i = -16;
	double d = 3.14159;

	cout << boolalpha;
	cout << true;
	cout << noboolalpha;

	cout << showbase;
	cout << i;
	cout << noshowbase;
	cout << showpoint;
	cout << 10.0;
	cout << noshowpoint;
	cout << showpos;
	cout << d;
	cout << noshowpos;
	cout << uppercase;
	cout << hex << 15;
	cout << nouppercase;
	cout << 15;
	cout << oct << 7;
	cout << dec<<10<<'\n';
	cout << left << setw(12) << i << '\n' << setw(12) << right << d << '\n';

	cout << setfill('#') << "i:" << setw(12) << i;

}
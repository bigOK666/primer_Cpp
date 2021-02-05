#include<iostream>

using std::cout;
using std::endl;

int main()
{
	bool flag;
	char cval;
	short sval;
	unsigned short usval;
	int ival;
	unsigned int uival;

	long lval;
	unsigned long ulval;
	float fval;
	double dval;

	cout << sizeof flag << endl;
	cout << sizeof cval << endl;
	cout << sizeof sval << endl;
	cout << sizeof usval << endl;
	cout << sizeof ival << endl;
	cout << sizeof uival << endl;
	cout << sizeof lval << endl;
	cout << sizeof ulval << endl;
	cout << sizeof fval << endl;
	cout << sizeof dval << endl;

	return 0;

}
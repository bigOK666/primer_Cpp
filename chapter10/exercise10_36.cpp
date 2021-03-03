#include<algorithm>
#include<iterator>
#include<list>
#include<iostream>
using namespace std;

int main()
{
	list<int> l_i{ 1,2,3,4,5,65,0,0,0 };

	auto iter = find(l_i.rbegin(), l_i.rend(), 0);

	cout << *(++(++(++iter))) << endl;
}
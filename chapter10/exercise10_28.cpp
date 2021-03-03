#include<vector>
#include<iterator>
#include<algorithm>
#include<list>
#include<forward_list>
#include<iostream>
using namespace std;

void display(int i) {
	cout << i << " ";
}

int main()
{
	vector<int> v_i{ 1,2,3,4,5,6 };

	list<int> l;
	forward_list<int> f_l;
	vector<int> v_em;

	copy(v_i.cbegin(), v_i.cend(), back_inserter(l));
	copy(v_i.cbegin(), v_i.cend(), front_inserter(f_l));
	copy(v_i.cbegin(), v_i.cend(), inserter(v_em, v_em.begin()));

	
	for_each(l.cbegin(), l.cend(), display);
	for_each(f_l.cbegin(), f_l.cend(), display);
	for_each(v_em.cbegin(), v_em.cend(), display);
	
}
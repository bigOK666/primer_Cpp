#include<vector>
#include<list>
using std::vector;
using std::list;
int main()
{
	list<int> l_i{ 1,2,3 };
	vector<double> v_d(l_i.begin(), l_i.end());

	vector<int> v_i{ 1,2,3 };
	vector<double> v_d(v_i.begin(), v_i.end());
}
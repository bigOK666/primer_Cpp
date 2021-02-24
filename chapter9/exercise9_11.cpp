#include<vector>
using std::vector;
int main()
{
	vector<int> v1;
	vector<int> v2 = { 1,2 };
	vector<int>v3{ 1,3 };
	vector<int>v4(10);
	vector<int>v5(10, 4);
	vector<int>v6(v2);
	vector<int>v7 = v2;
	vector<int>v8(v2.begin(), v2.end());
}
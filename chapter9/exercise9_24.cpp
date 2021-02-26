#include<iostream>
#include<vector>

int main()
{
	std::vector<int> v_i;
	//std::vector<int> v_i{ 1,2,3,4,5,6,7 };

	int& i = v_i.at(2);
	int j = v_i[2];
	int k = v_i.front();
	int m = *v_i.begin();

	std::cout << i << " " << j << " " << k << " " << m;


}
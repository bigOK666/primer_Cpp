#include<vector>
#include<string>

int main()
{
	std::vector<char> v_c{ 'C', 'h','a','r' };
	std::string s(v_c.cbegin(), v_c.cend());
}
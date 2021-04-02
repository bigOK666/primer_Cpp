#include<algorithm>
#include<functional>
#include<vector>
#include<string>
unsigned cnt_v(const std::vector<std::string> v_s)
{
	return std::count_if(v_s.begin(), v_s.end(), std::mem_fn(&std::string::empty));
}
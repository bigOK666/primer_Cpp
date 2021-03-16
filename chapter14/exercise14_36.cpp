#include"exercise14_35.h"
#include<vector>
#include<algorithm>
#include<iterator>

int main()
{
	std::vector<std::string> v_s;
	getString get;
	while (std::cin) {
		v_s.push_back(get());
	}
	std::ostream_iterator<std::string> out_iter(std::cout, "\n");
	copy(v_s.cbegin(), v_s.cend(), out_iter);
	

}
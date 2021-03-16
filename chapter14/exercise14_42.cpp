#include<list>
#include<algorithm>
#include<functional>
#include<string>

int main()
{

	using std::placeholders::_1;
	std::list<int> l_i{ 1,2,4,400,1244,4222 };
	std::count_if(l_i.cbegin(), l_i.cend(), std::bind(std::greater<int>(), _1, 1024));


	std::list<std::string> l_s{ "test", "pooh","pooh","a" };
	std::find_if(l_s.cbegin(), l_s.cend(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"));

	std::list<double> l_d{ 2.3,443.2,22.3 };
	std::for_each(l_d.begin(), l_d.end(), std::bind(std::multiplies<double>(), _1, 2));
}

#include<tuple>
int main()
{
	std::tuple<int, int, int> t{ 10,20,30 };
	auto t2 = std::make_tuple(10, 20, 30);
}
#include<functional>
#include<map>
#include<string>

int add(int i, int j) { return i + j; }
int main()
{
	
	auto mod = [](int i, int j) {return i % j; };

	struct divide {
		int operator()(int i, int j) {
			return i / j;
		}
	};

	std::map<std::string, std::function<int(int, int)>> binops = {
		{"+", add},{"-",std::minus<int>()},{"*",[](int i, int j) {return i * j; }},
		{"/", divide()}, {"%",mod}

	};
}
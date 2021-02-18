#include"exercise7_11.h"

int main()
{
	Sales_data A("2-32-Nls", 3, 2);
	Sales_data B("2-32-lNls");
	Sales_data C;
	Sales_data D(std::cin);

	print(std::cout, A) << std::endl;
	print(std::cout, B) << std::endl;
	print(std::cout, C) << std::endl;
	print(std::cout, D) << std::endl;
}
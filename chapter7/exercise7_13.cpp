#include"exercise7_12.h"

int main()
{
	Sales_data total(std::cin);

	if (!total.bookNo.empty()) {
		//std::cin检查输入流中是否有数据，>>操作符会把输入流中的数据输出出来，如果没有>>操作符则不输出，只检查
		while (std::cin) {
			Sales_data trans(std::cin);
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(std::cout, total);
				total = trans;
			}
		}
		print(std::cout, total);
	}
	else {
		std::cerr << "No data" << std::endl;
		return -1;
	}
	return 0;
}
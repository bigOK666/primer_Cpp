#include"exercise15_7.h"
#include<iostream>
double print_total(std::ostream& os, const Quote& item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " sold: " << n << " total due: " << ret << std::endl;
	return ret;
}
int main()
{
	Quote q1("test1", 10);
	Bulk_quote b1("test2", 20, 5, 0.2);
	Limit_quote l1("test3", 100, 5, 0.1);

	print_total(std::cout, q1, 6);
	print_total(std::cout, b1, 10);
	print_total(std::cout, l1, 3);
}
#include"exercise15_5.h"
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

	print_total(std::cout, q1, 6);
	print_total(std::cout, b1, 10);
}
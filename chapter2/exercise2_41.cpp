#include<iostream>
#include<string>
#include"Sales_data.h"

int main()
{
	Sales_data book1, book2;
	double price = 0;
	std::cin >> book1.bookNo >> book1.units_sold >> price;
	book1.revenue = price * book1.units_sold;

	std::cout << book1.bookNo << " " << book1.units_sold << " " << book1.revenue;

	return 0;
}
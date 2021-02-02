#include<iostream>
#include<string>
#include"Sales_data.h"

int main()
{
	Sales_data book1, book_total;
	int price = 0;

	while(std::cin >> book1.bookNo >> book1.units_sold >> price) {
		book1.revenue = book1.units_sold * price;
		book_total.revenue += book1.revenue;
		book_total.units_sold += book1.units_sold;
	}

	book_total.bookNo = book1.bookNo;
	std::cout << book_total.bookNo << " " << book_total.units_sold << " " << book_total.revenue;

	return 0;

}
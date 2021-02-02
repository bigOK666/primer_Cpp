#include<iostream>
#include<string>
#include"Sales_data.h"

int main()
{
	int price = 0;
	Sales_data book1, book2;

	if (std::cin >> book1.bookNo >> book1.units_sold >> price) {
		int cnt = 1;
		//book1 occurs cnt times
		while (std::cin >> book2.bookNo >> book2.units_sold >> price) {
			if (book2.bookNo == book1.bookNo) {
				++cnt;
			}
			else {
				std::cout << book1.bookNo << " occurs " << cnt << " times." << std::endl;
				book1 = book2;
				cnt = 1;
			}

		}
		std::cout << book1.bookNo << " occurs " << cnt << " times." << std::endl;
		return 0;
	}
	else {
		std::cerr << "No data" << std::endl;
		return -1;
	}
}
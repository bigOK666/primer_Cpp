#include<iostream>
#include<string>
#include"Sales_data.h"

int main()
{
	Sales_data total, trans;
	int total_price, trans_price;

	if (std::cin >> total.bookNo >> total.units_sold >> total_price) {
		total.revenue = total.units_sold * total_price;
		while (std::cin >> trans.bookNo >> trans.units_sold >> trans_price) {
			trans.revenue = trans.units_sold * trans_price;
			if (trans.bookNo == total.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else {
				std::cout << total.bookNo << " sells " << total.units_sold << " benifits " << total.revenue << 
					"average "<< total.revenue/total.units_sold<<std::endl;
				total = trans;
			}
		}
		std::cout << total.bookNo << " sells " << total.units_sold << " benifits " << total.revenue << 
			"average " << total.revenue / total.units_sold << std::endl;
		return 0;
	}
	else {
		std::cerr << "No data" << std::endl;
		return -1;
	}
}
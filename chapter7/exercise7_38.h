#include<iostream>
//std::istream& read(std::istream& is, Sales_data& item);
class Sales_data {
	friend std::istream& read(std::istream& is, Sales_data& item);
public:
	Sales_data(std::istream& is = std::cin) {
		read(is, *this);
	}

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

std::istream& read(std::istream& is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}
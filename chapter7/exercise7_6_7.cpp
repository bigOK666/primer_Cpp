#include<string>
#include<iostream>
using std::string;
using std::istream;
using std::ostream;

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	std::string isbn() const { return bookNo; };
	Sales_data& combine(const Sales_data&);
};
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

istream& read(istream& is, Sales_data& item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

ostream& print(ostream& os, const Sales_data& item)
{
	os << item.isbn() << " " << item.units_sold << " " << item.revenue << " ";
	return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

int main()
{
	Sales_data total;

	if (read(std::cin, total)) {
		Sales_data trans;
		while (read(std::cin, trans)) {
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
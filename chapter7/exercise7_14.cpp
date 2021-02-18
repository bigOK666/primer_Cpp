#include<string>

struct Sales_data {


	Sales_data() = default;
	Sales_data(const std::string& s) :bookNo(s) {};
	Sales_data(const std::string& s, unsigned us, double p) : bookNo(s), units_sold(us), revenue(us* p) {};
	Sales_data() : units_sold(0), revenue(0) {};
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	std::string isbn() const { return bookNo; };
	Sales_data& combine(const Sales_data&);
};
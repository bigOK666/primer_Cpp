#include<string>

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;

	std::string isbn() const { return bookNo; };
	Sales_data& combine(const Sales_data&);
};
//返回类型为左侧对象的引用，返回类型为引用不需要在return中做什么，而是在返回类型上加入&
Sales_data& Sales_data::combine(const Sales_data& rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
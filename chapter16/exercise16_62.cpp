#include<string>
#include<unordered_set>
#include<iostream>
class Sales_data {
	friend class std::hash<Sales_data>;
	friend std::ostream& operator<<(std::ostream& os, const Sales_data& item) { std::cout << item.bookNo << " " << item.units_sold << " " << item.revenue; return os; }
	friend bool operator==(const Sales_data& item1, const Sales_data& item2) { return item1.bookNo == item2.bookNo; }
public:
	Sales_data(const std::string &s="", unsigned d=0,double r=0):bookNo(s),units_sold(d),revenue(r){}
	
private:
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};

namespace std {
	template<>
	struct hash<Sales_data>
	{
		typedef size_t result_type;
		typedef Sales_data argument_type;
		size_t operator()(const Sales_data& s) const;
	};

	size_t
	hash<Sales_data>::operator()(const Sales_data& s) const {
		return hash<string>()(s.bookNo) ^
			hash<unsigned>()(s.units_sold) ^
			hash<double>()(s.revenue);
	}
}

int main()
{
	std::unordered_multiset<Sales_data> SDset;
	SDset.insert(Sales_data("book1", 2, 20));
	SDset.insert(Sales_data("book2", 3, 23));

	for (auto i : SDset) {
		std::cout << i << std::endl;
	}
}
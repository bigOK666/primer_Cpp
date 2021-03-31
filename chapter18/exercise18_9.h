#include<stdexcept>
#include<string>
class out_of_stock :public std::runtime_error {
public:
	explicit out_of_stock(const std::string &s):
		std::runtime_error(s){}
};

class isbn_mismatch : public std::logic_error {
public:
	explicit isbn_mismatch(const std::string &s):
		std::logic_error(s){}

	isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs):
		std::logic_error(s),left(lhs),right(rhs){}
	const std::string left, right;
};

class Sales_data {
public:
	Sales_data(const std::string &s="", unsigned us=0, double r=0):bookNo(s), units_sold(us), revenue(r){}
	std::string isbn() const { return bookNo; }
	Sales_data& operator+=(const Sales_data& rhs) {
		if (isbn() != rhs.isbn())
			throw isbn_mismatch("wrong isbn", isbn(), rhs.isbn());
		units_sold += rhs.units_sold;
		revenue += rhs.revenue;

		return *this;
	}
private:
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};
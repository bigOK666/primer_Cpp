#include<string>

class Quote {
public:
	Quote() = default;
	Quote(const std::string& book, double sales_price) :
		bookNo(book), price(sales_price) {}
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const {
		return n * price;
	}

	virtual ~Quote() = default;
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Bulk_quote :public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string&, double, std::size_t, double);
	double net_price(std::size_t) const override;//override 只在声明的时候用
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

Bulk_quote::Bulk_quote(const std::string& book, double p, std::size_t n, double dis):
	Quote(book, p), min_qty(n),discount(dis) {}

double Bulk_quote::net_price(std::size_t n) const
{
	if (n > min_qty) {
		return n * price * (1 - discount);
	}
	else {
		return n * price;
	}
}
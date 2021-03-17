#include<string>
#include<iostream>
class Quote {
public:
	Quote() = default;
	Quote(const std::string& book, double sales_price) :
		bookNo(book), price(sales_price) {}
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const {
		return n * price;
	}

	virtual void debug() const {
		std::cout << "bookNo " << bookNo << " price " << price << std::endl;
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
	void debug() const override {
		std::cout << "min_qty " << min_qty << " discount " << discount << std::endl;
	}
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

Bulk_quote::Bulk_quote(const std::string& book, double p, std::size_t n, double dis) :
	Quote(book, p), min_qty(n), discount(dis) {}

double Bulk_quote::net_price(std::size_t n) const
{
	if (n > min_qty) {
		return n * price * (1 - discount);
	}
	else {
		return n * price;
	}
}

class Limit_quote :public Quote {
public:
	Limit_quote() = default;
	Limit_quote(const std::string&, double, std::size_t, double);
	double net_price(std::size_t) const override;
	void debug() const override {
		std::cout << "max_qty " << max_qty << " discount " << discount << std::endl;
	}
private:
	std::size_t max_qty = 0;
	double discount = 0.0;
};

Limit_quote::Limit_quote(const std::string& book, double p, std::size_t n, double dis) :
	Quote(book, p), max_qty(n), discount(dis) {}

double Limit_quote::net_price(std::size_t cnt) const
{
	if (cnt < max_qty) {
		return cnt * price * (1 - discount);
	}
	else {
		return cnt * price;
	}
}
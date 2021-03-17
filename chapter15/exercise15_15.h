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

class Disc_quote :public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string &book, double p, std::size_t q, double d):
		Quote(book, p), quantity(q), discount(d){}

	double net_price(std::size_t) const = 0;//纯虚函数，只在类内声明时添加=0,如果要定义函数体，虚函数体必须定义在类的外部

private:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote :public Disc_quote {
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
	Disc_quote(book,p,n,dis){}

double Bulk_quote::net_price(std::size_t n) const
{
	if (n > min_qty) {
		return n * price * (1 - discount);
	}
	else {
		return n * price;
	}
}


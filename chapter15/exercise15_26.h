#include<string>
#include<iostream>
class Quote {
	friend bool operator!=(const Quote& q1, const Quote& q2) { return q1.bookNo != q2.bookNo && q1.price != q2.price; }
public:
	Quote() = default;
	Quote(const std::string& book, double sales_price) :
		bookNo(book), price(sales_price) {}
	//copy constructor
	Quote(const Quote& q) : bookNo(q.bookNo), price(q.price) { std::cout << "Quote copy constructor" << std::endl; }
	//copy =
	Quote& operator=(const Quote &rhs) {
		bookNo = rhs.bookNo;
		price = rhs.price;
		std::cout << "Quote copy =" << std::endl;
		return *this;
	}
	//move constructor
	Quote(Quote&& q) noexcept :bookNo(std::move(q.bookNo)), price(std::move(q.price)) { std::cout << "Quote move constructor" << std::endl; }
	//move =
	Quote& operator=(Quote&& rhs) noexcept{
		if (*this != rhs) {
			bookNo = std::move(rhs.bookNo);
			price = std::move(rhs.price);

		}
		std::cout << "Quote move = " << std::endl;
		return *this;
	};
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const {
		return n * price;
	}

	virtual void debug() const {
		std::cout << "bookNo " << bookNo << " price " << price << std::endl;
	}

	virtual ~Quote() {
		std::cout << "Quote deconstructor" << std::endl;
	};
private:
	std::string bookNo;
protected:
	double price = 0.0;
};

class Disc_quote :public Quote {
	friend bool operator!=(const Disc_quote& dq1, const Disc_quote& dq2) 
	{ return Quote(dq1) != Quote(dq2) && dq1.discount != dq2.discount && dq1.quantity != dq2.quantity; }
public:
	Disc_quote() = default;
	Disc_quote(const std::string& book, double p, std::size_t q, double d) :
		Quote(book, p), quantity(q), discount(d) {}
	//copy constructor
	Disc_quote(const Disc_quote &dq) :Quote(dq), quantity(dq.quantity), discount(dq.discount) 
			{ std::cout << "Disc_quote copy constructor" << std::endl; }
	//copy =
	Disc_quote& operator=(const Disc_quote &rhs) {
		Quote::operator=(rhs);
		quantity = rhs.quantity;
		discount = rhs.discount;
		std::cout << "Disc_quote cpy =" << std::endl;

		return *this;
	};
	//move constructor
	Disc_quote(Disc_quote &&dq) noexcept:Quote(std::move(dq)), quantity(std::move(dq.quantity)), discount(std::move(dq.discount))
	{
		std::cout << "Disc_quote move constructor" << std::endl;
	}
	//move =
	Disc_quote& operator=(Disc_quote&& rhs) noexcept {
		if (*this != rhs) {
			Quote::operator=(std::move(rhs));
			quantity = std::move(rhs.quantity);
			discount = std::move(discount);
		}
		std::cout << "Disc_quote move =" << std::endl;
		return *this;
	}
	double net_price(std::size_t) const = 0;//纯虚函数，只在类内声明时添加=0,如果要定义函数体，虚函数体必须定义在类的外部
	~Disc_quote() override {
		std::cout << "Disc_quote deconstructor" << std::endl;
	}
protected:
	std::size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote :public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const std::string&, double, std::size_t, double);
	//copy constructor
	Bulk_quote(const Bulk_quote& b) :Disc_quote(b) { std::cout << "Bulk_quote copy constructor" << std::endl; }
	//copy =
	Bulk_quote& operator=(const Bulk_quote& rhs) {
		Disc_quote::operator=(rhs);
		std::cout << "Bulk_quote copy=" << std::endl;
	}
	//move constructor
	Bulk_quote(Bulk_quote&& b) noexcept:Disc_quote(std::move(b)) { std::cout << "Bulk_quote move constructor" << std::endl; }
	//move copy
	Bulk_quote& operator=(Bulk_quote&& rhs) noexcept {
		if (*this != rhs) {
			Disc_quote::operator=(std::move(rhs));
		}
		std::cout << "Bulk_quote move copy" << std::endl;
		return *this;
	}
	double net_price(std::size_t) const override;//override 只在声明的时候用
	void debug() const override {
		std::cout << "min_qty " << quantity << " discount " << discount << std::endl;
	}

	~Bulk_quote() override {
		std::cout << "Bulk_quote deconstructor" << std::endl;
	}

};

Bulk_quote::Bulk_quote(const std::string& book, double p, std::size_t n, double dis) :
	Disc_quote(book, p, n, dis) {}

double Bulk_quote::net_price(std::size_t n) const
{
	if (n > quantity) {
		return n * price * (1 - discount);
	}
	else {
		return n * price;
	}
}


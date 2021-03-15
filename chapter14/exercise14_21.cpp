#include <string>
#include <iostream>

class Sales_data {
    friend std::ostream& operator<<(std::ostream& os, const Sales_data&);
    friend std::istream& operator>>(std::istream& is, Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    friend Sales_data operator-(const Sales_data&, const Sales_data&);

public:
    Sales_data(const std::string& s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n* p) { }
    Sales_data() : Sales_data("", 0, 0.0f) { }
    Sales_data(const std::string& s) : Sales_data(s, 0, 0.0f) { }
    Sales_data(std::istream& is);
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator-=(const Sales_data&);

    std::string isbn() const { return bookNo; }

private:
    inline double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream& operator>>(std::istream& is, Sales_data& s)
{
    double price;
    is >> s.bookNo >> s.units_sold >> price;
    s.revenue += price * s.units_sold;

    return is;
}
std::ostream& operator<<(std::ostream& os, const Sales_data& s)
{
    std::cout << s.bookNo << " " << s.units_sold << " " << s.revenue;
    return os;
}
Sales_data operator+(const Sales_data& s1, const Sales_data& s2)
{
    if (s1.bookNo != s2.bookNo) {
        std::cout << "Not the same book" << std::endl;
        return Sales_data();
    }
    else {
        Sales_data s3;
        s3.bookNo = s1.bookNo;
        s3.units_sold = s1.units_sold + s2.units_sold;
        s3.revenue = s1.revenue + s2.revenue;
        return s3;
    }


};

Sales_data& Sales_data::operator+=(const Sales_data& s1)
{
    if (s1.bookNo != bookNo) {
        std::cout << "Not the same book" << std::endl;

    }
    else {
        *this = *this + s1;

    }

    return *this;
};
Sales_data& Sales_data::operator-=(const Sales_data& s1)
{
    if (bookNo != s1.bookNo) {
        std::cout << "Not the same book" << std::endl;

    }
    else {
        units_sold = units_sold - s1.units_sold;
        revenue = revenue - s1.revenue;
    }
    return *this;
}
Sales_data operator-(const Sales_data& s1, const Sales_data& s2)
{
    Sales_data book(s1);
    book -= s2;
    return book;

}

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue / units_sold : 0;
}

int main()
{
    Sales_data item("book1", 2, 10);
    Sales_data item2("book1", 1, 10);
    item += item2;

    std::cout << item;
}
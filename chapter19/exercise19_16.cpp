#include<string>

class Sales_data {
	
public:
	Sales_data() = default;
	double avg_price() const { return revenue / units_sold; }
private:
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};

using avg_ptr = double (Sales_data::*) () const ;
#include<string>
#include<functional>
#include<algorithm>
#include<vector>

class Sales_data {

public:
	Sales_data() = default;
	double avg_price() const { return revenue / units_sold; }
private:
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};

Sales_data& find_above(std::vector<Sales_data> v_s, double threshold)
{
	auto fn = std::mem_fn(&Sales_data::avg_price);
	auto ptr = std::find_if(v_s.begin(), v_s.end(), [threshold, fn](Sales_data& sd) {return fn(sd) > threshold; });
	return *ptr;
}
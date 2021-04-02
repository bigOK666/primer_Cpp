#include<string>

class Sales_data {
	friend struct bookNoPtr;
public:
	Sales_data() = default;

private:
	std::string bookNo;
};

struct bookNoPtr
{
	const std::string Sales_data::* ptr = &Sales_data::bookNo;
};
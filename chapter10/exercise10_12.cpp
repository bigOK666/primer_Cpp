#include<string>
#include<algorithm>
#include<vector>
#include<iostream>

class Sales_data {
	friend std::istream& read(std::istream&, Sales_data&);
public:
	Sales_data() = default;
	Sales_data(const std::string& s) :bookNo(s) {}
	std::string isbn() const { return bookNo; }

private:
	std::string bookNo;

};

std::istream& read(std::istream& is, Sales_data& sd) {
	is >> sd.bookNo;
	return is;
}
bool compareIsbn(const Sales_data& s1, const Sales_data& s2)
{
	return s1.isbn() < s2.isbn();
}

int main()
{
	std::vector<Sales_data> v_s;
	Sales_data temp;
	while (read(std::cin, temp)) {
		v_s.push_back(temp);
	}

	stable_sort(v_s.begin(), v_s.end(), compareIsbn);

	for (auto i : v_s) {
		std::cout << i.isbn() << std::endl;
	}

}
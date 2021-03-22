#include<tuple>
#include<vector>
#include<string>
#include<algorithm>
class Sales_data {
	friend bool compareIsbn(const Sales_data&, const Sales_data&);
public:
	Sales_data(const std::string& s = "", unsigned us = 0, double r = 0) :bookNo(s), units_sold(us), revenue(r) {}
private:
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};

bool compareIsbn(const Sales_data& s1, const Sales_data& s2) {
	return s1.bookNo == s2.bookNo;
}

using namespace std;



//typedef tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator> matches;
typedef pair<vector<Sales_data>::size_type, pair<vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>> pair_matches;

struct struc_matches
{
	vector<Sales_data>::size_type i;
	vector<Sales_data>::const_iterator beg;
	vector<Sales_data>::const_iterator ed;
};

vector<struc_matches> findBook(const vector<vector<Sales_data>>& files, const string& book) {
	vector<struc_matches> ret;
	for (auto it = files.cbegin(); it != files.cend(); ++it) {
		auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
		if (found.first != found.second) {
			ret.push_back(struc_matches{ it - files.cbegin(), found.first, found.second });
		}
	}
	return ret;
}
int main()
{

}
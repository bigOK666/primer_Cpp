#include"exercise15_27.h"
#include<memory>
#include<vector>
using namespace std;

int main()
{
	vector<shared_ptr<Quote>> v_q;

	v_q.push_back(make_shared<Bulk_quote>("Book1", 10, 5, 0.2));
	v_q.push_back(make_shared<Bulk_quote>("Book2", 10, 5, 0.2));
	v_q.push_back(make_shared<Bulk_quote>("Book3", 10, 5, 0.2));
	v_q.push_back(make_shared<Bulk_quote>("Book3", 10, 5, 0.2));
	v_q.push_back(make_shared<Bulk_quote>("Book4", 10, 5, 0.2));
	v_q.push_back(make_shared<Bulk_quote>("Book5", 10, 5, 0.2));
	int sum = 0;
	for (auto const b_p : v_q) {
		sum += b_p->net_price(6);
	}

	std::cout << sum;

}
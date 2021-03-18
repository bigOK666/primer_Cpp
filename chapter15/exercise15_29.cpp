#include"exercise15_27.h"
#include<memory>
#include<vector>
using namespace std;

int main()
{
	vector<shared_ptr<Quote>> v_q;

	v_q.push_back(make_shared<Quote>("Book1", 10));
	v_q.push_back(make_shared<Quote>("Book2", 10));
	v_q.push_back(make_shared<Quote>("Book3", 10));
	v_q.push_back(make_shared<Quote>("Book3", 10));
	v_q.push_back(make_shared<Quote>("Book4", 10));
	v_q.push_back(make_shared<Quote>("Book5", 10));
	int sum = 0;
	for (auto const b_p : v_q) {
		sum += b_p->net_price(6);
	}

	std::cout << sum;

}
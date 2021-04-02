#include <iostream>
#include <typeinfo>

using namespace std;

class Query_base {
public:
	Query_base() { }
	virtual ~Query_base() { }
};

class BinaryQuery : public Query_base {
public:
	BinaryQuery() { }
	virtual ~BinaryQuery() { }
};

class AndQuery : public BinaryQuery {
public:
	AndQuery() { }
	virtual ~AndQuery() { }
};

int main()
{
	Query_base *qbp = new Query_base;
	Query_base* qbp2 = new AndQuery;
	Query_base qb;
	Query_base* qbp3 = &qb;

	if (typeid(*qbp) == typeid(*qbp2)) {
		cout << "Dynamic type should not be the same" << endl;
	}
	else if (typeid(*qbp) == typeid(*qbp3)) {
		cout << "same type" << endl;
	}
	


}
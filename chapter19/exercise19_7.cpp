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
	Query_base &qbp = AndQuery();

	try {
		AndQuery& aqp = dynamic_cast<AndQuery&> (qbp);
	}
	catch (bad_cast& bc) {
		cout << "Failed" << endl;
	}
	

}
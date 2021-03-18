#include"exercise15_35_TextQuery.h"

class Query_base {
	friend class Query;
protected:
	using lin_no = std::vector<std::string>::size_type;
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const = 0 { std::cout << "Query_base rep()" << std::endl; }
};

class Query {
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);

public:
	Query(const std::string&);
	QueryResult eval(const TextQuery& t) const { return q->eval(t); }
	std::string rep() const { return q->rep(); std::cout << "Query rep()" << std::endl;}

private:
	Query(std::shared_ptr<Query_base> query) :q(query) {}
	std::shared_ptr<Query_base> q;
};

std::ostream& operator<<(std::ostream& os, const Query& query) {
	return os << query.rep();
}

class WordQuery :public Query_base {
	friend class Query;
	WordQuery(const std::string& s) :query_word(s) { std::cout << "WordQuery constructor" << std::endl; }

	QueryResult eval(const TextQuery& t) const { return t.query(query_word); }
	std::string rep() const { return query_word; std::cout << "WordQuery rep()" << std::endl;}
	std::string query_word;
};
//now we can implement Query constructor
inline Query::Query(const std::string& s) :q(new WordQuery(s)) { std::cout << "Query constructur" << std::endl; }

class NotQuery :public Query_base {
	friend Query operator~(const Query&);
	NotQuery(const Query& q) :query(q) { std::cout << "NotQuery constructor" << std::endl; }

	std::string rep() const { return "~(" + query.rep() + ")"; std::cout << "NotQuery rep()" << std::endl;
	}
	QueryResult eval(const TextQuery&) const { return QueryResult(); };
	Query query;
};

inline Query operator~(const Query& operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery :public Query_base {
protected:
	BinaryQuery(const Query& l, const Query& r, std::string s) :
		lhs(l), rhs(r), opSym(s) {
		std::cout << "BinaryQuery constructor" << std::endl;
	}
	std::string rep() const { return"(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; std::cout << "BinaryQuery rep()" << std::endl;
	}
	Query lhs, rhs;
	std::string opSym;
};

class AndQuery : public BinaryQuery {
	friend Query operator &(const Query&, const Query&);
	AndQuery(const Query& left, const Query& right) :
		BinaryQuery(left, right, "&") {
		std::cout << "AndQuery constructor" << std::endl;
	}
	QueryResult eval(const TextQuery&) const { return QueryResult(); };

};
inline Query operator&(const Query& lhs, const Query& rhs) {
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query& left, const Query& right) :
		BinaryQuery(left, right, "|") {
		std::cout << "OrQuery constructor" << std::endl;
	}
	QueryResult eval(const TextQuery&) const { return QueryResult(); };
};

inline Query operator|(const Query& lhs, const Query& rhs) {
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}


int main()
{
	Query q = Query("fiery") & Query("bird") | Query("wind");
}
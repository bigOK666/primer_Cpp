#include<string>
class Sales_data {

public:
	Sales_data() = default;
	double avg_price() const { return revenue / units_sold; }
	~Sales_data() = default;
private:
	std::string bookNo;
	unsigned units_sold;
	double revenue;
};
class Token {
public:
	Token() :tok(INT), ival(0) {}
	Token(const Token& t) :tok(t.tok) { copyUnion(t); }
	Token(Token&& t) :tok(std::move(t.tok)) { copyUnion(t); }
	Token& operator=(const Token&);
	Token& operator=(Token&&);
	~Token() { if (tok == STR) { sval.std::string::~string(); } else if (tok == SD) { sdval.~Sales_data(); } }
	Token& operator=(const std::string&);
	Token& operator=(char);
	Token& operator=(int);
	Token& operator=(double);
	Token& operator=(const Sales_data&);
private:
	enum { INT, CHAR, DBL, STR, SD } tok;
	union {
		char cval;
		int ival;
		double dval;
		std::string sval;
		Sales_data sdval;
	};
	void copyUnion(const Token&);
};

Token& Token::operator=(int i)
{
	if (tok == SD) sdval.~Sales_data();
	if (tok == STR) sval.std::string::~string();
	ival = i;
	tok = INT;
	return *this;
}

Token& Token::operator=(char c)
{
	if (tok == SD) sdval.~Sales_data();
	if (tok == STR) sval.std::string::~string();
	cval = c;
	tok = CHAR;
	return *this;

}

Token& Token::operator=(double d)
{
	if (tok == SD) sdval.~Sales_data();
	if (tok == STR) sval.std::string::~string();
	dval = d;
	tok = DBL;
	return *this;
}

Token& Token::operator=(const std::string& s)
{
	if (tok == SD) sdval.~Sales_data();
	if (tok == STR)
		sval = s;
	else
		new(&sval) std::string(s);
	tok = STR;
	return *this;
}

Token& Token::operator=(const Sales_data& sd)
{
	if (tok == STR) sval.std::string::~string();
	if (tok == SD)
		sdval = sd;
	else
		new(&sdval) Sales_data(sd);

	tok = SD;
	return *this;


}

void Token::copyUnion(const Token& t)
{
	switch (t.tok) {
	case Token::INT: ival = t.ival; break;
	case Token::CHAR: cval = t.cval; break;
	case Token::DBL: dval = t.dval; break;
	case Token::STR: new(&sval) std::string(t.sval); break;
	case Token::SD: new(&sdval) Sales_data(t.sdval); break;
	}
}

Token& Token::operator=(const Token& t)
{
	if (this != &t) {
		if (tok == STR && t.tok != STR) sval.std::string::~string();
		if (tok == SD && t.tok != SD) sdval.~Sales_data();
		if (tok == SD && t.tok == SD) sdval = t.sdval;
		if (tok == STR && t.tok == STR)
			sval = t.sval;
		else
			copyUnion(t);
		tok = t.tok;
		
	}
	return *this;

}

Token& Token::operator=(Token&& t)
{
	if (this != &t) {
		this->~Token();
		copyUnion(t);
		tok = std::move(t.tok);
	}

	return *this;
}

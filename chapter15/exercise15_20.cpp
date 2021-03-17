class Base {
public:
	void pub_mem();
protected:
	int prot_mem;
private:
	char priv_mem;
};

struct Pub_Derv:public Base
{
public:
	void memfcn(Base& b) { b = *this; }
};

struct  Priv_Derv:private Base
{
public:
	void memfcn(Base& b) { b = *this; }
};
struct Prot_Derv:protected Base
{
public:
	void memfcn(Base& b) { b = *this; }
};

struct Derived_from_Public: Pub_Derv
{
public:
	void memfcn(Base& b) { b = *this; }
};

struct Derived_from_Private: Priv_Derv
{
public:
	void memfcn(Base& b) { b = *this; }//wrong
};

struct Derived_from_Protected:Prot_Derv
{
public:
	void memfcn(Base& b) { b = *this; }
};

int main()
{
	Pub_Derv d1;
	Priv_Derv d2;
	Prot_Derv d3;
	Derived_from_Public dd1;
	Derived_from_Protected dd3;
	Derived_from_Private dd2;
	Base* p = &d1;
	p = &d2;//wrong
	p = &d3;//wrong
	p = &dd1;
	p = &dd2;//wrong
	p = &dd3;//wrong

}
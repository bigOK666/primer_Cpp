class Class{};
class Base :public Class {
public:
	Base(int i) :bi(i) {}
	Base() :Base(0) {}
	Base(const Base &b):bi(b.bi){}
	
private:
	int bi;
};

class D1 :virtual public Base {
public:
	D1(int i):Base(i){}
	D1() :D1(0) {}
	D1(const D1 &d1):Base(d1){}
};

class D2 : virtual public Base {
public:
	D2(int i):Base(i){}
	D2():D2(0){}
	D2(const D2& d2):Base(d2) {}
};

class MI : public D1, public D2 {
public:
	MI(int i):Base(i),D1(i),D2(i){}
	MI():Base(0),D1(0),D2(0){}
	MI(const MI &mi):Base(mi),D1(mi),D2(mi){}

};
class Final :public MI, public Class {
public:
	Final(int i):Base(i),MI(i){}
	Final() :Base(0), MI(0) {}
	Final(const Final &f):Base(f),MI(f){}
};
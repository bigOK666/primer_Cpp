#include<iostream>

class NoDefault {
public:
	NoDefault(int i) :member(i) { std::cout << "NoDefault constructor" << std::endl; }
private:
	int member = 0;
};

class C {
public:
	C(int i) :noC(i) { std::cout << "C constructor i" << std::endl; }
	C() :C(0) { std::cout << "C default constructor i" << std::endl; }
	//以上等价于C():noC(i){}
private:
	NoDefault noC;
};
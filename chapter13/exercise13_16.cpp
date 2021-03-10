#include<iostream>

class numbered {
public:
	numbered() { ++mysn; }
	numbered(const numbered& n) :mysn(n.mysn + 1) {}
	int mysn = 0;
};

void f(const numbered &s) { std::cout << s.mysn << std::endl; }

int main()
{
	numbered a, b = a, c = b;
	f(a); f(b); f(c);
}
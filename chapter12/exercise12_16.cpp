#include<memory>

using namespace std;

int main()
{
	unique_ptr<int> p(new int(3));
	unique_ptr<int> p2(p);
	unique_ptr<int> p3;
	p3 = p;
}
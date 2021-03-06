#include<memory>

struct connection;
struct destination;

connection connect(destination*);
void disconnect(connection);

void end_connection(connection* p) { disconnect(*p); }

void f(destination& d)
{
	connection c = connect(&d);
	//将智能指针绑在c上，这样即使后面异常退出， c占用的内存也会被释放
	std::shared_ptr<connection> p(&c, [](connection* p) {disconnect(*p); });
}
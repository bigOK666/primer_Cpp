#include<memory>

struct connection;
struct destination;

connection connect(destination*);
void disconnect(connection);

void end_connection(connection* p) { disconnect(*p); }

void f(destination& d)
{
	connection c = connect(&d);
	//������ָ�����c�ϣ�������ʹ�����쳣�˳��� cռ�õ��ڴ�Ҳ�ᱻ�ͷ�
	std::shared_ptr<connection> p(&c, [](connection* p) {disconnect(*p); });
}
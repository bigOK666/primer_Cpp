#include<string>
//����������ʽҲ�Ƚϼ��
std::string (&foo(int i))[10];
//����������ʽ�Ƚϼ��
using sArry = std::string [10];

sArry &fooSArry(int i);
//����������ʽ�պ�
auto fooTr(int i)->std::string(&)[10];
//����������ʽ���ã���Ϊ��Ҫ�ȶ���һ��ͬ���͵ı���
std::string sA[10];

decltype(sA) &fooDec(int i);
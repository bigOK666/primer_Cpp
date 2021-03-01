#include<string>
#include<stack>
#include<iostream>
using namespace std;

int priority(char operat)
{
	int p = 0;
	if (operat=='(' )
		return p = 1;
	if (operat == '+'  || operat =='-')
		return p = 2;
	if (operat == '*' || operat == '/')
		return p = 3;
	return p;
}

void calculate(stack<double>& operands, char& operat) {
	if (operat == '+')
	{
		double a = operands.top();	//ȡջ��Ԫ��a
		operands.pop();			//����a
		double b = operands.top();	//ȡջ��Ԫ��b
		operands.pop();			//����b
		operands.push(a + b);		//ѹ��a+b��ֵ
	}
	if (operat == '-')
	{
		double a = operands.top();	//ȡջ��Ԫ��a
		operands.pop();			//����a
		double b = operands.top();	//ȡջ��Ԫ��b
		operands.pop();			//����b
		operands.push(b - a);	//ѹ��b-a��ֵ
	}
	if (operat == '*')
	{
		double a = operands.top();	//ȡջ��Ԫ��a
		operands.pop();			//����a
		double b = operands.top();	//ȡջ��Ԫ��b
		operands.pop();			//����b
		operands.push(a * b);	//ѹ��a*b��ֵ
	}
	if (operat == '/')
	{
		double a = operands.top();	//ȡջ��Ԫ��a
		operands.pop();			//����a
		double b = operands.top();	//ȡջ��Ԫ��b
		operands.pop();			//����b
		operands.push(b / a);	//ѹ��b/a��ֵ
	}
	
}

int main()
{
	stack<char> optStack;
	stack<double> opdStack;

	string expression{ "3+7*(5-6/2+(3+8)*2)-2" };
	//string expression{ "3+7" };
	auto iter = expression.begin();
	cout << expression << endl;
	while (iter != expression.end()) {
		//�ȿ��ǲ���������������������������Ҫ���м���
		if (((*iter) == '+')||((*iter) =='-')||((*iter) =='*')||((*iter)=='/')) {
			if (optStack.size() == 0) {
				optStack.push(*iter);
			}
			else {
				//�鿴Ŀǰ�����������ȼ�
				int currPrio = priority(*iter);
				//�鿴ǰһ�������������ȼ�
				char optTop = optStack.top();
				int prePrio = priority(optTop);
				if (currPrio > prePrio) {//��ǰ�����ȼ���
					optStack.push(*iter);
				}
				else {
					while (currPrio <= prePrio) {//ǰһ�����������ȼ��ߣ���Ҫ����ǰһ��������
						optStack.pop();
						calculate(opdStack, optTop);//����ǰһ������������������������
						if (optStack.size() > 0) {//��ǰһ��������֮ǰ���в����������¶������������Ӧ�����ȼ�ֵ
							optTop = optStack.top();
							prePrio = priority(optTop);
						}
						else {
							break;
						}
					}
					optStack.push(*iter);
				}
			}
			
		}
		else if ((*iter) =='(') {//������ֱ�ӽ�������ջ��������ʶ���ŵķ�Χ
			optStack.push(*iter);
		}
		else if ((*iter) == ')') {//�����ű�־������������ڵļ��㣬ƥ������������ţ������ѹ��ջ��������
			while (optStack.top() != '(') {
				char optTop = optStack.top();
				calculate(opdStack, optTop);
				optStack.pop();
			}
			optStack.pop();//����������
		}
		else {//����������ǲ������ˣ���������ֱ��ѹ�������ջ
			cout << string(1,*iter) << endl;
			opdStack.push(stod(string(1, *iter)));
		}
		++iter;
	}
	
	//���������ź����ȼ�����������е����������ƽ���ģ�����ʣ�����е�����
	while (optStack.size() != 0) {
		char optTop = optStack.top();
		calculate(opdStack, optTop);
		optStack.pop();
	}

	//���ʣ��ֵ���Ǽ�����
	
	cout << opdStack.top()<<" "<<opdStack.size();

}
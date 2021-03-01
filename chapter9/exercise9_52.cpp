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
		double a = operands.top();	//取栈顶元素a
		operands.pop();			//弹出a
		double b = operands.top();	//取栈顶元素b
		operands.pop();			//弹出b
		operands.push(a + b);		//压入a+b的值
	}
	if (operat == '-')
	{
		double a = operands.top();	//取栈顶元素a
		operands.pop();			//弹出a
		double b = operands.top();	//取栈顶元素b
		operands.pop();			//弹出b
		operands.push(b - a);	//压入b-a的值
	}
	if (operat == '*')
	{
		double a = operands.top();	//取栈顶元素a
		operands.pop();			//弹出a
		double b = operands.top();	//取栈顶元素b
		operands.pop();			//弹出b
		operands.push(a * b);	//压入a*b的值
	}
	if (operat == '/')
	{
		double a = operands.top();	//取栈顶元素a
		operands.pop();			//弹出a
		double b = operands.top();	//取栈顶元素b
		operands.pop();			//弹出b
		operands.push(b / a);	//压入b/a的值
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
		//先看是不是运算符，如果是运算符则可能需要进行计算
		if (((*iter) == '+')||((*iter) =='-')||((*iter) =='*')||((*iter)=='/')) {
			if (optStack.size() == 0) {
				optStack.push(*iter);
			}
			else {
				//查看目前操作符的优先级
				int currPrio = priority(*iter);
				//查看前一个操作符的优先级
				char optTop = optStack.top();
				int prePrio = priority(optTop);
				if (currPrio > prePrio) {//当前的优先级高
					optStack.push(*iter);
				}
				else {
					while (currPrio <= prePrio) {//前一个操作符优先级高，需要先算前一个操作符
						optStack.pop();
						calculate(opdStack, optTop);//计算前一个操作符关联的两个操作数
						if (optStack.size() > 0) {//当前一个操作符之前还有操作符，更新顶层操作符及对应的优先级值
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
		else if ((*iter) =='(') {//左括号直接进操作符栈，用来标识括号的范围
			optStack.push(*iter);
		}
		else if ((*iter) == ')') {//右括号标志可以完成括号内的计算，匹配最近的左括号，即最近压入栈的左括号
			while (optStack.top() != '(') {
				char optTop = optStack.top();
				calculate(opdStack, optTop);
				optStack.pop();
			}
			optStack.pop();//弹出左括号
		}
		else {//其他情况就是操作数了，将操作数直接压入操作数栈
			cout << string(1,*iter) << endl;
			opdStack.push(stod(string(1, *iter)));
		}
		++iter;
	}
	
	//处理完括号和优先级运算符后，所有的运算符都是平级的，处理剩下所有的运算
	while (optStack.size() != 0) {
		char optTop = optStack.top();
		calculate(opdStack, optTop);
		optStack.pop();
	}

	//最后剩的值就是计算结果
	
	cout << opdStack.top()<<" "<<opdStack.size();

}
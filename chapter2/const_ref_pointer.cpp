int main()
{
	int i = 22;
	//指向常量的引用，简称常量引用
	//常量引用可以绑定在任意对象
	const int& r1 = i;
	const int& r2 = 42;
	const int& r3 = r1 * 2;
	//普通引用不能绑在常量上，r1是常量，绑定r1的引用得是常量才行。
	int& r4 = r1 * 2;



	return 0;
}
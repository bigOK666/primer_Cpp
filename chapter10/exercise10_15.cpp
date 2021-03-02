int main()
{
	int a = 12;
	auto l = [a](int b) {return a + b; };
}
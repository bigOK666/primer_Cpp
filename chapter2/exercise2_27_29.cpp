int main()
{
	int i = -1, & r = 0;//非法
	int* const p2 = &i2;//合法
	const int i = -1, & r = 0;//非法
	const int* const p3 = &i2;//legal
	const int* p1 = &i2;//legal
	const int& const r2;//ilegal
	const int i2 = i, & r = i;//legal

	const int* p;//ilegal

}
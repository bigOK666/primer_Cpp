int odd[] = { 1,3,5,7,9 };
int even[] = { 2,4,6,8,0 };

auto arrRef(int i)->int(&)[5]
{
	return (i % 2) ? odd : even;
}
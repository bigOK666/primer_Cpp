#include<utility>
#include<iostream>
void f(int v1, int& v2) {
	std::cout << v1 << " " << ++v2 << std::endl;
}

template <typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2) {
	f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main()
{
	int i = 20;
	//flip(f,3, 1);//会报错
	flip(f, i, 3);

	std::cout << i << std::endl;
	//flip(f, 3, i);//会报错
}
#include<string>
#include<memory>
#include<iostream>
int main()
{
	int n(2);
	std::allocator<std::string> s_m;

	auto const p = s_m.allocate(n);

	std::string s;
	auto q = p;
	while (std::cin >> s && q != p + n) {
		s_m.construct(q++, s);

	}
	const size_t size = q - p;

	while (q != p) {
		s_m.destroy(--q);
	}

	s_m.deallocate(p, n);
}
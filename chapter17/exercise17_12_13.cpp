#include<bitset>
#include<string>
#include<iostream>
template<std::size_t N>
class Exercise {
public:
	Exercise() = default;
	Exercise(const std::string& s) :b(s) {}
	void change(unsigned i, bool answer) { b.set(i, answer); }
	std::size_t examine(const Exercise<N>& answers) { auto result = b ^ answers.b; result.flip(); return result.count(); }
private:
	std::bitset<N> b;
};



int main() {
	Exercise<10> e1("1100110");
	Exercise<100> e2;
	Exercise<10> ans("1100110");

	std::cout<<e1.examine(ans);

	e1.change(0, true);

	std::cout << e1.examine(ans);

}
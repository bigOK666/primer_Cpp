#include<bitset>
#include<string>
template<std::size_t N>
class Exercise {
public:
	Exercise() = default;
	Exercise(const std::string &s):b(s){}
private:
	std::bitset<N> b;
};

int main() {
	Exercise<10> e1("1100110");
	Exercise<100> e2;
}
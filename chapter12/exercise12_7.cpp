#include<vector>
#include<iostream>
#include<iterator>
#include<memory>
std::shared_ptr<std::vector<int>> dynamicVector()
{
	return std::make_shared<std::vector<int>>();
}

void save(std::istream& is, std::shared_ptr<std::vector<int>> v_iter)
{
	int i;
	while (is >> i) {
		v_iter->push_back(i);
	}



}

void printOut(std::shared_ptr<std::vector<int>> v_iter)
{
	std::ostream_iterator<int> out(std::cout);
	copy(v_iter->cbegin(), v_iter->cend(), out);

	

	

}

int main()
{
	std::shared_ptr<std::vector<int>> ptr = dynamicVector();

	save(std::cin, ptr);

	printOut(ptr);



}
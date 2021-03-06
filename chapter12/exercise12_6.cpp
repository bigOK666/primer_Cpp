#include<vector>
#include<iostream>
#include<iterator>
std::vector<int>* dynamicVector() 
{
	return new std::vector<int>();
}

void save(std::istream& is, std::vector<int>* v_iter) 
{
	int i;
	while (is >> i) {
		v_iter->push_back(i);
	}

	
	
}

void printOut(std::vector<int>* v_iter)
{
	std::ostream_iterator<int> out(std::cout);
	copy(v_iter->cbegin(), v_iter->cend(), out);

	delete v_iter;

	v_iter = nullptr;

}

int main()
{
	std::vector<int> *ptr = dynamicVector();

	save(std::cin, ptr);

	printOut(ptr);



}
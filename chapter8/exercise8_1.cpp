#include<iostream>

std::istream& read(std::istream& is)
{
	std::string temp;
	while (is>>temp) {
		
		std::cout << temp << std::endl;
	}
	is.clear();

	return is;
}

int main()
{
	read(std::cin);
}
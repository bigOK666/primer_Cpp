#include<iostream>
#include<sstream>
void read(std::istringstream& is)
{
	std::string temp;
	while (is >> temp) {

		std::cout << temp << std::endl;
	}
	

	
}

int main()
{
	std::string test("this is a test");
	std::istringstream manyInputs(test);
	read(manyInputs);
}
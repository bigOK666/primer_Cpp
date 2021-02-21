#include"exercise8_6.h"
#include<fstream>
int main(int argc, char** argv)
{
	std::ifstream infile(argv[1]);
	Sales_data total;
	if (read(infile, total)) {
		Sales_data trans;
		while (read(infile, trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				print(std::cout, total) << std::endl;
				total = trans;

			}
		}
		print(std::cout, total) << std::endl;
	}
	else {
		std::cerr << "No data" << std::endl;
	}
}
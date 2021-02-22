#include"exercise8_6.h"
#include<fstream>
int main(int argc, char** argv)
{
	std::ifstream infile(argv[1]);
	std::ofstream outfile;
	Sales_data total;
	if (read(infile, total)) {
		Sales_data trans;
		while (read(infile, trans)) {
			if (total.isbn() == trans.isbn()) {
				total.combine(trans);
			}
			else {
				outfile.open(argv[2], std::ofstream::app);
				print(outfile, total) << std::endl;
				total = trans;
				outfile.close();

			}
		}
		outfile.open(argv[2], std::ofstream::app);
		print(outfile, total) << std::endl;
		outfile.close();
	}
	else {
		std::cerr << "No data" << std::endl;
	}
}

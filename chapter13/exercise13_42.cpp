#include"exercise13_42.h"


void runQueries(std::ifstream& infile)
{
	TextQuery tq(infile);

	while (true) {
		std::cout << "Enter word to look for, or q to quit" << std::endl;;

		std::string s;
		if (!(std::cin >> s) || s == "q") { break; }

		print(std::cout, tq.query(s)) << std::endl;;
	}

}

int main(int argc, char** argv)
{
	std::ifstream in(argv[1]);

	runQueries(in);

}
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
int main(int argc, char **argv)
{
	std::vector<std::string> lines;
	std::ifstream infile;
	infile.open(argv[1], std::ifstream::in);
	std::string line;

	while (getline(infile, line)) {
		lines.push_back(line);
	}

	for (auto &l : lines) {
		std::istringstream words(l);
		std::string word;
		while (words >> word) {
			std::cout << word<<std::endl;
		}
	}
}
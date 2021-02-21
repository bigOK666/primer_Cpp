//#include<iostream>
#include<fstream>
#include<string>
#include<vector>

std::vector<std::string> readLine(const std::string& fileName) {
	std::ifstream ifs(fileName);
	std::vector<std::string> lines;
	if (ifs) {
		
		std::string line;
		while (std::getline(ifs, line)) {
			lines.push_back(line);
		}
	}

	return lines;
}

int main(int argc,char **argv) {
	std::vector<std::string> test;
	test = readLine(argv[1]);
	
}
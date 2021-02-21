#include<fstream>
#include<string>
#include<vector>

std::vector<std::string> readLine(const std::string& fileName) {
	std::ifstream ifs(fileName);
	std::vector<std::string> words;
	if (ifs) {

		std::string word;
		while (ifs>>word) {
			words.push_back(word);
		}
	}

	return words;
}

int main(int argc, char** argv) {
	std::vector<std::string> test;
	test = readLine(argv[1]);

}
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<fstream>
struct PersonInfo {
	std::string name;
	std::vector < std::string > phones;

};

bool valid(const std::string& phoneNr) {
	for (const auto& c : phoneNr) {
		if (!std::isdigit(c)) {
			return false;
		}
	}
	return true;
}

std::string format(const std::string& oldNr) {
	return oldNr.substr(0, 3) + "-" + oldNr.substr(3, 3) + "-" + oldNr.substr(6);
}

int main(int argc, char **argv)
{
	std::string line, word;
	std::vector<PersonInfo> people;
	std::istringstream record(line);
	std::ifstream infile(argv[1]);
	while (getline(infile, line)) {
		PersonInfo info;
		//¸üÐÂrecord
		record.clear();
		record.str(line);
		record >> info.name;
		std::cout << info.name << std::endl;
		while (record >> word) {
			info.phones.push_back(word);
		}
		people.push_back(info);
	}

	for (const auto &entry : people) {
		std::ostringstream formatted, badNums;
		for (const auto& nums : entry.phones) {
			if (!valid(nums)) {
				badNums << " " << nums;

			}
			else {
				formatted << " " << format(nums);
			}
		}
		if (badNums.str().empty())
			std::cout << entry.name << " " << formatted.str() << std::endl;
		else
			std::cerr << "input error: " << entry.name << " invalid number" << badNums.str() << std::endl;
	}
}
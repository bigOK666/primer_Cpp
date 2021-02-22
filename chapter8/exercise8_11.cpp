#include<iostream>
#include<vector>
#include<sstream>

struct PersonInfo {
	std::string name;
	std::vector < std::string > phones;

};

int main()
{
	std::string line, word;
	std::vector<PersonInfo> people;
	std::istringstream record(line);
	
	while (getline(std::cin, line)) {
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

	for (auto person : people) {
		std::cout << person.name << std::endl;
	}
}
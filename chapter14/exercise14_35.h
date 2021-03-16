#include<string>
#include<iostream>

class getString {
public:
	getString(std::istream& in = std::cin) :input(in) {}
	std::string operator()() {
		std::string s;
		std::getline(input, s);
		return input ? s : std::string();
	}

private:
	//std::string s;
	std::istream& input;
};
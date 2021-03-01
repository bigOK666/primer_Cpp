#include<string>
#include<iostream>
class date {
public:
	date() = default;
	date(const std::string&);
	void display() { std::cout << "Today is " << year << " " << month << " " << day << std::endl; }
private:
	unsigned year,month,day;

	void convert1(const std::string&);
	void convert2(const std::string&);
	void convert3(const std::string&);
	void convertMonth(const std::string&);

};

date::date(const std::string& s) {
	if (s.find("/") != std::string::npos) {
		convert1(s);
	}
	else if (s.find(",") != std::string::npos) {
		convert2(s);
	}
	else {
		convert3(s);
	}
}

void date::convert1(const std::string& s)
{
	year = stoi(s.substr(s.find_last_of("/")+1, s.size()-s.find_last_of("/")-1));
	day = stoi(s.substr(0, s.find_first_of("/")));
	month = stoi(s.substr(s.find_first_of("/") + 1, s.find_last_of("/") - s.find_first_of("/") - 1));
}

void date::convert2(const std::string& s)
{
	std::string numbers{ "0123456789" };
	year = stoi(s.substr(s.find_last_of(",") + 2, s.size() - s.find_last_of(",") - 2));
	day = stoi(s.substr(s.find_first_of(numbers), s.find_first_of(",") - s.find_first_of(numbers)));
	convertMonth(s);
}

void date::convert3(const std::string& s)
{
	std::string numbers{ "0123456789" };
	year = stoi(s.substr(s.find_last_of(" ") + 1, s.size() - s.find_last_of(" ") - 1));
	day = stoi(s.substr(s.find_first_of(" ") + 1, s.find_last_of(" ") - s.find_first_of(" ") - 1));
	convertMonth(s);

}

void date::convertMonth(const std::string& s)
{
	if (s.find("Jan") !=std::string::npos) month = 1;
	if (s.find("Feb") != std::string::npos) month = 2;
	if (s.find("Mar") != std::string::npos) month = 3;
	if (s.find("Apr") != std::string::npos) month = 4;
	if (s.find("May") != std::string::npos) month = 5;
	if (s.find("Jun") != std::string::npos) month = 6;
	if (s.find("Jul") != std::string::npos) month = 7;
	if (s.find("Aug") != std::string::npos) month = 8;
	if (s.find("Sep") != std::string::npos) month = 9;
	if (s.find("Oct") != std::string::npos) month = 10;
	if (s.find("Nov") != std::string::npos) month = 11;
	if (s.find("Dec") != std::string::npos) month = 12;
}
#include<string>
#include<iostream>
void findAndReplace(std::string& s, const std::string& oldVal, const std::string& newVal)
{
	auto iter = s.begin();
	auto n_o= oldVal.size();
	auto n_n = newVal.size();
	std::string temp(iter, iter +n_o);
	
	std::cout << temp << std::endl;
	while (iter != s.end()) {
		std::cout << temp << std::endl;
		
		if (temp == oldVal) {
			std::cout << "target is found!" << std::endl;
			s.erase(iter, iter + n_o);
			std::cout << s << std::endl;
			s.insert(iter, newVal.cbegin(), newVal.cend());
			std::cout << s << std::endl;
			iter += n_n;
			temp.assign(iter, iter + n_o);
			
		}
		else {
			++iter;
			
			temp.assign(iter, iter + n_o);
		}
	}


}

int main()
{
	std::string s{ "This is a test for abbreation. thx is thanks. ur is your" };
	std::string old{ "thx " };
	std::string new_v{ "Thanks " };

	findAndReplace(s, old, new_v);
	std::cout << s << std::endl;
	findAndReplace(s, "ur ", "your ");
	std::cout << s << std::endl;
}
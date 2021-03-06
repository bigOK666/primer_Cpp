#include"exercise12_19.h"

int main()
{
	std::string input;
	StrBlob store;
	while (std::getline(std::cin, input)) {
		store.push_back(input);
	}

	StrBlobPtr beg = store.begin();
	while (beg != store.end()) {
		std::cout << beg.deref() << std::endl;
		beg.incr();
	}
}
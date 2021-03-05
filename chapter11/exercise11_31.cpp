#include<map>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	multimap<string, string> authors{ {"author1", "book1"},{"author2","book1"},{"author1", "book2"} };
	string target("author1");
	auto found = authors.find(target);
	auto cnt = authors.count(target);
	
	if (cnt!=0) {
		while (cnt) {
			cout << "Erase " << found->first << endl;
			authors.erase(found);
			++found;
			--cnt;
		}
	}
	else {
		cout << "No such an author!" << endl;
	}
}


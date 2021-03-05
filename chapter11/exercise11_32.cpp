#include<map>
#include<iostream>
#include<string>
#include<set>
using namespace std;

int main()
{
	multimap<string, string> authors{ {"author1", "book1"},{"author2","book1"},{"author1", "book2"} };

	map<string, set<string>> authorOrdered;

	for (auto& author : authors) {
		authorOrdered[author.first].insert(author.second);
	}

	for (const auto& oderAuthor : authorOrdered) {
		cout << oderAuthor.first << endl;
		for (const auto& book : oderAuthor.second) {
			cout << book << endl;
		}
	}
}


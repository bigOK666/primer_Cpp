#include<map>
#include<vector>
#include<set>
#include<iostream>
#include<fstream>
#include<sstream>
#include<memory>
using namespace std;

int main(int argc, char** argv)
{
	using size_t = vector<string>::size_type;
	ifstream infile(argv[1]);
	string text;
	shared_ptr<vector<string>> input_data = make_shared<vector<string>>();
	shared_ptr<map<string, set<size_t>>> query_data = make_shared<map<string, set<size_t>>>();
	size_t line_nr(0);
	while (getline(infile, text)) {
		input_data->push_back(text);
		istringstream row(text);
		string word;
		++line_nr;
		while (row >> word) {
			if (query_data->find(word) == query_data->end()) {
				query_data->insert({ word, {line_nr} });
			}
			else {
				auto iter = query_data->find(word);
				iter->second.insert(line_nr);
			}
		}
	}

	cout << "Enter the word you are looking for:" << endl;
	string target;
	cin >> target;
	auto iter_target = query_data->find(target);
	if ( iter_target!= query_data->end()) {
		cout << target << " appears " << iter_target->second.size() << (iter_target->second.size() > 1 ? "times" : "time") << endl;
		for (auto line : iter_target->second) {
			cout << "(Line " << line << ") " << (*input_data)[line - 1] << endl;
		}
	}
	else {
		cout << "The word is not here." << endl;
	}



}
#include<string>
#include<iostream>
#include<map>
#include<fstream>
#include<sstream>
using namespace std;

map<string, string> buildMap(ifstream& rulFile) {
	map<string, string> dict;
	string key;
	string value;
	while (rulFile >> key && getline(rulFile, value)) {
		if (value.size() > 1) {
			dict[key] = value.substr(1);
		}
		else {
			throw runtime_error("No rule!");
		}
	}

	return dict;
}

const string& translate(const string& w, const map<string, string>& mapFile) {
	auto map_iter = mapFile.find(w);

	if (map_iter != mapFile.end()) {
		return map_iter->second;
	}
	else {
		return w;
	}
}



void textTransform(ifstream& rule, ifstream& source) {
	auto translation = buildMap(rule);

	string text;

	while (getline(source, text)) {
		istringstream stream(text);
		string word;
		while (stream >> word) {
			cout << translate(word, translation) << " ";
		}
		cout << endl;
	}
}
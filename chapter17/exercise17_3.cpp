#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<tuple>
using namespace std;
class QueryResult;


class TextQuery {

public:
	using size_t = string::size_type;
	TextQuery() = default;
	//一定要分配自由内存给智能指针
	TextQuery(ifstream& infile) :input_data(new vector<string>), query_data(new map<string, set<size_t>>) { store(infile); }

	std::tuple<size_t, map<size_t, string>> query(const string&) const;



private:
	shared_ptr<vector<string>> input_data;
	void store(ifstream&);
	shared_ptr<map<string, set<size_t>>> query_data;
};

void TextQuery::store(ifstream& infile)
{
	string row;
	size_t row_nr(0);
	while (getline(infile, row)) {
		//cout << "Push back" << endl;
		input_data->push_back(row);
		istringstream line(row);
		string word;
		++row_nr;
		//cout << "deal with word" << endl;
		while (line >> word) {
			word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
			if (query_data->find(word) == query_data->end()) {
				query_data->insert({ word, {row_nr} });
			}
			else {
				auto iter_exist = query_data->find(word);
				iter_exist->second.insert(row_nr);
			}
		}

	}
}
class QueryResult {
	friend void print(ostream&, QueryResult);
public:
	QueryResult() :t(0) {}
	QueryResult(size_t timeNr, map<size_t, string>& result_map) :t(timeNr), r(result_map) {}
private:
	size_t t;
	map<size_t, string> r;
};
/*
QueryResult TextQuery::query(const string& s) const
{
	auto iter = query_data->find(s);
	if (iter == query_data->end()) {
		cout << "No data" << endl;
		return QueryResult();
	}
	else {
		size_t times(iter->second.size());
		//cout << times << endl;
		map<size_t, string> results;

		for (auto nr : (iter->second)) {
			//cout << nr << endl;
			results[nr] = (*input_data)[nr - 1];
			//cout << results[nr] << endl;
		}

		return QueryResult(times, results);
	}
}
*/

std::tuple<size_t, map<size_t, string>> TextQuery::query(const string& s) const
{
	auto iter = query_data->find(s);
	map<size_t, string> results;
	if (iter == query_data->end()) {
		cout << "No data" << endl;
		return make_tuple(0, results);
	}
	else {
		size_t times(iter->second.size());
		//cout << times << endl;
		map<size_t, string> results;

		for (auto nr : (iter->second)) {
			//cout << nr << endl;
			results[nr] = (*input_data)[nr - 1];
			//cout << results[nr] << endl;
		}

		return make_tuple(times,results);
	}
}



void print(ostream& os, std::tuple<size_t, map<size_t,std::string>> qresult) {
	os << "the word appears " << std::get<0>(qresult) << (std::get<0>(qresult) > 1 ? " times:" : " time:") << endl;
	for (auto result_pair : std::get<1>(qresult)) {
		os << "(Line " << result_pair.first << " )" << result_pair.second << endl;
	}
}
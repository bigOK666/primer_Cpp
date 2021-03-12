#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<iostream>
#include<sstream>
#include<algorithm>
//#include<memory>
#include"exercise13_40.h"

class QueryResult;


class TextQuery {

public:
	using size_t = std::string::size_type;
	TextQuery() = default;
	//一定要分配自由内存给智能指针
	TextQuery(std::ifstream& infile) :input_data(new StrVec), query_data(new std::map<std::string, std::set<size_t>>) { store(infile); }

	QueryResult query(const std::string&) const;



private:
	std::shared_ptr<StrVec> input_data;
	void store(std::ifstream&);
	std::shared_ptr<std::map<std::string, std::set<size_t>>> query_data;
};

void TextQuery::store(std::ifstream& infile)
{
	std::string row;
	size_t row_nr(0);
	while (getline(infile, row)) {
		//cout << "Push back" << endl;
		input_data->push_back(row);
		std::istringstream line(row);
		std::string word;
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
	friend std::ostream& print(std::ostream&, QueryResult);
public:
	QueryResult() :t(0) {}
	QueryResult(size_t timeNr, std::map<size_t, std::string>& result_map) :t(timeNr), r(result_map) {}
private:
	size_t t;
	std::map<size_t, std::string> r;
};

QueryResult TextQuery::query(const std::string& s) const
{
	auto iter = query_data->find(s);
	if (iter == query_data->end()) {
		std::cout << "No data" << std::endl;
		return QueryResult();
	}
	else {
		size_t times(iter->second.size());
		//cout << times << endl;
		std::map<size_t, std::string> results;

		for (auto nr : (iter->second)) {
			//cout << nr << endl;
			results[nr] = (*input_data)[nr - 1];
			//cout << results[nr] << endl;
		}

		return QueryResult(times, results);
	}
}



std::ostream& print(std::ostream& os, QueryResult qresult) {
	os << "the word appears " << qresult.t << (qresult.t > 1 ? " times:" : " time:") << std::endl;
	for (auto result_pair : qresult.r) {
		os << "(Line " << result_pair.first << " )" << result_pair.second << std::endl;
	}
	return os;
}
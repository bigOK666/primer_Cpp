#include<fstream>

#include<set>
#include<map>

#include<sstream>
#include<algorithm>
#include"exercise12_22.h"
using namespace std;
class QueryResult;


class TextQuery {

public:
	using size_t = string::size_type;
	TextQuery() = default;
	//一定要分配自由内存给智能指针
	TextQuery(ifstream& infile) :input_data(StrBlob()), query_data(new map<string, set<size_t>>) { store(infile); }

	QueryResult query(const string&) const;



private:
	StrBlob input_data;
	void store(ifstream&);
	shared_ptr<map<string, set<size_t>>> query_data;
};

void TextQuery::store(ifstream& infile)
{
	string row;
	size_t row_nr(0);
	while (getline(infile, row)) {
		//cout << "Push back" << endl;
		input_data.push_back(row);
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
	friend ostream& print(ostream&, QueryResult);
public:
	QueryResult() :t(0) {}
	QueryResult(size_t timeNr, map<size_t, string>& result_map) :t(timeNr), r(result_map) {}
private:
	size_t t;
	map<size_t, string> r;
};

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
			results[nr] = input_data[nr-1];
			//cout << results[nr] << endl;
		}

		return QueryResult(times, results);
	}
}



ostream& print(ostream& os, QueryResult qresult) {
	os << "the word appears " << qresult.t << (qresult.t > 1 ? " times:" : " time:") << endl;
	for (auto result_pair : qresult.r) {
		os << "(Line " << result_pair.first << " )" << result_pair.second << endl;
	}
	return os;
}


void runQueries(ifstream& infile)
{
	TextQuery tq(infile);

	while (true) {
		cout << "Enter word to look for, or q to quit" << endl;;

		string s;
		if (!(cin >> s) || s == "q") { break; }

		print(cout, tq.query(s)) << endl;;
	}

}

int main(int argc, char** argv)
{
	ifstream in(argv[1]);

	runQueries(in);

}
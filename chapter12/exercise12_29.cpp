#include"exercise12_29.h"

void runQueries(ifstream& infile)
{
	TextQuery tq(infile);
	
	do {
		cout << "Enter word to look for, or q to quit" << endl;;

		string s;
		if (!(cin >> s) || s == "q") { break; }

		print(cout, tq.query(s));
	} while (true);
}

int main(int argc, char** argv)
{
	ifstream in(argv[1]);

	runQueries(in);

}
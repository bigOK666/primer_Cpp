#include<fstream>
#include<iterator>
#include<algorithm>
using namespace std;
int main(int argc, char **argv)
{
	

	ifstream infile(argv[1]);
	ofstream oddfile(argv[2]), evenfile(argv[3]);

	istream_iterator<int> in_iter(infile), eof;
	ostream_iterator<int> odd_iter(oddfile, " "), even_iter(evenfile, "\n");

	//cannot use in_iter twice because istream_iterator is a single-pass iterator. After ++iter, it is invalid anymore.
	//copy_if(in_iter, eof, even_iter, [](int j) {return j % 2 == 0; });

	//copy_if(in_iter, eof, odd_iter, [](int i) {return i % 2 != 0; });

	//but we can use a vector to store the inputs firstly then use copy_if

	while (in_iter != eof) {
		(*in_iter % 2 ? odd_iter : even_iter) = *in_iter++;
	}

}
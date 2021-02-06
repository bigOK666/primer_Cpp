#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, sCnt = 0, tCnt = 0, nCnt = 0;
	char ch;
	while (cin >> std::noskipws>>ch) {
		switch (ch) {
		case 'a':
		case 'A':
			++aCnt;
			break;
		case 'e':
		case 'E':
			++eCnt;
			break;
		case 'i':
		case 'I':
			++iCnt;
			break;
		case 'o':
		case 'O':
			++oCnt;
			break;
		case 'u':
		case 'U':
			++uCnt;
			break;
		case ' ':
			++sCnt;
			break;
		case '\t':
			++tCnt;
			break;
		case '\n':
			++nCnt;
			break;
		default:

			break;
		}
	}

	cout << aCnt << " " << eCnt << " " << iCnt << " " << oCnt << " " << uCnt <<" " <<sCnt<<" "<<tCnt<<" "<<nCnt<< endl;

	return 0;
}
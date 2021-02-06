#include<string>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
	string in, lastIn, maxString;
	unsigned tempCnt = 1, maxNum = 1;

	while (cin >> in) {
		if (in == lastIn) {
			++tempCnt;
			
			
		}
		else {
			if (tempCnt > maxNum) {
				maxNum = tempCnt;
				maxString = lastIn;
			}
			tempCnt = 1;
			lastIn = in;
		}

		
	}

	if (maxNum == 1) {
		cout << "there is no successive word" << endl;
	}
	else {
		cout << maxString << " " << maxNum << endl;

	}

	return 0;
}
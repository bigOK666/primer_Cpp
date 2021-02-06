#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;

	char c1='\0', buff='\0';

	while (cin >> c1) {
		
		switch (buff) {

			case 'f':
				switch (c1) {
				case 'f':
					++ffCnt;
					break;
				case 'l':
					++flCnt;
					break;
				case 'i':
					++fiCnt;
					break;
				}
				
				break;
			default:
				
				break;
		}
		buff = c1;

	}

	cout << ffCnt << " " << flCnt << " " << fiCnt << " " << endl;

	return 0;
}
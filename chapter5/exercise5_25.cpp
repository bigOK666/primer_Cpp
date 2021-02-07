#include<iostream>
#include<stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
int main()
{
	int i1, i2;
	while (cin >> i1 >> i2) {
		try {
			if (i2 == 0) {
				throw runtime_error("divider should be non-zero");
			}

			cout << i1 / i2;


		}
		catch (runtime_error err) {
			cout << err.what() << "\n Try enter two non-zero values again?y or n" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n') {
				break;
			}
		}

	}
	return 0;
}
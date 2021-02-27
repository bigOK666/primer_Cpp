#include<forward_list>
#include<string>
using std::string;
void findAndReplace(std::forward_list<string> f_l, const string& target, const string& insertValue) {
	auto prev = f_l.before_begin();
	auto curr = f_l.begin();
	int cnt = 0;
	while (curr != f_l.end()) {
		if (*curr == target) {
			curr = f_l.insert_after(curr, insertValue);
			++cnt;
		}
		prev = curr;
		++curr;
	}

	if (!cnt) {
		
		
		f_l.insert_after(prev, insertValue);
	}
}

int main()
{

}
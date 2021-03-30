#include<vector>
#include<memory>
struct intArray {
	intArray() :p(nullptr) {}
	explicit intArray(size_t n) :p(new int[n]) {}

	~intArray() {
		delete[] p;
	}

	int* p;
};

void exercise(int* b, int* e) {
	std::vector<int>v(b, e);
	//first approach
	intArray p(v.size());
	//second approach
	std::shared_ptr<int> p2(new int[v.size()], [](int* p) {delete[] p; });

	//exception occurs here
}
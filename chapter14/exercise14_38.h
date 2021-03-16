#include<string>

class isSize {
public:
	isSize(size_t n) :size(n) {}
	bool operator()(const std::string& s) {
		return s.size() == size;
	}

private:
	size_t size;
};

class greaterSize {
public:
	greaterSize(size_t n) : size(n) {}
	bool operator() ( const std::string& s ) {
		return s.size() >= size;
	}
private:
	size_t size;
};
class isEqual {
public:
	isEqual(int i=0):ref(i){}
	bool operator()(int a) {
		return a == ref;
	}
private:
	int ref;
};


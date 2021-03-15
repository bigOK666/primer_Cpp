class IfThenElse {
public:
	int operator()(bool b, int a, int c) {
		return b ? a : c;
	}
};
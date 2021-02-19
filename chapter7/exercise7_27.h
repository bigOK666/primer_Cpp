#include<string>

class Screen {
public:
	typedef std::string::size_type pos;

	Screen() = default;
	Screen(pos h, pos w) :height(h), width(w), contents(h* w, ' ') {};
	Screen(pos h, pos w, char c) : height(h), width(w), contents(h* w, c) {};

	char get() const { return contents[cursor]; }
	char get(pos r, pos c) const;
	Screen& move(pos r, pos c);
	Screen& set(char c);
	Screen& set(pos, pos, char);
	Screen& display(std::ostream &os) { do_display(os); return *this; };
	const Screen& display(std::ostream& os) const { do_display(os); return *this; };
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

private:
	void do_display(std::ostream& os) const {
		os << contents;
	}
};

inline Screen& Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}

inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen& Screen::set(pos r, pos c, char ch)
{
	contents[r * width + c] = ch;
	return *this;
}
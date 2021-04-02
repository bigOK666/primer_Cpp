#include<string>

class Screen {
	
public:
	typedef std::string::size_type pos;
	static const pos Screen::* cursor_ptr();
	char get_cursor() const { return contents[cursor]; }
	char get() const;
	char get(pos ht, pos wd) const;
private:
	std::string contents;
	pos cursor;
	pos height, width;
};

const Screen::pos Screen::* Screen::cursor_ptr() {
	return &Screen::cursor;
};

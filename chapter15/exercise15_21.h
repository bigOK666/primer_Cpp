#include<string>
#include<iostream>
class Image {
public:
	virtual void show_name() const { std::cout << name; }

private:
	std::size_t width;
	std::size_t height;

protected:
	std::string name;
	
};

class gif :public Image {
	void show_name() const override { std::cout << name << ".gif"; }
};

class tiff :public Image {
	void show_name() const override { std::cout << name << ".tiff"; }
};

class jepeg :public Image {
	void show_name() const override { std::cout << name << ".jepeg"; }
};

class bmp :public Image {
	void show_name() const override { std::cout << name << ".bmp"; }
};
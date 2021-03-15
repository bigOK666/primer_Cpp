#include<memory>
#include<vector>
#include<initializer_list>
#include<string>
#include<iostream>
class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob {
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator!=(const StrBlob&, const StrBlob&);
	friend bool operator<(const StrBlob&, const StrBlob&);
public:
	using size_type = std::vector<std::string>::size_type;

	StrBlob() :data(std::make_shared<std::vector<std::string>>()) {};
	StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {};
	size_type size() const { return data->size(); };
	bool empty() const { return data->empty(); };
	void push_back(const std::string& s) { data->push_back(s); }
	void pop_back();
	std::string& front();
	std::string& back();
	const std::string& front() const;
	const std::string& back() const;

	StrBlobPtr begin();
	StrBlobPtr end();

	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;

	std::string& operator[](size_type i);
	const std::string& operator[](size_type i) const;

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string& msg) const;
};


bool operator==(const StrBlob& s1, const StrBlob& s2)
{
	return *(s1.data) == *(s2.data);
}

bool operator!=(const StrBlob& s1, const StrBlob& s2)
{
	return !(s1 == s2);
}

void StrBlob::check(size_type i, const std::string& msg) const {
	if (i >= data->size()) {
		throw std::out_of_range(msg);
	}
}

std::string& StrBlob::front() {
	check(0, "Front on empty StrBlob");
	return data->front();
}

const std::string& StrBlob::front() const {
	check(0, "Front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back() {
	check(0, "Back on empty StrBlob");
	return data->back();
}

const std::string& StrBlob::back() const {
	check(0, "Back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

bool operator<(const StrBlob& s1, const StrBlob& s2)
{
	if (s1.size() < s2.size()) {
		return true;
	}
	else if (s1.size() > s2.size()) {
		return false;
	}
	else {
		return *s1.data < *s2.data;
	}
}
std::string& StrBlob::operator[](size_type i)
{
	check(i, "Out of range");
	return (*data)[i];
}

const std::string& StrBlob::operator[](size_type i) const
{
	check(i, "Out of range");
	return (*data)[i];
}

//StrBlobPtr
class StrBlobPtr {
	friend bool operator!=(const StrBlobPtr& s1, const StrBlobPtr& s2) { return (s1.curr != s2.curr) || (s1.wptr.lock() != s2.wptr.lock()); }
	friend bool operator==(const StrBlobPtr& s1, const StrBlobPtr& s2) { return !(s1 != s2); }
	friend bool operator<(const StrBlobPtr& s1, const StrBlobPtr& s2) { return s1.curr < s2.curr; }
	friend StrBlobPtr operator+(const StrBlobPtr& s1, size_t);
	friend StrBlobPtr operator-(const StrBlobPtr& s2, size_t);
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	std::string& deref() const;
	StrBlobPtr& incr();
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	std::string& operator[](size_t i);
	const std::string& operator[](size_t i) const;


private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string& msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size()) {
		throw std::out_of_range(msg);
	}
	return ret;
}

std::string& StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

std::string& StrBlobPtr::operator[](size_t i)
{
	auto ptr = check(i, "out of range");
	return ptr->at(i);
}

const std::string& StrBlobPtr::operator[](size_t i) const
{
	auto ptr = check(i, "out of range");
	return ptr->at(i);
}

StrBlobPtr& StrBlobPtr::operator++()
{
	check(curr, "increment past range");
	++curr;
	return *this;
}
StrBlobPtr& StrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrement pasts range");
	return *this;
}
StrBlobPtr StrBlobPtr::operator++(int)
{
	auto ret = *this;
	++* this;
	return ret;
}
StrBlobPtr StrBlobPtr::operator--(int)
{
	auto ret = *this;
	--* this;
	return ret;
}

StrBlobPtr operator-(const StrBlobPtr& s2, size_t n)
{
	StrBlobPtr ret(s2);
	ret.curr = ret.curr - n;
	ret.check(ret.curr, "out of range");

	return ret;
}

StrBlobPtr operator+(const StrBlobPtr& s1, size_t n)
{
	StrBlobPtr ret(s1);
	ret.curr = ret.curr + n;
	ret.check(ret.curr, "out of range");

	
	return ret;



}


class ConstStrBlobPtr {
public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob& a, size_t sz = 0) :wptr(a.data), curr(sz) {}
private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;


};

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

ConstStrBlobPtr StrBlob::cbegin() const { return ConstStrBlobPtr(*this); }
ConstStrBlobPtr StrBlob::cend() const { return ConstStrBlobPtr(*this, data->size()); }
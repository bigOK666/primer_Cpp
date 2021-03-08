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

	std::string& operator[](size_type i) { return (*data)[i]; } // 省略了check
	const std::string& operator[](size_type i) const { return (*data)[i]; } // 省略了check

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string& msg) const;
};



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

//StrBlobPtr
class StrBlobPtr {
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob& a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	std::string& deref() const;
	StrBlobPtr& incr();
	bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
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
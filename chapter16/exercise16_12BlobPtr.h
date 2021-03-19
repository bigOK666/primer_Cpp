#include<memory>
#include"exercise16_12BlobTemplate.h"
#include<iostream>

template<typename> class BlobPtr;
template<typename T>bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
template<typename T>bool operator<(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);


template<typename T> class BlobPtr {
	friend bool operator==<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
	friend bool operator< <T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
public:
	BlobPtr() :curr(0) {}
	BlobPtr(Blob<T>& a, size_t sz = 0) :wptr(a.data), curr(sz) {}

	T& operator*() const { auto p = check(curr, "dereference pasts end"); return (*p)[curr]; }

	BlobPtr& operator++();
	BlobPtr& operator--();

private:
	std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
};

template<typename T> std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string& msg) const
{
	auto p=wptr.lock();
	if (!p) throw std::runtime_error("unbound StrBlobPtr");
	if (i > p->size()) throw std::out_of_range(msg);
	
	return p;
}

template<typename T> BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of StrBlob");
	++curr;
	return *this;
}

template<typename T> BlobPtr<T>& BlobPtr<T>::operator--()
{
	--curr;
	check(curr, "decrement past begin of BlobPtr");

	return *this;
}

template<typename T> bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock()) {
		throw runtime_error("ptrs to different Blobs!");
	}
	return lhs.i == rhs.i;
}

template<typename T> bool operator< (const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
	if (lhs.wptr.lock() != rhs.wptr.lock()) {
		throw runtime_error("ptrs to different Blobs!");
	}
	return lhs.i < rhs.i;
}

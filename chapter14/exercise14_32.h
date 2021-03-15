#include"exercise14_30.h"

class HasStrBlobPtr {
public:
	HasStrBlobPtr() = default;
	HasStrBlobPtr(StrBlobPtr* p) :ptr(p) {};

	StrBlobPtr& operator*() const;
	StrBlobPtr* operator->() const;
private:
	StrBlobPtr* ptr ;

};

StrBlobPtr& HasStrBlobPtr::operator*() const
{
	return *ptr;
}

StrBlobPtr* HasStrBlobPtr::operator->() const
{
	return ptr;
}
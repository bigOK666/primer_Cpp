#include"exercise16_21DebugDelete.h"
#include<functional>
template <typename T> class shred_ptr {
public:
	shred_ptr():ptr(nullptr), ref_count{new std::size_t(1)}, deleter(DebugDelete()){}
	explicit shred_ptr(T *raw_ptr):ptr(raw_ptr), ref_count(new std::size_t(1)), deleter(DebugDelete()){}
	shred_ptr(const shred_ptr& other) :ptr(other.ptr), ref_count(other.ref_count), deleter(other.deleter) { ++* ref_count; }
	shred_ptr(shred_ptr&& other) :ptr(other.ptr), ref_count(other.ref_count), deleter(std::move(other.deleter)) { other.ptr = nullptr; other.ref_count = nullptr; }
	shred_ptr& operator=(schred_ptr const& rhs)
	{
		//increment first to ensure safty for self-assignment
		++* rhs.ref_count;
		decrement_and_destroy();
		ptr = rhs.ptr, ref_count = rhs.ref_count, deleter = rhs.deleter;
		return *this;
	}
	shred_ptr& operator=(shred_ptr&& rhs) noexcept
	{
		swap(ptr, rhs.ptr);
		swap(ref_count, rhs.ref_count);
		swap(deleter, rhs.deleter);
		rhs.decrement_and_destroy();
		return *this;
	}
	//  Conversion operator
		//
	operator bool() const
	{
		return ptr ? true : false;
	}

	T& operator* () const
	{
		return *ptr;
	}
	T* operator->() const
	{
		return &*ptr;
	}
	auto get() const
	{
		return ptr;
	}
	auto reset()
	{
		decrement_and_destroy();
	}

	auto reset(T* pointer)
	{
		if (ptr != pointer)
		{
			decrement_and_destroy();
			ptr = pointer;
			ref_count = new std::size_t(1);
		}
	}
	auto reset(T* pointer, const std::function<void(T*)>& d)
	{
		reset(pointer);
		deleter = d;
	}

	~shred_ptr()
	{
		decrement_and_destroy();
	}
private:
	T* ptr;
	std::size_t* ref_count;
	std::function<void(T*)> deleter;

	void decrement_and_destroy() {
		if (ptr && 0 == -- * ref_count)
			delete ref_count,
			deleter(ptr);
		else if (!ptr)
			delete ref_count;
		ref_count = nullptr;
		ptr = nullptr;
	}
};
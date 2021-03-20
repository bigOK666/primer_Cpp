#include"exercise16_21DebugDelete.h"

template<typename T, typename D = DebugDelete> class u_ptr {
public:
	u_ptr() = default;
	explicit u_ptr(T *up):ptr(up){}
	u_ptr(const u_ptr&) = delete;
	u_ptr& operator=(const u_ptr&) = delete;

	u_ptr(uptr&& up)noexcept :ptr(up.ptr) { up.ptr = nullptr; }
	u_ptr& operator=(u_ptr&& rhs)noexcept {
		// prevent self-assignment
		if (ptr != rhs.ptr)
		{
			deleter(ptr);
			ptr = nullptr;
			ptr = rhs.ptr;
			deleter = rhs.deleter;
		}
		return *this;
	};

	~u_ptr() {
		deleter(ptr);
	}

private:
	T* ptr = nullptr;
	D deleter = D();
};
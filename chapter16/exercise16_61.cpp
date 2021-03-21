#include<memory>

template<typename T, typename... Args>
std::shared_ptr<T> mk_shared(Args&&... args)
{
	return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}
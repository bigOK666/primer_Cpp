#include<initializer_list>
#include<memory>
#include<vector>
template<typename T> class Blob {
	Blob(std::initializer_list<T> il) try: data(std::make_shared<std::vector<T>>(il)){ 
	}
	catch (const std::bad_alloc& e) { handle_out_of_memory(e); }
private:
	std::shared_ptr<std::vector<T>> data;
};
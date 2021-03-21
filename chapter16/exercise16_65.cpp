#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>

template <typename T>
std::string debug_rep(T* t);

template<>
std::string debug_rep(const char* str);
template<>
std::string debug_rep(char* str);

template <typename T>
std::string debug_rep(T* t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();
}
// ģ��������
// T = const char*
template<>
std::string debug_rep(const char* str)
{
    std::string ret(str);
    return str;
}
// ģ��������
// T =       char*
template<>
std::string debug_rep(char* str)
{
    std::string ret(str);
    return ret;
}

#include<map>
#include<iostream>
int main()
{
	std::map<int, int>m_i{ {1,1} };

	auto iter = m_i.begin();
	iter->second = 2;

	std::cout << m_i[1];

}
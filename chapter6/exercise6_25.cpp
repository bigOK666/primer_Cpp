#include<string>
#include<iostream>

int main(int argc, char* argv[])
{
	std::string s1,s2,s3;
	s1 = argv[1];
	s2 = argv[2];
	s3 = s1 + s2;

	std::cout << s3 << std::endl;

	return 0;

	
}
#include<iostream>

int main()
{	
	//接下来的语句可行是因为/**/ 采用就近配对原则
	std::cout << /* "*/"  /*"/*"  */;

	return 0;
}
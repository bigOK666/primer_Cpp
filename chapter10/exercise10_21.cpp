int main()
{
	int a = 42;
	auto l = [&a]()-> bool  {if (a == 0) { return true; } else { --a; return false;}  };


}



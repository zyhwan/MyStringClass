#include<iostream>

using namespace std;

class String
{
public:
	String()
	{
		Str = nullptr;
		len = 0;
	}
	String(const char* str)
	{

	}

	~String()
	{

	}



private:
	char* Str;
	int len;

};


int main()
{


	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class String
{
public:
	String() : Str(nullptr), len(0)
	{

	}
	String(const char* str)
	{
		if (str != nullptr)
		{
			len = strlen(str);
			Str = new char[len + 1];
			strcpy(Str, str);
		}
	}
	String(const String& rhs)
	{
		len = rhs.len;
		Str = new char[len + 1];
		strcpy(Str, rhs.Str);
	}
	//복사 대입 연산자 오버로딩
	String& operator=(const String& rhs)
	{
		len = rhs.len;
		delete Str;
		Str = new char[len + 1];
		strcpy(Str, rhs.Str);

		return *this;
	}

	~String()
	{
		cout << "소멸자 호출" << endl;
		delete[] Str;
	}
	const char* GetData()
	{
		if (Str != nullptr)
		{
			return Str;
		}
		return "";
	}
	int GetLen()
	{
		return len;
	}
private:
	char* Str;
	int len;
};

String getName()
{
	String res("Doodle");
	return res;
}


int main()
{
	String s1("Hello");
	String s2;
	
	s2 = s1;

	String a;
	a = getName();

	cout << a.GetData() << endl;

	cout << s1.GetData() << endl;
	cout << s2.GetData() << endl;


	return 0;
}
#include<iostream>

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
		len = strlen(str);
		Str = new char[len + 1];
		strcpy(Str, str);
	}
	//복사 생성
	String(const String& rhs)
	{
		len = rhs.len;
		Str = new char[len + 1];
		strcpy(Str, rhs.Str);
	}
	//복사 대입 연산자 오버로딩
	String& operator=(String& rhs)
	{
		if (this != &rhs)
		{
			len = rhs.len;
			delete[] Str;
			Str = new char[len + 1];
			strcpy(Str, rhs.Str);
		}
		return *this;
	}

	const char* GetStr()
	{
		if (len > 0)
		{
			return Str;
		}
		return "";
	}

	~String()
	{
		std::cout << "소멸자 호출" << std::endl; 
		delete Str;
	}
private:
	char* Str;
	int len;
};


int main()
{
	String str("Hello");
	String s2(str);
	String s3;

	s3 = s2;

	std::cout << str.GetStr() << std::endl;
	std::cout << s2.GetStr() << std::endl;
	std::cout << s3.GetStr() << std::endl;

	return 0;
}
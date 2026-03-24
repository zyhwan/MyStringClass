#include<iostream>

class String
{
public:
	String() : Str(nullptr), len(0)
	{

	}
	//기본 생성자
	String(const char* str)
	{	
		len = strlen(str);
		Str = new char[len + 1];
		strcpy(Str, str);
	}
	//복사 생성자
	String(const String& rhs)
	{
		len = rhs.len;
		Str = new char[len + 1];
		strcpy(Str, rhs.Str);
	}
	//이동 생성자
	String(String&& rhs)
	{
		len = rhs.len;
		Str = rhs.Str;
		rhs.Str = nullptr;
	}
	~String()
	{
		std::cout << "소멸자 호출" << std::endl;
 		delete[] Str;
	}
	//대입 연산자 오버로딩
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
	//이동 대입 연산자 오버로딩
	String& operator=(String&& rhs)
	{
		if (this != &rhs)
		{
			len = rhs.len;
			Str = rhs.Str;
			rhs.Str = nullptr;
		}
		return *this;
	}
	char* GetData() const
	{
		return Str;
	}
	int GetLen() const
	{
		return len;
	}

private:
	char* Str;
	int len;

};

String GetStr()
{
	String s1("tempStr");
	return s1;
}


int main()
{
	String s1("Hello");
	String s2;
	String s3(GetStr());
	String s4;

	s2 = s1;
	s4 = GetStr();
	

	std::cout << s1.GetData() << std::endl;
	std::cout << s2.GetData() << std::endl;
	std::cout << s3.GetData() << std::endl;
	std::cout << s4.GetData() << std::endl;
}
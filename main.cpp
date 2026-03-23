#include <iostream>

class String
{
public:
	String() : Str(nullptr), len(0)
	{

	}
	String(const char* str)
	{
		len = strlen(str);
		alloc(len);
		strcpy(Str, str);
	}
	//복사 생성자
	String(const String& rhs)
	{
		len = rhs.len;
		alloc(len);
		strcpy(Str, rhs.Str);
	}
	//이동 생성자
	String(String&& rhs)
	{
		len = rhs.len;
		Str = rhs.Str;
		rhs.Str = nullptr;
	}
	//복사 대입 연산자 오버로딩
	String& operator=(String& rhs)
	{
		if (this != &rhs)
		{
			len = rhs.len;
			release();
			alloc(len);
			strcpy(Str, rhs.Str);
		}
		return *this;
	}
	//이동 대입 연산자 오버로딩
	String& operator=(String&& rhs)
	{
		len = rhs.len;
		Str = rhs.Str;
		rhs.Str = nullptr;
		return *this;
	}

	String &operator<<(String& str)
	{
		return *this;
	}


	~String()
	{
		std::cout << "소멸자 호출" << std::endl;
		release();
	}

	const char* GetData()
	{
		if(Str != nullptr)
		{
			return Str;
		}
		return"";
	}

private:
	void alloc(const int n)
	{
		Str = new char[n + 1];
	}
	void release()
	{
		if (Str != nullptr)
		{
			delete[] Str;
		}
	}
	char* Str;
	int len;
};


int main()
{
	String s1("Hello");
	String s2(s1);
	String s3;
	s3 = s1;

	std::cout << s1.GetData() << std::endl;
	std::cout << s2.GetData() << std::endl;
	std::cout << s3.GetData() << std::endl;
	
	return 0;
}

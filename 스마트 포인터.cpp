#include<iostream>
#include<memory>

class MyClass
{
public:
	MyClass() : x(0)
	{
		std::cout << "Default MyClass()" << std::endl;
	}
	MyClass(int x) : x(x)
	{
		std::cout << "MyClass()" << std::endl;
	}
	~MyClass()
	{
		std::cout << "~MyClass()" << std::endl;
	}

	int GetX() const
	{
		return x;
	}
private:
	int x;
};


int main()
{
	//std::unique_ptr<MyClass> a = std::unique_ptr<MyClass>(new MyClass(5));
	//std::cout << a->GetX() << std::endl;
	//std::unique_ptr<MyClass> b(move(a));
	//std::cout << b->GetX() << std::endl;
	//b.reset(new MyClass(3));
	//std::cout << b->GetX() << std::endl;
	//b.reset(new MyClass(1));
	//std::cout << b->GetX() << std::endl;

	std::shared_ptr<MyClass> a(new MyClass(5));
	{
		std::shared_ptr<MyClass> b = a;
		std::cout << a->GetX() << std::endl;
		std::cout << b->GetX() << std::endl;
		std::cout << a.use_count() << std::endl;
		std::cout << b.use_count() << std::endl;
		b.reset();
		std::cout << b.use_count() << std::endl;
	}
	std::cout << a.use_count() << std::endl;



}
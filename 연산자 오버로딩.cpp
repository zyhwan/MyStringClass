#include<iostream>

using namespace std;

class Vector2
{
public:
	Vector2() : x (0.0f), y(0.0f)
	{

	}
	Vector2(float x, float y) : x(x), y(y)
	{

	}
	~Vector2()
	{

	}

	Vector2 operator+(Vector2 other)
	{
		return Vector2(x + other.x, y + other.y);
	}
	Vector2 operator-(Vector2 other)
	{
		return Vector2(x - other.x, y - other.y);
	}



private:
	float x;
	float y;
};


int main()
{


}
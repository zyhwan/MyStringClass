#include <iostream>

using namespace std;

class Vector2
{
public:
	Vector2() : x(0), y(0) {}
	Vector2(float x, float y) : x(x), y(y) {}
	~Vector2() {}

	Vector2 operator+(const Vector2 other) const
	{
		return Vector2(x + other.x, y + other.y);
	}
	Vector2 operator-(const Vector2 other) const
	{
		return Vector2(x - other.x, y - other.y);
	}
	Vector2& operator+=(const Vector2 other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	Vector2& operator-=(const Vector2 other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	float GetX() const
	{
		return x;
	}
	float GetY() const
	{
		return y;
	}
private:
	float x;
	float y;
};

template<typename T>
T getArraySum(const T arr[], int n)
{
	T sum = arr[0];
	for (int i = 1; i < n; ++i)
	{
		sum += arr[i];
	}
	return sum;
}

int main()
{
	int sumArray[5] = {1,3,2,31,1};

	Vector2 VecArray[3] = { Vector2(1,2), Vector2(3,4), Vector2(5,6) };

	int sumi = getArraySum<int>(sumArray, 5);
	Vector2 sumv = getArraySum<Vector2>(VecArray, 3);

	cout << sumi << endl;
	cout << sumv.GetX() << ", " << sumv.GetY() << endl;

	return 0;
}
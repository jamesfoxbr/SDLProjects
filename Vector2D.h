#ifndef VECTOR_2D
#define VECTOR_2D

// Vector2D

template<typename T>
struct Vector2D
{
	T x, y;

	Vector2D operator+(Vector2D const& obj)
	{
		Vector2D vec;
		vec.x = x + obj.x;
		vec.y = y + obj.y;
		return vec;
	}
	Vector2D operator-(Vector2D const& obj)
	{
		Vector2D vec;
		vec.x = x - obj.x;
		vec.y = y - obj.y;
		return vec;
	}
	Vector2D operator*(Vector2D const& obj)
	{
		Vector2D vec;
		vec.x = x * obj.x;
		vec.y = y * obj.y;
		return vec;
	}
	Vector2D operator/(Vector2D const& obj)
	{
		Vector2D vec;
		vec.x = x / obj.x;
		vec.y = y / obj.y;
		return vec;
	}

	Vector2D(T x, T y)
		: x(x), y(y)
	{
	}

	Vector2D() = default;
};

#endif // !VECTOR_2D


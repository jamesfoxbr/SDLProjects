#ifndef VECTOR_2D
#define VECTOR_2D

// Vector2D

//Interger vector 2D version
struct Vector2Di
{
	int mX, mY;

	Vector2Di operator+(Vector2Di const& obj)
	{
		Vector2Di vec;
		vec.mX = mX + obj.mX;
		vec.mY = mY + obj.mY;
		return vec;
	}
	Vector2Di operator-(Vector2Di const& obj)
	{
		Vector2Di vec;
		vec.mX = mX - obj.mX;
		vec.mY = mY - obj.mY;
		return vec;
	}
	Vector2Di operator*(Vector2Di const& obj)
	{
		Vector2Di vec;
		vec.mX = mX * obj.mX;
		vec.mY = mY * obj.mY;
		return vec;
	}
	Vector2Di operator/(Vector2Di const& obj)
	{
		Vector2Di vec;
		vec.mX = mX / obj.mX;
		vec.mY = mY / obj.mY;
		return vec;
	}

	Vector2Di(int x, int y)
		: mX(x), mY(y)
	{
	}

	Vector2Di() = default;
};

// Float vector 2D version

struct Vector2Df
{
	float mX, mY;

	Vector2Df operator+(Vector2Df const& obj)
	{
		Vector2Df vec;
		vec.mX = mX + obj.mX;
		vec.mY = mY + obj.mY;
		return vec;
	}
	Vector2Df operator-(Vector2Df const& obj)
	{
		Vector2Df vec;
		vec.mX = mX - obj.mX;
		vec.mY = mY - obj.mY;
		return vec;
	}
	Vector2Df operator*(Vector2Df const& obj)
	{
		Vector2Df vec;
		vec.mX = mX * obj.mX;
		vec.mY = mY * obj.mY;
		return vec;
	}
	Vector2Df operator/(Vector2Df const& obj)
	{
		Vector2Df vec;
		vec.mX = mX / obj.mX;
		vec.mY = mY / obj.mY;
		return vec;
	}

	Vector2Df(float x, float y)
		: mX(x), mY(y)
	{
	}

	Vector2Df() = default;
};

#endif // !VECTOR_2D


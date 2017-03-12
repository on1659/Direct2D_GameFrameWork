#pragma once

namespace Radar
{
	class Vector2
	{
		using T = float;
	public:
		T x;
		T y;

		//생성자도 여러가지로 만들 수 있음
		Vector2(const T& x = 0.0f, const T& y = 0.0f) : x(x), y(y) {}
	
		Vector2(const Vector2& 	other)
		{
			x = other.x;
			y = other.y;
		}
		Vector2(const Vector2&& other)
		{
			x = other.x;
			y = other.y;
		}

		~Vector2() {}

		void set(const T& x, const T& y) { this->x = x; this->y = y; }

		//const를 붙이는건 other은 수정하지 않는거니깐 붙이는거
		 Vector2& operator+(const Vector2& other) { return Vector2(x + other.x, y + other.y);}
		 void operator+=(const Vector2& other) { x += other.x; y += other.y; }
		 Vector2& operator-(const Vector2& other) { return Vector2(x - other.x, y - other.y);}
		 void operator-=(const Vector2& other) {	x -= other.x; y -= other.y; }


		//하나는 벡터끼리 곱셈이고, 하나는 벡터*스칼라 곱셈
		Vector2& operator*(const Vector2& other) const
		{
			return Vector2(x * other.x, y * other.y);
		}
		void operator*=(const Vector2& other)
		{
			x *= other.x; y *= other.y;
		}

		Vector2& operator*(const float& a) const
		{
			return Vector2(x * a, y * a);
		}
		void operator*=(const float& a)
		{
			x *= a; y *= a;
		}
		
		Vector2& operator/(const Vector2& other) const
		{
			return Vector2(x / other.x, y / other.y);
		}
		void operator/=(const Vector2& other)
		{
			x /= other.x; y /= other.y;
		}

		Vector2& operator/(const float& a) const
		{
			return Vector2(x / a, y / a);
		}
		  void operator/=(const float& a)
		{
			x /= a; y /= a;
		}

		float InnerProduct(Vector2 other) const
		{
			return (x * other.x) + (y * other.y);
		}

		 inline float scale() const { return sqrt((x * x) + (y * y)); }

		//단휘벡터 만들기 
		 Vector2& normalize() const
		{
			float s = scale();
			return Vector2(x / s, y / s);
		}

		//두 벡터간의 거리.. (현재 이 벡터와 다른 벡터간의 거리
		float length(const Vector2& other) const
		{
			return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
		}

	};


};
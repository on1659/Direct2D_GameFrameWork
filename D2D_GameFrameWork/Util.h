#pragma once

namespace Radar
{
	class Vector2
	{
		using T = float;
	public:
		T x;
		T y;

		//�����ڵ� ���������� ���� �� ����
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

		//const�� ���̴°� other�� �������� �ʴ°Ŵϱ� ���̴°�
		 Vector2& operator+(const Vector2& other) { return Vector2(x + other.x, y + other.y);}
		 void operator+=(const Vector2& other) { x += other.x; y += other.y; }
		 Vector2& operator-(const Vector2& other) { return Vector2(x - other.x, y - other.y);}
		 void operator-=(const Vector2& other) {	x -= other.x; y -= other.y; }


		//�ϳ��� ���ͳ��� �����̰�, �ϳ��� ����*��Į�� ����
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

		//���ֺ��� ����� 
		 Vector2& normalize() const
		{
			float s = scale();
			return Vector2(x / s, y / s);
		}

		//�� ���Ͱ��� �Ÿ�.. (���� �� ���Ϳ� �ٸ� ���Ͱ��� �Ÿ�
		float length(const Vector2& other) const
		{
			return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
		}

	};


};
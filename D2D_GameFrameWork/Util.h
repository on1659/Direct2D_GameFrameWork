#pragma once

#include <vector>
#include <map>
#include <direct.h>

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

	void set(const T& x, const T& y) { Vector2::x = x; Vector2::y = y; }

	//const를 붙이는건 other은 수정하지 않는거니깐 붙이는거
	Vector2& operator+(const Vector2& other) { auto v2 = Vector2(x + other.x, y + other.y); return v2; }
		void operator+=(const Vector2& other) { x += other.x; y += other.y; }


	Vector2& operator-(Vector2& other) { return Vector2(x - other.x, y - other.y); }
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

		void operator=(const Vector2& other) { x = other.x; y = other.y; }

	float dot(Vector2 other) const
	{
		return (x * other.x) + (y * other.y);
	}

	inline float scale() const { return sqrt((x * x) + (y * y)); }

	//단위벡터 만들기 
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

class BoundingBox_2D
{

public:
	D2D_RECT_F     rect;

	Vector2			m_position;
	Vector2			m_size;

public:
		
	void SetBoxLTRD(const Vector2& pos, const Vector2& size)
	{
		SetBoxLTRD(pos.x, pos.y, size.x, size.y);
	}
	void SetBoxLTRD(const float& left, const float& top, const float& right, const float& bot)
	{
		rect.left		= left; 
		rect.right		= right;
		rect.top		= top; 
		rect.bottom		= bot;
		m_size.x		= right - left;
		m_size.y		= bot - top;
		m_position.x	= left + (m_size.x * 0.5f);
		m_position.y	= top  + (m_size.y * 0.5f);
	}

	void SetBoxCenter(const BoundingBox_2D& boundingbox) { SetBoxCenter(boundingbox.m_position, boundingbox.m_size); }
	void SetBoxCenter(const Vector2& pos, const Vector2& size) { SetBoxCenter(pos.x, pos.y, size.x, size.y);	}
	void SetBoxCenter(const float& x, const float& y, const float& w, const float& h)
	{
		m_size.x		= w;
		m_size.y		= h;
		m_position.x	= x;
		m_position.y	= y;

		rect.left		= x - (w * 0.5f);
		rect.right		= x + (w * 0.5f);
		rect.top		= y - (h * 0.5f);
		rect.bottom		= y + (h * 0.5f);
	}

	bool collision(BoundingBox_2D& other)
	{
		return collision(other.GetRect());
	}
	bool collision(const D2D_RECT_F& rect)
	{
		if (rect.left   > rect.right)return false;
		if (rect.right  < rect.left)return false;
		if (rect.top    > rect.bottom)return false;
		if (rect.bottom < rect.top)return false;
		return true;
	}
	bool contains(const Vector2& v2) const { return contains(v2.x, v2.y); }
	bool contains(const float& x, const float& y) const
	{
		return rect.left < rect.right 
			&& rect.top < rect.bottom
			&& rect.left <= x && x < rect.right 
			&& rect.top <= y  && y < rect.bottom;
	}

	void offset(const Vector2& v2) { offset(v2.x, v2.y); }
	void offset(const float& x, const float& y)
	{
		m_position.x = m_position.x + x;
		m_position.y = m_position.y + y;

		rect.left    += x;
		rect.right   += x;
		rect.top     += y;
		rect.bottom  += y;

	}

	const Vector2& GetPosition() const { return m_position; }
	const Vector2& GetSize()	 const { return m_size; }

	void Set(const Vector2& v2) { update(v2.x, v2.y); }
	void Set(const float& x, const float& y) { update(x, y); }
	void Set(const float& x, const float& y, const float& w, const float& h) 
	{
		SetSize(w, h);
		update(x, y); 
	}

	void SetX(const float& x)
	{
		m_position.x = x;
		rect.left = x - (m_size.x * 0.5f);
		rect.right = x + (m_size.x * 0.5f);
	}
	void SetY(const float& y)
	{
		m_position.y = y;
		rect.top = y - (m_size.y * 0.5f);
		rect.bottom = y + (m_size.y * 0.5f);
	}

	void SetSize(const float& w, const float& h)	{ SetWidth(w); SetHeight(h); }
	void SetSize(const Vector2& size)				{ SetSize(size.x, size.y); }
	void SetWidth(const float& width)				{ m_size.x = width;  }
	void SetHeight(const float& height)				{ m_size.y = height; }

	const float& GetX() const      { return m_position.x; };
	const float& GetY() const      { return m_position.y; };
	const float& GetWidth() const  { return m_size.x; };
	const float& GetHeight() const { return m_size.y; };
	D2D_RECT_F GetRect() 
	{ 
		update();
		return rect; 
	}

	void update()
	{
		rect.left	= m_position.x - (m_size.x * 0.5f);
		rect.right	= m_position.x + (m_size.x * 0.5f);
		rect.top	= m_position.y - (m_size.y * 0.5f);
		rect.bottom = m_position.y + (m_size.y * 0.5f);
	}

	void update(const Vector2& v2) { update(v2.x, v2.y); }
	void update(const float& x, const float& y)
	{
		rect.left   = x - (m_size.x * 0.5f);
		rect.right  = x + (m_size.x * 0.5f);
		rect.top    = y - (m_size.y * 0.5f);
		rect.bottom = y + (m_size.y * 0.5f);
		
		m_position.x = x;
		m_position.y = y;
	}

	void operator=(const BoundingBox_2D& other)
	{
		rect			= other.rect;
		m_position.x    = other.m_position.x;
		m_position.y    = other.m_position.y;
		m_size.x		= other.m_size.x;
		m_size.y		= other.m_size.y;
	}

	void operator+=(const Vector2& v2)
	{
		m_position.x += v2.x;
		m_position.y += v2.y;

		rect.left    += v2.x;
		rect.right   += v2.x;
		rect.top     += v2.y;
		rect.bottom  += v2.y;
	}
	void operator+=(const BoundingBox_2D& other)
	{
		m_position.x += other.m_position.x;
		m_position.y += other.m_position.y;

		rect.left    += other.m_position.x;
		rect.right   += other.m_position.x;
		rect.top     += other.m_position.y;
		rect.bottom  += other.m_position.y;
	}

	void operator-=(const Vector2& v2)
	{
		m_position.x -= v2.x;
		m_position.y -= v2.y;

		rect.left    -= v2.x;
		rect.right   -= v2.x;
		rect.top     -= v2.y;
		rect.bottom  -= v2.y;
	}
	void operator-=(const BoundingBox_2D& other)
	{
		m_position.x -= other.m_position.x;
		m_position.y -= other.m_position.y;

		rect.left    -= other.m_position.x;
		rect.right   -= other.m_position.x;
		rect.top     -= other.m_position.y;
		rect.bottom  -= other.m_position.y;
	}

	void operator*=(const Vector2& v2)
	{
		m_position.x *= v2.x;
		m_position.y *= v2.y;

		rect.left    *= v2.x;
		rect.right   *= v2.x;
		rect.top     *= v2.y;
		rect.bottom  *= v2.y;
	}
	void operator*=(const BoundingBox_2D& other)
	{
		m_position.x *= other.m_position.x;
		m_position.y *= other.m_position.y;

		rect.left    *= other.m_position.x;
		rect.right   *= other.m_position.x;
		rect.top     *= other.m_position.y;
		rect.bottom  *= other.m_position.y;
	}

	BoundingBox_2D operator+(const Vector2& v2)
	{
		BoundingBox_2D box;
		box.m_position.x = m_position.x + v2.x;
		box.m_position.y = m_position.y + v2.y;

		box.rect.left    = rect.left    + v2.x;
		box.rect.right   = rect.right   + v2.x;
		box.rect.top     = rect.top     + v2.y;
		box.rect.bottom  = rect.bottom  + v2.y;
		return box;
	}
	BoundingBox_2D operator+(const BoundingBox_2D& other)
	{
		BoundingBox_2D box;
		box.m_position.x = m_position.x + other.m_position.x;
		box.m_position.y = m_position.y + other.m_position.y;

		box.rect.left    = rect.left    + other.m_position.x;
		box.rect.right   = rect.right   + other.m_position.x;
		box.rect.top     = rect.top     + other.m_position.y;
		box.rect.bottom  = rect.bottom  + other.m_position.y;
		return box;
	}


};

inline static D2D_RECT_F operator+(const D2D_RECT_F& a, const D2D_RECT_F& b)
{
	return D2D_RECT_F{a.left + b.left, a.top + b.top, a.right + b.right, a.bottom + b.bottom};
}
inline static D2D_RECT_F operator-(const D2D_RECT_F& a, const D2D_RECT_F& b)
{
	return D2D_RECT_F{ a.left - b.left, a.top - b.top, a.right - b.right, a.bottom - b.bottom };
}
inline static D2D_RECT_F operator*(const D2D_RECT_F& a, const D2D_RECT_F& b)
{
	return D2D_RECT_F{ a.left * b.left, a.top * b.top, a.right * b.right, a.bottom * b.bottom };
}

namespace Radar
{
	static bool isImage(const std::wstring& path)
	{
		TCHAR exe[10];
		_wsplitpath_s(path.c_str(), NULL,	  NULL,	      NULL,  NULL,    NULL,    NULL,		exe, 10);
						//path		dirve drivesize  directory   dirSize  fileName  filenameSize exe  exesize
		if (!wcscmp(exe, TEXT(".png"))) return true;
		if (!wcscmp(exe, TEXT(".jpg")))	return true;
		if (!wcscmp(exe, TEXT(".bmp")))	return true;
		if (!wcscmp(exe, TEXT(".PNG"))) return true;
		if (!wcscmp(exe, TEXT(".JPG")))	return true;
		if (!wcscmp(exe, TEXT(".BMP")))	return true;
		return false;
	}

	static bool GetFileName(std::wstring& output, const std::wstring& path)
	{
		output.clear();
		TCHAR name[100];
		_wsplitpath_s(path.c_str(), NULL,	  NULL,	      NULL,  NULL, name,    100, NULL, NULL);
						//path		dirve drivesize  directory   dirSize  fileName  filenameSize exe  exesize
		//_wsplitpath(path.c_str(), NULL, NULL, name, NULL);
		output = name;
		return !(output.empty());
	}

	static std::vector<std::wstring> FilePathRead(const std::wstring& path)
	{
		std::vector<std::wstring> vArchivePath;

		WIN32_FIND_DATA fd;
		std::wstring start_path = path + std::wstring(TEXT("*.*"));
		HANDLE hFindHande = FindFirstFile(start_path.c_str(), &fd);

		//없으면 끝
		//if (hFindHande != INVALID_HANDLE_VALUE) return vArchivePath;

		while (FindNextFile(hFindHande, &fd))
		{
			auto index = start_path.find(TEXT("*"));

			std::wstring new_path;
			new_path.reserve(start_path.size());

			auto count = 0;
			auto size = (start_path.size() - 3);
			for (auto i = 0U; i < size; ++i)
			{
				if (index == i) count += 3;
				new_path.push_back(start_path[i + count]);
			}

			if (!std::wstring(fd.cFileName).compare(TEXT("..")))
				continue;

			std::wstring save_path = new_path + std::wstring(fd.cFileName);

			auto attribute = fd.dwFileAttributes;


			if (attribute | FILE_ATTRIBUTE_ARCHIVE)
				vArchivePath.push_back(save_path);

		}

		FindClose(hFindHande);

		return vArchivePath;
	}



}

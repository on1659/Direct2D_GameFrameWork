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

	void set(const T& x, const T& y) { this->x = x; this->y = y; }

	//const를 붙이는건 other은 수정하지 않는거니깐 붙이는거
	Vector2& operator+(const Vector2& other) { auto v2 = Vector2(x + other.x, y + other.y); return v2; }
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

	float dot(Vector2 other) const
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

class BoundingBox_2D
{

public:
	D2D_RECT_F     rect;

	float			m_cx;
	float			m_cy;
	float			m_width;
	float			m_height;

public:
		
	
	void SetBoxLTRD(const float& left, const float& top, const float& right, const float& bot)
	{
		rect.left	= left; 
		rect.right	= right;
		rect.top	= top; 
		rect.bottom = bot;
		m_width		= right - left;
		m_height	= bot - top;
		m_cx		= left + (m_width * 0.5f);
		m_cy		= top  + (m_height * 0.5f);
	}

	void SetBoxCenter(const float& cx, const float& cy, const float& w, const float& h)
	{
		m_width		  = w;
		m_height	  = h;
		m_cx		  = cx;
		m_cy		  = cy;

		rect.left	  = cx - (w * 0.5f);
		rect.right	  = cx + (w * 0.5f);
		rect.top	  = cy - (h * 0.5f);
		rect.bottom	  = cy + (h * 0.5f);
	}

	bool collision(const BoundingBox_2D& other)
	{
		if (rect.left > other.rect.right)return false;
		if (rect.right < other.rect.left)return false;
		if (rect.top > other.rect.bottom)return false;
		if (rect.bottom < other.rect.top)return false;
		return true;
	}

	bool contains(const float& x, const float& y)
	{
		return rect.left < rect.right 
			&& rect.top < rect.bottom
			&& rect.left <= x && x < rect.right 
			&& rect.top <= y  && y < rect.bottom;
	}

	void offset(const float& cx, const float& cy)
	{
		m_cx = m_cx + cx;
		m_cy = m_cy + cy;

		rect.left    += cx;
		rect.right   += cx;
		rect.top     += cy;
		rect.bottom  += cy;

	}

	void Set(const float& cx, const float& cy) { update(cx, cy); }
	void SetX(const float& cx)
	{
		m_cx = cx;
		rect.left = cx - (m_width * 0.5f);
		rect.right = cx + (m_width * 0.5f);
	}
	void SetY(const float& cy)
	{
		m_cy = cy;
		rect.top = cy - (m_height * 0.5f);
		rect.bottom = cy + (m_height * 0.5f);
	}
	void SetWidth(const float& width) {	m_width = width; }
	void SetHeight(const float& height) { m_height = height; }

	float GetX() const      { return m_cx; };
	float GetY() const      { return m_cy; };
	float GetWidth() const  { return m_width; };
	float GetHeight() const { return m_height; };

	void update(const float& cx, const float& cy)
	{
		rect.left   = cx - (m_width * 0.5f);
		rect.right  = cx + (m_width * 0.5f);
		rect.top    = cy - (m_height * 0.5f);
		rect.bottom = cy + (m_height * 0.5f);
		
		m_cx = cx;
		m_cy = cy;
	}

	void operator=(const BoundingBox_2D& other)
	{
		rect     = other.rect;
		m_cx     = other.m_cx;
		m_cy     = other.m_cy;
		m_width  = other.m_width;
		m_height = other.m_height;
	}

	void operator+=(const BoundingBox_2D& other)
	{
			m_cx	+= other.m_cx;
			m_cy	+= other.m_cy;

		rect.left   += other.m_cx;
		rect.right  += other.m_cx;
		rect.top    += other.m_cy;
		rect.bottom += other.m_cy;
	}

	BoundingBox_2D operator+(const BoundingBox_2D& other)
	{
		BoundingBox_2D box;
		box.m_cx = m_cx + other.m_cx;
		box.m_cy = m_cy + other.m_cy;

		box.rect.left    = rect.left    + other.m_cx;
		box.rect.right   = rect.right   + other.m_cx;
		box.rect.top     = rect.top     + other.m_cy;
		box.rect.bottom  = rect.bottom  + other.m_cy;
		return box;
	}


};

namespace Radar
{
	static bool isImage(const std::wstring& path)
	{
		TCHAR exe[10];
		_wsplitpath(path.c_str(), NULL, NULL, NULL, exe);
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
		_wsplitpath(path.c_str(), NULL, NULL, name, NULL);
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

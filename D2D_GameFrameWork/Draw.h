#pragma once

#include "stdafx.h"

class Draw
{	
public:
	static inline void drawRect(ID2D1HwndRenderTarget *pd2dRenderTarget, const float& left, const float& top, const float& width, const float& height, ID2D1Brush *bursh)
	{
		pd2dRenderTarget->FillRectangle(RectF(left, top, left + width, top + height), bursh);
	}

	static  inline void drawText(ID2D1HwndRenderTarget *pd2dRenderTarget, const D2D1_RECT_F& rect, const FONT_FORMAT& font, ID2D1SolidColorBrush* color, TCHAR *format, ...)
	{
		va_list arg;
		va_start(arg, format);
		TCHAR buf[500] = { NULL };
		vswprintf_s(buf, format, arg);
		va_end(arg);

		pd2dRenderTarget->DrawTextW(buf, wcslen(format), MY_FONT(font), rect, color);

	}
	void static drawText(ID2D1HwndRenderTarget *pd2dRenderTarget, const D2D1_RECT_F& rect, const FONT_FORMAT& font, const MyColorEnum color, TCHAR *format, ...)
	{
		va_list arg;
		va_start(arg, format);
		TCHAR buf[500] = { NULL };
		vswprintf_s(buf, format, arg);
		va_end(arg);

		pd2dRenderTarget->DrawTextW(buf, wcslen(buf), MY_FONT(font), rect, MY_COLOR(color));
	}
};

//IDWriteTextFormat** Draw::gppTextFormat = nullptr;
//int Draw::gnTextFormat = 0;
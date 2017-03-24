#pragma once

// No Use
class Draw
{	
public:
	static inline void drawRect(ID2D1HwndRenderTarget *pd2dRenderTarget,const float& left, const float& top, const float& width, const float& height, ID2D1Brush *bursh)
	{
		pd2dRenderTarget->FillRectangle(RectF(left, top, left + width, top + height), bursh);
	}

};


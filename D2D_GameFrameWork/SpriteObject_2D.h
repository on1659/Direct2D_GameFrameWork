#pragma once

#include "GraphicObject_2D.h"

class CSpriteObject_2D :public CGraphicObject_2D
{

//처음
protected:
	float						m_frameFPS{ 10.0f };
	int							m_frameCount{ 1 };
	float						m_frameWidth{ 0.0f };


//상시
protected:
	float						m_frameCountHeight{ 0.0f };
	float						m_frameLeft{ 0.0f };
	float						m_frameTop{ 0.0f };

	D2D_RECT_F					m_rSprite;


public:

	CSpriteObject_2D(const std::string& name = "SpriteObject_2D");

	virtual ~CSpriteObject_2D();

	virtual void Create(const std::wstring& name, const float& cx, const float& cy, const float& width = 0.0f, const float& heigh = 0.0f, float frameFPS = 10.0f, int frameCount = 1.0f, int frameCountHeight =1.0f);

	virtual void Render(ID2D1HwndRenderTarget *pd2dRenderTarget) override;

	void OnSpriteUpdate();

	void SetSpriteHeight(const float& n) { m_frameCountHeight = n; }

	void SetSprite(float frameFPS, int frameCount, int frameCountHeight);



};
#pragma once

#include "GraphicObject_2D.h"

class CSpriteObject_2D :public CGraphicObject_2D
{

//처음
protected:
	float						m_frameFPS{ 10.0f };
	UINT						m_frameCount{ 1 };
	float						m_frameWidth{ 0.0f };


//상시
protected:
	UINT						m_frameCountHeight{ 0U };
	float						m_frameLeft{ 0.0f };
	float						m_frameTop{ 0.0f };

	D2D_RECT_F					m_rSprite;


public:

	CSpriteObject_2D(const std::string& name = "SpriteObject_2D");

	CSpriteObject_2D(const std::wstring& name);

	virtual ~CSpriteObject_2D();

	virtual void Create(const std::wstring& name, const float& x, const float& y, const float& width, const float& heigh, const float& frameFPS = 10.0f, const UINT& frameCount = 1U, const UINT& frameCountHeight = 1U);

	virtual void Render(ID2D1HwndRenderTarget *pd2dRenderTarget) override;

	void OnSpriteUpdate();

	void SetSpriteHeight(const UINT& pivot) { m_frameCountHeight = pivot; }

	void SetSprite(const float& frameFPS, const UINT& frameCount,const UINT& frameCountHeight = 1U);
	void SetSprite(const std::wstring& name, const float& frameFPS, const UINT& frameCount,const UINT& frameCountHeight = 1U);


};
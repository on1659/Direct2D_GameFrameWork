#pragma once

#include "stdafx.h"
#include "SpriteObject_2D.h"

CSpriteObject_2D::CSpriteObject_2D(const std::string& name) : CGraphicObject_2D(name)
{
}


CSpriteObject_2D::~CSpriteObject_2D()
{
};

/*
	cx,cy,width,height �� ĳ������ ��ġ.
	frameFPS    : �ִϸ��̼� ��ȯ �ӵ��Դϴ�.
	frameCount  : ��������Ʈ�� ������ �̹��� �� ũ���Դϴ�.
	frameHeight : ��������Ʈ�� ���� �̹��� ���� �Դϴ�.
*/

void CSpriteObject_2D::Create(const std::wstring& name, const float& cx, const float& cy, const float& width, const float& heigh, float frameFPS, int frameCount, int frameCountHeight)
{
	CGraphicObject_2D::Create(name, cx, cy, width, heigh);

	m_frameFPS = 1 / frameFPS;
	m_frameCount = frameCount;
	m_imgWidth = m_imgWidth / frameCount;
	m_imgHeight = m_imgHeight / frameCountHeight;

}

void CSpriteObject_2D::Render(ID2D1HwndRenderTarget * pd2dRenderTarget)
{
	OnSpriteUpdate();

	RENDERMGR_2D->Render(pd2dRenderTarget, m_imageName, m_BoundingBox.rect, m_alpha, m_rSprite);
}

void CSpriteObject_2D::SetSprite(float frameFPS, int frameCount, int frameCountHeight)
{
	m_frameFPS = 1 / frameFPS;
	m_frameCount = frameCount;
	m_imgWidth = m_imgWidth / frameCount;
	m_imgHeight = m_imgHeight / frameCountHeight;

	SetWidth(m_imgWidth);
	SetHeight(m_imgHeight);
}



void CSpriteObject_2D::OnSpriteUpdate()
{
	m_frameLeft = m_imgWidth  * (int)m_frameWidth;
	m_frameTop  = m_imgHeight * (int)m_frameCountHeight;

	m_frameWidth += m_frameFPS;

	if (m_frameWidth >= m_frameCount)
	{
		m_frameWidth = 0;

	}

	m_rSprite.left		= m_frameLeft;
	m_rSprite.right		= m_frameLeft + m_imgWidth;
	m_rSprite.top		= m_frameTop;
	m_rSprite.bottom	= m_frameTop + m_imgHeight;

}
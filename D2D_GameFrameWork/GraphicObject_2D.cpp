
#include "stdafx.h"
#include "GraphicObject_2D.h"
#include "RenderManager_2D.h"
#include "Util.h"


CGraphicObject_2D::CGraphicObject_2D(const std::string& name) : CObject_D2D(name)
{
}

CGraphicObject_2D::~CGraphicObject_2D()
{
}

void CGraphicObject_2D::Create(const std::wstring & name, const float & cx, const float & cy, const float & width, const float & height)
{
	m_imageName = name;

	m_imgWidth  = (float)CRenderManager_2D::GetInstance()->GetImage(m_imageName)->GetSize().width;
	m_imgHeight = (float)CRenderManager_2D::GetInstance()->GetImage(m_imageName)->GetSize().height;

	m_BoundingBox.m_cx = cx;
	m_BoundingBox.m_cy = cy;

	m_BoundingBox.m_width = width;
	m_BoundingBox.m_height = height;

	if (m_BoundingBox.m_width == 0)  m_BoundingBox.m_width = m_imgWidth;
	if (m_BoundingBox.m_height == 0) m_BoundingBox.m_height = m_imgHeight;

	m_BoundingBox.SetBoxCenter(m_BoundingBox.m_cx, m_BoundingBox.m_cy, m_BoundingBox.m_width, m_BoundingBox.m_height);

}

void CGraphicObject_2D::SetPosition(float cx, float cy, float width, float height)
{
	m_BoundingBox.SetBoxCenter(m_BoundingBox.m_cx, m_BoundingBox.m_cy, m_BoundingBox.m_width, m_BoundingBox.m_height);
}

void CGraphicObject_2D::Render(ID2D1HwndRenderTarget *pd2dRenderTarget)
{
	RENDERMGR_2D->Render(pd2dRenderTarget, m_imageName, m_BoundingBox.rect, m_alpha);
}

void CGraphicObject_2D::RenderBoundingBox(ID2D1HwndRenderTarget* pd2dRenderTarget)
{
	//pd2dRenderTarget->DrawRectangle(m_BoundingBox.rect, MyColor::GetColor(MyColorEnum::Red));
}

void CGraphicObject_2D::SetPosition(const float& cx, const float& cy)
{
	m_BoundingBox.SetBoxCenter(m_BoundingBox.m_cx, m_BoundingBox.m_cy, m_BoundingBox.m_width, m_BoundingBox.m_height);
}

void CGraphicObject_2D::SetBoundingBox(const BoundingBox_2D & boundingBox)
{
	m_BoundingBox = boundingBox;
}

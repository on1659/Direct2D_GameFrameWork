
#include "stdafx.h"
#include "GraphicObject_2D.h"
#include "RenderManager_2D.h"
#include "Util.h"


CGraphicObject_2D::CGraphicObject_2D(const std::string& name) : CObject_D2D(name)
{
}

CGraphicObject_2D::CGraphicObject_2D(const std::wstring& name)
{
	m_imageName = name;
	std::string str_name;
	str_name.assign(name.begin(), name.end());
	CObject_D2D::CObject_D2D(str_name);
}

CGraphicObject_2D::~CGraphicObject_2D()
{
}

void CGraphicObject_2D::Create(const std::wstring & name, const Vector2 & position, const Vector2 & size)
{
	CGraphicObject_2D::Create(name, position.x, position.y, size.x, size.y);
}

void CGraphicObject_2D::Create(const std::wstring & name, const float &x, const float &y, const float & width, const float & height)
{
	m_imageName = name;

	m_imgWidth  = (float)CRenderManager_2D::GetInstance()->GetImage(m_imageName)->GetSize().width;
	m_imgHeight = (float)CRenderManager_2D::GetInstance()->GetImage(m_imageName)->GetSize().height;

	m_bcBoundingBox.SetX(x);
	m_bcBoundingBox.SetY(y);

	m_bcBoundingBox.SetWidth(width);
	m_bcBoundingBox.SetHeight(height);

	if ( width  == 0 || width  >= 0xFFFF )  m_bcBoundingBox.SetWidth(m_imgWidth);
	if ( height == 0 || height >= 0xFFFF )  m_bcBoundingBox.SetHeight(m_imgHeight);

	m_bcBoundingBox.SetBoxCenter(m_bcBoundingBox.m_position, m_bcBoundingBox.m_size);

}

void CGraphicObject_2D::SetPosition(const float&  x, const float&  y, const float&  width, const float&  height)
{
	m_bcBoundingBox.SetBoxCenter(x, y, width, height);
}

void CGraphicObject_2D::Render(ID2D1HwndRenderTarget *pd2dRenderTarget)
{
	RENDERMGR_2D->Render(pd2dRenderTarget, m_imageName, m_bcBoundingBox.rect, m_alpha);
}

void CGraphicObject_2D::RenderBoundingBox(ID2D1HwndRenderTarget* pd2dRenderTarget)
{
	//pd2dRenderTarget->DrawRectangle(m_bcBoundingBox.rect, MyColor::GetColor(MyColorEnum::Red));
}

void CGraphicObject_2D::SetPosition(const float& x, const float& y)
{
	m_bcBoundingBox.SetBoxCenter(x, y);
}

void CGraphicObject_2D::SetBoundingBox(const BoundingBox_2D & boundingBox)
{
	m_bcBoundingBox = boundingBox;
}

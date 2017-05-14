#include "stdafx.h"
#include "MapObject.h"


CMapObject::CMapObject(const std::string name) : CGraphicObject_2D(name)
{
}


CMapObject::~CMapObject()
{
}

void CMapObject::Render(ID2D1HwndRenderTarget * pd2dRenderTarget, CCamera_2D * pCamera)
{
	if (pCamera->isVisible(GetRect()))return;
	Render(pd2dRenderTarget, pCamera->GetRect());
}

void CMapObject::Render(ID2D1HwndRenderTarget * pd2dRenderTarget, const D2D_RECT_F rtCamera)
{
	auto myRect = GetRect();
	auto rtCamRect = rtCamera;
	auto rtCameraWorldRect = myRect - rtCamRect;

	D2D_RECT_F rtPos{ 0.0f, 0.0f, 0.0f, 0.0f };
	rtPos.left   = min(0.0f, rtCameraWorldRect.left);
	rtPos.top    = min(0.0f, rtCameraWorldRect.top);
	rtPos.right	 = WIDTH;// min(WIDTH, rtCameraWorldRect.left + GetWidth());
	rtPos.bottom = HEIGHT;// min(HEIGHT, rtCameraWorldRect.top + GetHeight());


	D2D_RECT_F rtSrc{ 0.0f, 0.0f, 0.0f, 0.0f };

	rtSrc.right  = min(rtSrc.left + (rtPos.right - rtPos.left), GetWidth());// (pCamera->GetWidth(), rtPos.left + GetWidth());
	rtSrc.bottom = min(rtSrc.top + (rtPos.bottom - rtPos.top), GetHeight());//min(pCamera->GetHeight(), rtPos.top + GetHeight());


	RENDERMGR_2D->Render(pd2dRenderTarget, m_imageName, rtPos, m_alpha, rtSrc);
}

#pragma once
class CMapObject : public CGraphicObject_2D
{
public:
	CMapObject(const std::string name = "MapObject");

	~CMapObject();

	virtual void Render(ID2D1HwndRenderTarget *pd2dRenderTarget, CCamera_2D *pCamera);

	virtual void Render(ID2D1HwndRenderTarget *pd2dRenderTarget, const D2D_RECT_F rtCamera);

};


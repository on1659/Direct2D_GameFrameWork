#pragma once

class BoundingBox_2D;

class CGraphicObject_2D : public CObject_D2D
{
protected:
	//처음한번
	std::wstring			m_imageName;

	//상시
	BoundingBox_2D			m_BoundingBox;


	float					m_imgWidth{0.0f};
	float					m_imgHeight{0.0f};

	float					m_alpha{ 1.0f };


public:

	CGraphicObject_2D(const std::string& name = "GraphicObject");

	virtual ~CGraphicObject_2D();

	virtual void Create(const std::wstring& name, const float& cx, const float& cy, const float& width = 0.0f, const float& heigh = 0.0f);

	virtual void Render(ID2D1HwndRenderTarget *pd2dRenderTarget);

	virtual void RenderBoundingBox(ID2D1HwndRenderTarget *pd2dRenderTarget);

	virtual void OnUpdate(const float& fTimeElapsed) {}

	virtual void SetPosition(float cx, float cy, float width, float height);


	//Set
	void SetX(const float& cx){ m_BoundingBox.m_cx = cx; }
	void SetY(const float& cy){ m_BoundingBox.m_cy = cy; }
	void SetWidth(float width){ m_BoundingBox.m_width = width; }
	void SetHeight(float height){ m_BoundingBox.m_height = height; }
	void SetPosition(const float& cx, const float& cy);
	void SetAplha(const float& alpha = 1.0f) { m_alpha = alpha; }

	//Get

	float GetX()	  const { return m_BoundingBox.m_cx; }
	float GetY()	  const { return m_BoundingBox.m_cy; }
	float GetWidth()  const { return m_BoundingBox.m_width; }
	float GetHeight() const { return m_BoundingBox.m_height; }

	BoundingBox_2D CGraphicObject_2D::GetBoundingBox() const {	return m_BoundingBox; }
};

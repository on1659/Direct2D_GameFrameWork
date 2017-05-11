#pragma once

class BoundingBox_2D;

class CGraphicObject_2D : public CObject_D2D
{

public:

	CGraphicObject_2D(const std::string& name = "GraphicObject");

	virtual ~CGraphicObject_2D();

	virtual void Create(const std::wstring& name, const float& cx, const float& cy, const float& width = 0.0f, const float& heigh = 0.0f);

	virtual void Render(ID2D1HwndRenderTarget *pd2dRenderTarget);

	virtual void RenderBoundingBox(ID2D1HwndRenderTarget *pd2dRenderTarget);

	virtual void OnUpdate(const float& fTimeElapsed) {}

	virtual void SetPosition(float cx, float cy, float width, float height);

	//Set
	void SetImageName(const std::wstring& name) { m_imageName = name; }
	void SetX(const float& cx){ m_BoundingBox.m_cx = cx; }
	void SetY(const float& cy){ m_BoundingBox.m_cy = cy; }
	void SetWidth(const float& width){ m_BoundingBox.m_width = width; }
	void SetHeight(const float& height){ m_BoundingBox.m_height = height; }
	void SetPosition(const float& cx, const float& cy);
	void SetAplha(const float& alpha = 1.0f) { m_alpha = alpha; }
	void SetBoundingBox(const BoundingBox_2D& boundingBox);

	//Get
	float GetX()	  const { return m_BoundingBox.m_cx; }
	float GetY()	  const { return m_BoundingBox.m_cy; }
	float GetWidth()  const { return m_BoundingBox.m_width; }
	float GetHeight() const { return m_BoundingBox.m_height; }

	BoundingBox_2D CGraphicObject_2D::GetBoundingBox() const {	return m_BoundingBox; }

protected:
	//ó���ѹ�
	std::wstring			m_imageName;

	//���
	BoundingBox_2D			m_BoundingBox;


	float					m_imgWidth{0.0f};
	float					m_imgHeight{0.0f};

	float					m_alpha{ 1.0f };

};

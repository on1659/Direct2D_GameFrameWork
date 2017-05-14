#pragma once

class BoundingBox_2D;
class CCamera_2D;

class CGraphicObject_2D : public CObject_D2D
{

public:

	CGraphicObject_2D(const std::string& name = "GraphicObject");

	CGraphicObject_2D(const std::wstring& name);

	virtual ~CGraphicObject_2D();

	virtual void Create(const std::wstring& name, const Vector2& position, const Vector2& size = Vector2(0.0f, 0.0f));

	virtual void Create(const std::wstring& name, const float& x, const float& y, const float& width = 0.0f, const float& heigh = 0.0f);

	virtual void Render(ID2D1HwndRenderTarget *pd2dRenderTarget);

	virtual void Render(ID2D1HwndRenderTarget *pd2dRenderTarget, CCamera_2D *pCamera);

	virtual void Render(ID2D1HwndRenderTarget *pd2dRenderTarget, const D2D_RECT_F rtCamera);

	virtual void RenderBoundingBox(ID2D1HwndRenderTarget *pd2dRenderTarget);

	virtual void OnUpdate(const float& fTimeElapsed) {}

	virtual void SetPosition(const float&  x, const float&  y, const float&  width, const float&  height);

	//Set
	void SetImageName(const std::wstring& name)				{ m_imageName = name; }
	void SetX(const float& x)								{ m_bcBoundingBox.SetX(x);}
	void SetY(const float& y)								{ m_bcBoundingBox.SetY(y); }
	const Vector2& GetPosition() const						{ return m_bcBoundingBox.GetPosition(); }

	void SetWidth(const float& width)						{ m_bcBoundingBox.SetWidth(width); }
	void SetHeight(const float& height)						{ m_bcBoundingBox.SetHeight(height); }
	const Vector2& GetSize() const							{ return m_bcBoundingBox.GetSize(); }


	void SetAplha(const float& alpha = 1.0f)				{ m_alpha = alpha; }
	void SetPosition(const float& x, const float& y);
	void SetBoundingBox(const BoundingBox_2D& boundingBox);

	void SetLTRB(const float& left, const float& top, const float& right= 0xFFFF, const float& bottom = 0xFFFF)
	{
		int width  = 0;
		int height = 0;
		if ( right == 0xFFFF)  width = GetWidth();
		if (bottom == 0xFFFF) height = GetHeight();
		m_bcBoundingBox.SetBoxLTRD(left, top, (left + width), (top +height));
	}
	void SetLTRB(const Vector2& left_top, const Vector2& right_bottom) 
	{
		SetLTRB(left_top.x, left_top.y, right_bottom.x, right_bottom.y);
	}


	//Get
	float GetX()	  const { return m_bcBoundingBox.GetX();		}
	float GetY()	  const { return m_bcBoundingBox.GetY();		}
	float GetWidth()  const { return m_bcBoundingBox.GetWidth();  }
	float GetHeight() const { return m_bcBoundingBox.GetHeight(); }
	D2D_RECT_F& GetRect() { return m_bcBoundingBox.GetRect(); }

	BoundingBox_2D CGraphicObject_2D::GetBoundingBox() const {	return m_bcBoundingBox; }

protected:
	//처음한번
	std::wstring			m_imageName;

	//상시
	BoundingBox_2D			m_bcBoundingBox;


	float					m_imgWidth{0.0f};
	float					m_imgHeight{0.0f};

	float					m_alpha{ 1.0f };


};

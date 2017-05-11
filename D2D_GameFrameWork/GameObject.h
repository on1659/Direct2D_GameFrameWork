#pragma once


class CGameObject : public CObject_D2D
{

public:

	CGameObject(const std::string& name = "GameObject");

	~CGameObject();

	bool Release() override;

	virtual void Render(ID2D1HwndRenderTarget *pd2dRenderTarget);

	virtual void RenderBoundingBox(ID2D1HwndRenderTarget *pd2dRenderTarget);

	virtual void OnUpdate(const float& frame_time);

	//Set
	void push_name(const std::wstring& name);
	void SetX(const float& cx)								 { m_bcBoundingBox.SetX(cx);}
	void SetY(const float& cy)								 { m_bcBoundingBox.SetY(cy);}
	void set_width(const float& width)						 { m_bcBoundingBox.SetWidth(width);}
	void SetHeight(const float& height)						 { m_bcBoundingBox.SetHeight(height);}
	void SetPosition(const float& cx, const float& cy)		 { m_bcBoundingBox.Set(cx, cy); }
	void SetAplha(const float& alpha = 1.0f)				 { SetAplha(alpha); }
	void SetComponent(std::unique_ptr<Component>& pComponet) { m_vComponent.push_back(std::move(pComponet)); }
	
	//Get
	virtual float GetX()	  const { return m_bcBoundingBox.GetX();	   }
	virtual float GetY()	  const { return m_bcBoundingBox.GetY(); 	   }
	virtual float GetWidth()  const { return m_bcBoundingBox.GetWidth();  }
	virtual float GetHeight() const { return m_bcBoundingBox.GetHeight(); }

private:
	BoundingBox_2D									 m_bcBoundingBox;
	std::vector<CSpriteObject_2D>					 m_vSprite;
	std::vector<std::unique_ptr<Component>>			 m_vComponent;
	
};


#pragma once


class CGameObject : public CObject_D2D
{

public:

	CGameObject(const std::string& name = "GameObject");

	~CGameObject();

	bool Release() override;

	virtual void Render(ID2D1HwndRenderTarget *pd2dRenderTarget);
	virtual void RenderBoundingBox(ID2D1HwndRenderTarget *pd2dRenderTarget);
	virtual void Update(const float& frame_time);
	virtual void Move(const float& x, const float& y);

	//Set
	void Set(const float& x, const float& y, const float& w, const float& h) 
	{
		m_bcBoundingBox.Set(x, y, w, h);
	}
	void Set(const Vector2& pos, const Vector2& size)		
	{
		m_bcBoundingBox.Set(pos.x, pos.y, size.x, size.y);
	}

	void PushName(const std::wstring& name);
	void PushSprite(const CSpriteObject_2D& sprite);

	void SetX(const float& x)								 { m_bcBoundingBox.SetX(x);}
	void SetY(const float& y)								 { m_bcBoundingBox.SetY(y);}
	void SetPosition(const Vector2& v2)						 { SetPosition(v2.x, v2.y); }
	void SetPosition(const float& x, const float& y)		 { m_bcBoundingBox.Set(x, y); }
	
	void SetWidth(const float& width)						 { m_bcBoundingBox.SetWidth(width);}
	void SetHeight(const float& height)						 { m_bcBoundingBox.SetHeight(height);}
	void SetSize(const Vector2& v2)							 { m_bcBoundingBox.SetSize(v2); }
	void SetSize(const float& w, const float& h)			 { m_bcBoundingBox.SetSize(w, h); }
	
	void SetAplha(const float& alpha = 1.0f)				 { SetAplha(alpha); }
	
	void SetComponent(std::unique_ptr<Component> pComponet) 
	{
		pComponet->SetGameObject(this);
		m_vComponent.push_back(std::move(pComponet)); 
	}

	//Get
	const float&   GetX() const { return m_bcBoundingBox.GetX(); }
	const float&   GetY() const { return m_bcBoundingBox.GetY(); }
	const Vector2& GetPosition() const { return m_bcBoundingBox.GetPosition(); }

	const float& GetWidth()  const { return m_bcBoundingBox.GetWidth();  }
	const float& GetHeight() const { return m_bcBoundingBox.GetHeight(); }
	const Vector2& GetSize() const { return m_bcBoundingBox.GetSize();   }

private:
	BoundingBox_2D									 m_bcBoundingBox;
	std::vector<CSpriteObject_2D>					 m_vSprite;
	std::vector<std::unique_ptr<Component>>			 m_vComponent;
};


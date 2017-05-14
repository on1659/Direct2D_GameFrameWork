#pragma once

class CSceneMain : public CSceneState
{
public:
	CSceneMain(const std::string& name = "MainScene");

	~CSceneMain();

	bool Release() override;

	bool Start(HINSTANCE hInstance, HWND hWnd, Microsoft::WRL::ComPtr<ID2D1Factory2> pd2dFactory2, ID2D1HwndRenderTarget *pd2dRenderTarget = nullptr);

	virtual void Render(ID2D1HwndRenderTarget *pd2dRenderTarget);

	virtual void Update(const float& fTime);

	virtual void LateUpdate(const float& fTime);

	virtual void FixedUpdate(const float& fTime);

private:
	CCamera_2D			m_Camera;
	CGraphicObject_2D	*m_BackGround;
};


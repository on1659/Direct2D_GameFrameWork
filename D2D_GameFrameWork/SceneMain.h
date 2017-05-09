#pragma once

class CSceneMain : public CSceneState
{
public:
	CSceneMain(const std::string& name = "MainScene");

	~CSceneMain();

	virtual void enter(HINSTANCE hInstance, HWND hWnd, Microsoft::WRL::ComPtr<ID2D1Factory2> pd2dFactory2, ID2D1HwndRenderTarget *pd2dRenderTarget = nullptr);

	virtual void exit();

	virtual void Render(ID2D1HwndRenderTarget *pd2dRenderTarget);

	virtual void Update(const float& fTime);

	virtual void LateUpdate(const float& fTime);

	virtual void FixedUpdate(const float& fTime);

private:

	Vector2			playerPos;
	int				player_size;

	CSpriteObject_2D	sprite;

};


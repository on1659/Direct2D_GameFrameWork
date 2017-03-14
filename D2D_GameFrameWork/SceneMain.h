#pragma once

class CSceneMain : public CSceneState
{
public:
	CSceneMain(const std::string& name = "MainScene");

	~CSceneMain();

	virtual void enter(HINSTANCE hInstance, HWND hWnd, ID2D1HwndRenderTarget *pd2dRenderTarget = nullptr);

	virtual void exit();

	virtual void Render(ID2D1HwndRenderTarget *pd2dRenderTarget);

	virtual void Update(const float& fTime);

	virtual void FixedUpdate(const float& fTime);

private:

	Radar::Vector2 playerPos;
	int				player_size;
	Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> whilte_brush;
	Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> black_brush;
	Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> red_brush;

};


#include "stdafx.h"
#include "SceneMain.h"


CSceneMain::CSceneMain(const std::string& name) : CSceneState(name)
{

}


CSceneMain::~CSceneMain()
{

}


void CSceneMain::enter(HINSTANCE hInstance, HWND hWnd, ID2D1HwndRenderTarget *pd2dRenderTarget)
{
	m_hInstance = hInstance;
	m_hWnd = hWnd;

	playerPos.x = 45;
	playerPos.y = 45;

	player_size = 88;

	pd2dRenderTarget->CreateSolidColorBrush(ColorF{ ColorF::White }, &whilte_brush);
	pd2dRenderTarget->CreateSolidColorBrush(ColorF{ ColorF::Black }, &black_brush);
	pd2dRenderTarget->CreateSolidColorBrush(ColorF{ ColorF::Red }, &red_brush);

}
void CSceneMain::exit()
{
}
void CSceneMain::Render(ID2D1HwndRenderTarget *pd2dRenderTarget)
{
	//Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> hbr;
	//pd2dRenderTarget->CreateSolidColorBrush(ColorF{ ColorF::AliceBlue }, &hbr);
	//pd2dRenderTarget->FillRectangle(RectF(v2.x - 10.f, v2.y - 10.f, v2.x + 10.f, v2.y + 10.f), hbr.Get());


	int w = player_size;
	int h = player_size;
	
	for (int y = 0; y < 8;  ++y)
	{
		for (int x = 0; x < 8; ++x)
		{
			if( (x+y) & 1)
				pd2dRenderTarget->FillRectangle(RectF(x * w, y * h, (x+1) * w, (y+1) * h), whilte_brush.Get());
													 
			else									  
				pd2dRenderTarget->FillRectangle(RectF(x * w, y * h, (x + 1) * w, (y + 1) * h), black_brush.Get());
	
		}
	}

	D2D1_ELLIPSE ellispe;
	ellispe.point.x = playerPos.x;
	ellispe.point.y = playerPos.y;
	ellispe.radiusX = 10.0f;
	ellispe.radiusY = 10.0f;
	pd2dRenderTarget->FillEllipse(ellispe, red_brush.Get());

}
void CSceneMain::Update(const float& fTime)
{
	//radian = XMConvertToRadians(angle++);
	//v2.x = 50 + cos(radian) * 25.f;
	//v2.y = 50 + sin(radian) * 25.f;

	if (INPUT->KeyUp(YT_KEY::YK_W))	playerPos.y -= player_size;
	if (INPUT->KeyUp(YT_KEY::YK_A))	playerPos.x -= player_size;
	if (INPUT->KeyUp(YT_KEY::YK_S))	playerPos.y += player_size;
	if (INPUT->KeyUp(YT_KEY::YK_D))	playerPos.x += player_size;

	if (Input->KeyUp(YT_KEY::YK_F1))	player_size += 5;
	if (Input->KeyUp(YT_KEY::YK_F2))	player_size -= 5;

}
void CSceneMain::FixedUpdate(const float& fTime)
{


}
#include "stdafx.h"
#include "SceneMain.h"
#include "LoadD2DBitmap.h"
#include "GameFrameWork_D2D.h"
#include "Draw.h"

CSceneMain::CSceneMain(const std::string& name) : CSceneState(name)
{
}


CSceneMain::~CSceneMain()
{
}


void CSceneMain::enter(HINSTANCE hInstance, HWND hWnd, Microsoft::WRL::ComPtr<ID2D1Factory2> pd2dFactory2, ID2D1HwndRenderTarget *pd2dRenderTarget)
{
	CSceneState::enter(hInstance, hWnd, pd2dFactory2, pd2dRenderTarget);

	m_hInstance = hInstance;
	m_hWnd = hWnd;

	playerPos.x = 45;
	playerPos.y = 45;

	player_size = 88;



	sprite.Create(TEXT("윈드밀"), 200, 400, 200, 200, 1, 1);
	graphicObject.Create(TEXT("윈드밀"), 500, 400, 200, 200);
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
	float x, y;
	
	for (int iy = 0; iy < 8; ++iy)
	{
		for (int ix = 0; ix < 8; ++ix)
		{
			x = static_cast<float>(ix);
			y = static_cast<float>(iy);

			if ((ix + iy) & 1)
				pd2dRenderTarget->FillRectangle(RectF(x * w, y * h, (x+1) * w, (y+1) * h), MY_COLOR(MyColorEnum::White));
				//Draw::drawRect(pd2dRenderTarget, x *w, y * h, w, h, whilte_brush.Get());
			else									  
				pd2dRenderTarget->FillRectangle(RectF(x * w, y * h, (x + 1) * w, (y + 1) * h), MY_COLOR(MyColorEnum::Black));
	
		}
	}

	D2D1_ELLIPSE ellispe;
	ellispe.point.x = playerPos.x;
	ellispe.point.y = playerPos.y;
	ellispe.radiusX = 10.0f;
	ellispe.radiusY = 10.0f;
	pd2dRenderTarget->FillEllipse(ellispe, MY_COLOR(Red));

	sprite.Render(pd2dRenderTarget);

	D2D_RECT_F  pos{ 100.0f,100.0f,200.0f,200.0f };
	pd2dRenderTarget->DrawBitmap(RENDERMGR_2D->GetImage(TEXT("Player_Attack_Left")), &pos, 1.0f);

	pos.top += 100;
	pos.bottom += 100;

	pd2dRenderTarget->DrawBitmap(RENDERMGR_2D->GetImage(TEXT("Player_Attack_Right")), &pos , 1.0f) ;
	graphicObject.Render(pd2dRenderTarget);
	


}
void CSceneMain::Update(const float& fTime)
{

	if (INPUT->OnlyKeyDown(YT_KEY::YK_W))	playerPos.y -= player_size;
	if (INPUT->OnlyKeyDown(YT_KEY::YK_A))	playerPos.x -= player_size;
	if (INPUT->OnlyKeyDown(YT_KEY::YK_S))	playerPos.y += player_size;
	if (INPUT->OnlyKeyDown(YT_KEY::YK_D))	playerPos.x += player_size;

	if (Input->KeyUp(YT_KEY::YK_F1))	player_size += 5;
	if (Input->KeyUp(YT_KEY::YK_F2))	player_size -= 5;


	if (!DROPMGR->empty())
	{
		auto info = DROPMGR->pop();

		if (info.vDropType[0] == DropInfo_TYPE::DROP_IMAGE)
			graphicObject.SetImageName(info.vFileName[0]);
	}
}

void CSceneMain::LateUpdate(const float& fTime)
{
}


void CSceneMain::FixedUpdate(const float& fTime)
{
}
#include "stdafx.h"
#include "SceneMain.h"
#include "GameFrameWork_D2D.h"

#include "Draw.h"
#include "InputScript.h"

#include "MapObject.h"


CSceneMain::CSceneMain(const std::string& name) : CSceneState(name)
{
}


CSceneMain::~CSceneMain()
{
}

bool CSceneMain::Release()
{
	CSceneState::Release();

	if (m_BackGround)delete m_BackGround;
	m_BackGround = nullptr;

	return true;
}


bool CSceneMain::Start(HINSTANCE hInstance, HWND hWnd, Microsoft::WRL::ComPtr<ID2D1Factory2> pd2dFactory2, ID2D1HwndRenderTarget *pd2dRenderTarget)
{
	CSceneState::Start(hInstance, hWnd, pd2dFactory2, pd2dRenderTarget);

	m_BackGround = new CMapObject;
	m_BackGround->Create(TEXT("map_GentMarket"), Vector2(-50, -50));
	m_BackGround->SetLTRB(-50, -50);
	m_Camera.Create(0.0f, 0.0f, 450.0f, 450.0f);
	auto inputScript = std::make_unique<InputScript>();
	m_Camera.SetComponent(std::move(inputScript));

	return true;
}

void CSceneMain::Render(ID2D1HwndRenderTarget *pd2dRenderTarget)
{
	m_BackGround->Render(pd2dRenderTarget, m_Camera.GetRect());
	m_Camera.Render(pd2dRenderTarget);

}
void CSceneMain::Update(const float& fTime)
{
	m_Camera.Update(fTime);
}

void CSceneMain::LateUpdate(const float& fTime)
{
}


void CSceneMain::FixedUpdate(const float& fTime)
{
}
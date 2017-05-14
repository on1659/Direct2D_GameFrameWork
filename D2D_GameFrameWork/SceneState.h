#pragma once

#include "stdafx.h"

class CSceneState : public CObject_D2D
{
public:

	CSceneState(const std::string& name = "SceneState") : CObject_D2D(name), m_pd2dFactory2(nullptr) {}

	~CSceneState() {}

	virtual bool Start(HINSTANCE hInstance, HWND hWnd, Microsoft::WRL::ComPtr<ID2D1Factory2> pd2dFactory2, ID2D1HwndRenderTarget *pd2dRenderTarget = nullptr)
	{
		m_hInstance = hInstance;
		m_hWnd = hWnd;
		m_pd2dFactory2 = pd2dFactory2;
		return true;
	}

	virtual bool Release() override
	{
		m_hInstance = nullptr;
		m_hWnd = nullptr;
		return true;
	}

	virtual void Render(ID2D1HwndRenderTarget *pd2dRenderTarget) = 0;

	virtual void Update(const float& fTime) = 0;

	virtual void LateUpdate(const float& fTime) = 0;

	virtual void FixedUpdate(const float& fTime) = 0;

protected:
	HINSTANCE								 m_hInstance;
	HWND									 m_hWnd;
	Microsoft::WRL::ComPtr<ID2D1Factory2>	m_pd2dFactory2;
};


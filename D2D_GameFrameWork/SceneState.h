#pragma once

#include "stdafx.h"

class CSceneState : public CObject_D2D
{
public:

	CSceneState(const std::string& name = "SceneState") : CObject_D2D(name) {}

	~CSceneState() {}

	virtual void enter(HINSTANCE hInstance, HWND hWnd, ID2D1HwndRenderTarget *pd2dRenderTarget = nullptr) = 0;

	virtual void exit() = 0;

	virtual void Render(ID2D1HwndRenderTarget *pd2dRenderTarget) = 0;

	virtual void Update(const float& fTime) = 0;

	virtual void LateUpdate(const float& fTime) = 0;

	virtual void FixedUpdate(const float& fTime) = 0;

protected:
	HINSTANCE					m_hInstance;
	HWND						m_hWnd;
};


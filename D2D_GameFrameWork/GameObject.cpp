#include "stdafx.h"
#include "GameObject.h"


#include <random>

CGameObject::CGameObject(const std::string& name) : CObject_D2D(name)
{
	m_vSprite.push_back(CSpriteObject_2D());
	m_vComponent.clear();
}

bool CGameObject::Release()
{
	for (auto& sprite : m_vSprite)
		sprite.Release();

	for (auto& pComp : m_vComponent)
		pComp->Release();

	m_vSprite.clear();
	m_vComponent.clear();

	return true;
}

CGameObject::~CGameObject()
{
}

void CGameObject::Render(ID2D1HwndRenderTarget *pd2dRenderTarget)
{
	for (auto& sprite : m_vSprite) sprite.Render(pd2dRenderTarget);
}

void CGameObject::RenderBoundingBox(ID2D1HwndRenderTarget *pd2dRenderTarget)
{
	for (auto& sprite : m_vSprite) sprite.RenderBoundingBox(pd2dRenderTarget);
}

void CGameObject::OnUpdate(const float& frame_time)
{
	for (auto& sprite : m_vSprite) 
		sprite.SetBoundingBox(m_bcBoundingBox);

	for (auto& pComp : m_vComponent)
		pComp->OnUpdate(frame_time);
}

void CGameObject::push_name(const std::wstring & name)
{

}

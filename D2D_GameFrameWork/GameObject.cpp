#include "stdafx.h"
#include "GameObject.h"


#include <random>

CGameObject::CGameObject(const std::string& name) : CObject_D2D(name)
{
	m_vComponent.clear();
}

bool CGameObject::Release()
{
	for (auto& sprite : m_vSprite)
		sprite.Release();

	for (auto& pComp : m_vComponent)
	{
		pComp->Release();
		pComp.reset();
	}
	m_vSprite.clear();
	m_vComponent.clear();

	return true;
}

CGameObject::~CGameObject()
{
}

void CGameObject::Render(ID2D1HwndRenderTarget *pd2dRenderTarget)
{
	for (auto& sprite : m_vSprite)
		sprite.SetBoundingBox(m_bcBoundingBox);

	for (auto& sprite : m_vSprite) 
		sprite.Render(pd2dRenderTarget);
}

void CGameObject::RenderBoundingBox(ID2D1HwndRenderTarget *pd2dRenderTarget)
{
	for (auto& sprite : m_vSprite)
		sprite.RenderBoundingBox(pd2dRenderTarget);
}

void CGameObject::Update(const float& frame_time)
{
	for (auto& pComp : m_vComponent)
		pComp->Update(frame_time);
}

void CGameObject::Move(const float& x, const float& y)
{
	m_bcBoundingBox.m_position.x += x;
	m_bcBoundingBox.m_position.y += y;
}

void CGameObject::PushName(const std::wstring & name)
{
	m_vSprite.push_back(CSpriteObject_2D(name));
}

void CGameObject::PushSprite(const CSpriteObject_2D & sprite)
{
	m_vSprite.push_back(sprite);
}

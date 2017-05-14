#include "stdafx.h"
#include "GameObject_2D.h"


#include <random>

CGameObject_2D::CGameObject_2D(const std::string& name) : CObject_D2D(name)
{
	m_vComponent.clear();
}

bool CGameObject_2D::Release()
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

CGameObject_2D::~CGameObject_2D()
{
}

void CGameObject_2D::Create(const Vector2 & position, const Vector2 & size)
{
	Create(position.x, position.y, size.x, size.y);
}

void CGameObject_2D::Create(const float & x, const float & y, const float & width, const float & heigh)
{
	SetPosition(x, y);
	SetSize(width, heigh);
}

void CGameObject_2D::Render(ID2D1HwndRenderTarget *pd2dRenderTarget)
{
	for (auto& sprite : m_vSprite)
		sprite.SetBoundingBox(m_bcBoundingBox);

	for (auto& sprite : m_vSprite) 
		sprite.Render(pd2dRenderTarget);

	auto rect = GetRect();

	rect.left = max(0.0f, rect.left);
	rect.top  = max(0.0f, rect.top);

	rect.right  = min(WIDTH, rect.right);
	rect.bottom = min(HEIGHT, rect.bottom);

	pd2dRenderTarget->FillRectangle(rect, MY_COLOR(MyColorEnum::Red));

}

void CGameObject_2D::RenderBoundingBox(ID2D1HwndRenderTarget *pd2dRenderTarget)
{
	for (auto& sprite : m_vSprite)
		sprite.RenderBoundingBox(pd2dRenderTarget);
}

void CGameObject_2D::Update(const float& frame_time)
{
	for (auto& pComp : m_vComponent)
		pComp->Update(frame_time);
}

void CGameObject_2D::Move(const Vector2& v2)
{
	Move(v2.x, v2.y);
}
void CGameObject_2D::Move(const float& x, const float& y)
{
	m_bcBoundingBox.m_position.x += x;
	m_bcBoundingBox.m_position.y += y;
}

void CGameObject_2D::PushName(const std::wstring & name)
{
	m_vSprite.push_back(CSpriteObject_2D(name));
}

void CGameObject_2D::PushSprite(const CSpriteObject_2D & sprite)
{
	m_vSprite.push_back(sprite);
}

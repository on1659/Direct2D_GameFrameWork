#include "stdafx.h"
#include "Camera_2D.h"


CCamera_2D::CCamera_2D(const std::string& name) : CGameObject_2D(name)
{
}


CCamera_2D::~CCamera_2D()
{
}



void CCamera_2D::Update(const float & frame_time)
{
	CGameObject_2D::Update(frame_time);

	if (m_pPlayer)
	{
		auto dir = m_pPlayer->GetPosition() - GetPosition();
		
		// offset범위보다 작게 있으면 무시
		if (dir.scale() < m_v2Offset.scale())
			return;

		dir.normalize();
		Move(dir * m_v2Veolocity);

	}

}

bool CCamera_2D::isVisible(CGameObject_2D& gameObject)
{
	return GetBoundingBox().collision(gameObject.GetBoundingBox());
}

bool CCamera_2D::isVisible(D2D_RECT_F& rect)
{
	return GetBoundingBox().collision(rect);
}

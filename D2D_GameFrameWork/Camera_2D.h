#pragma once
class CCamera_2D : public CGameObject_2D
{
public:
	CCamera_2D(const std::string& name = "Camera_2D");

	~CCamera_2D();

	void Update(const float& frame_time) override;

	bool isVisible(CGameObject_2D& gameObject);
	bool isVisible(D2D_RECT_F& rect);

	void SetSmooth(const bool& mode) { m_bSmooth = mode; }

	void SetVelocity(const Vector2& v2) { SetVelocity(v2.x, v2.y); }
	void SetVelocity(const float& x, const float& y) { m_v2Veolocity.x = x; m_v2Veolocity.y = y; }

	void SetOffset(const Vector2& v2) { SetOffset(v2.x, v2.y); }
	void SetOffset(const float& x, const float& y){	m_v2Offset.x = x; m_v2Offset.y = y; }

private:

	CGameObject_2D*		m_pPlayer{ nullptr };

	bool			    m_bSmooth{ true };
	Vector2				m_v2Veolocity;

	Vector2				m_v2Offset;


};




#pragma once

class CGameObject_2D;

class Component : public CObject_D2D
{
protected:
	CGameObject_2D*			gameObject;

public:
	
	Component(std::string name = "Component") : CObject_D2D(name) {	gameObject = nullptr; }
	
	~Component()  {	gameObject = nullptr; }

	virtual bool Release() override { gameObject = nullptr;  return true; }

	virtual void Start(CGameObject_2D* gameObject) { Component::gameObject = gameObject; }

	virtual void BeforeMove(CGameObject_2D* other) {}

	virtual void Update(const float& frame_time) {}

	virtual void PlayerUpdate(const float& frame_time) {}

	void SetGameObject(CGameObject_2D* gameObject) { Component::gameObject = gameObject; }
};
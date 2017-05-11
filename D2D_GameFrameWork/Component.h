#pragma once

class CGameObject;

class Component : public CObject_D2D
{
protected:
	CGameObject*			gameObject;

public:
	
	Component(std::string name = "Component") : CObject_D2D(name) {	gameObject = nullptr; }
	
	~Component()  {	gameObject = nullptr; }

	virtual bool Release() override { gameObject = nullptr; }

	virtual void Start(CGameObject* gameObject) { Component::gameObject = gameObject; }

	virtual void BeforeMove(CGameObject* other) {}

	virtual void OnUpdate(const float& frame_time) {}

	virtual void PlayerUpdate(const float& frame_time) {}

};
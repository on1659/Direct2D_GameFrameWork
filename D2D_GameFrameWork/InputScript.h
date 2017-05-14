#pragma once

#include "stdafx.h"

class InputScript : public Component
{
	float	fSpeed{ 10.0f };

public:

	InputScript(std::string name = "InputScript") : Component(name)
	{
	}

	virtual ~InputScript()
	{

	}

	virtual void Start(CGameObject_2D* gameObject)
	{
		Component::Start(gameObject);
	}

	virtual void BeforeMove(CGameObject_2D* other)
	{

	}

	virtual void Update(const float&  frame_time)
	{

		if (INPUT->KeyDown(YT_KEY::YK_W) || INPUT->KeyDown(YT_KEY::YK_UP))
			gameObject->Move(0, -fSpeed);
		if (INPUT->KeyDown(YT_KEY::YK_A) || INPUT->KeyDown(YT_KEY::YK_LEFT))
			gameObject->Move(-fSpeed, 0);
		if (INPUT->KeyDown(YT_KEY::YK_S) || INPUT->KeyDown(YT_KEY::YK_DOWN))
			gameObject->Move(0, fSpeed);
		if (INPUT->KeyDown(YT_KEY::YK_D) || INPUT->KeyDown(YT_KEY::YK_RIGHT))
			gameObject->Move(fSpeed, 0);

	}

	virtual void PlayerUpdate(float frame_time)
	{

	}


};
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

	virtual void Start(CGameObject* gameObject)
	{
		Component::Start(gameObject);
	}

	virtual void BeforeMove(CGameObject* other)
	{

	}

	virtual void Update(const float&  frame_time)
	{

		if (INPUT->KeyDown(YT_KEY::YK_W))	
			gameObject->Move(0, -fSpeed);
		if (INPUT->KeyDown(YT_KEY::YK_A))
			gameObject->Move(-fSpeed, 0);
		if (INPUT->KeyDown(YT_KEY::YK_S))
			gameObject->Move(0, fSpeed);
		if (INPUT->OnlyKeyDown(YT_KEY::YK_D))	
			gameObject->Move(fSpeed, 0);

	}

	virtual void PlayerUpdate(float frame_time)
	{

	}


};
#pragma once

#include "stdafx.h"

class SampleScript : public Component
{

public:

	SampleScript(std::wstring name = TEXT("SampleScript")) : Component(name)
	{

	}

	virtual ~SampleScript()
	{ 
	
	}

	virtual void Start(CGameObject_2D* gameObject)
	{
		Component::Start(gameObject);
	}

	virtual void BeforeMove(CGameObject_2D* other) 
	{

	}

	virtual void OnUpdate(float frame_time) 
	{

	}

	virtual void PlayerUpdate(float frame_time)
	{

	}


};
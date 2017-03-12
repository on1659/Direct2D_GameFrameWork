#pragma once

static size_t gInstanceID = 0;

class CObject_D2D
{
public:

	CObject_D2D(const std::string& name = "Object_D2D)");

	virtual ~CObject_D2D();

	virtual bool Start()				{ return true; }
	virtual bool Start(void* pData)		{ return true; }
	virtual bool Release()				{ return true; }

	
public:
	size_t				nGID;
	std::string			name;
	TAG					tag;

	
};


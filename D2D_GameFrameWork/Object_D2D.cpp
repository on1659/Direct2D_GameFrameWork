#include "stdafx.h"
#include "Object_D2D.h"


CObject_D2D::CObject_D2D(const std::string& name) : name(name), nGID(gInstanceID++), tag(TAG::DEFAULT)
{
}


CObject_D2D::~CObject_D2D()
{
}

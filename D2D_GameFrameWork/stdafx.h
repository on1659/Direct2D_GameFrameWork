// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.

#pragma comment(lib, "D2D1.lib")
#pragma comment(lib, "Dwrite.lib")
#pragma comment(lib, "windowscodecs.lib")


// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <memory>
#include <tchar.h>


//C++
#include <iostream>
#include <chrono>
#include <algorithm>
#include <memory>	

//STL Container
#include <string>
#include <vector>
#include <map>
#include <array>

// D2D1

#include <d2d1.h>
#include <d2d1_1.h>
#include <dwrite.h>
#include <dwrite_2.h>
#include <d2d1_2helper.h>
#include <wincodec.h>

// DirectX Math
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
#include <DirectXColors.h>
#include <DirectXCollision.h>

// U W P
#include <wrl.h>
#include <wrl/client.h>
#include <wrl/internal.h>

// Texture Loader : in Utils

using namespace D2D1;
using namespace DirectX;
using namespace DirectX::PackedVector;


#include "MyDefine.h"
#include "MyEnum.h"
#include "MyStruct.h"

#include "Object_D2D.h"
#include "SingleTon.h"
#include "SceneState.h"
#include "InputManager.h"
#include "DropManager.h"
#include "DrawHelper.h"

#include "Timer.h"
#include "Util.h"
#include "Draw.h"
#include "GraphicObject_2D.h"
#include "SpriteObject_2D.h"

#include "RenderManager_2D.h"
#include "Component.h"
#include "GameObject.h"

static HWND gHwnd;

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

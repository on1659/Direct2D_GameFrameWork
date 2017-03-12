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
#include <tchar.h>


//C++
#include <iostream>
#include <chrono>
#include <algorithm>


//STL Container
#include <string>
#include <vector>

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

#include "Timer.h"





// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

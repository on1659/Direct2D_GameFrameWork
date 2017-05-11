#include "stdafx.h"
#include "RenderManager_2D.h"


CRenderManager_2D::CRenderManager_2D(const std::string& name) : CSingleTonBase(name)
{
}

CRenderManager_2D::~CRenderManager_2D()
{
}

void CRenderManager_2D::Load(Microsoft::WRL::ComPtr<IWICImagingFactory2> pwicFactory, Microsoft::WRL::ComPtr<ID2D1HwndRenderTarget> phWndRenderTarget)
{
	m_wicFactory = pwicFactory;
	m_hWndRenderTarget = phWndRenderTarget;

	// -- Always -- 
		AddImage(TEXT("Default"), TEXT("../Asset/default.png"));
	// -- Always --


	AddMirrorFolderImage(TEXT("../Asset/Player/"), TEXT("Player_")) ;

}

void CRenderManager_2D::AddMirrorFolderImage(const std::wstring& path, const std::wstring& name, WICBitmapTransformOptions nFlipRotation)
{
	auto vPlayerPath = Radar::FilePathRead(path.c_str());
	for (auto path : vPlayerPath)
	{
		TCHAR file[100];
		_wsplitpath(path.c_str(), NULL, NULL, file, NULL);
		AddMirrorImage(name + std::wstring(file), path, nFlipRotation);
	}

}

void CRenderManager_2D::AddFolderImage(const std::wstring& path, const std::wstring& name, WICBitmapTransformOptions nFlipRotation)
{
	auto vPlayerPath = Radar::FilePathRead(path.c_str());
	for (auto path : vPlayerPath)
	{
		TCHAR file[100];
		_wsplitpath(path.c_str(), NULL, NULL, file, NULL);
		AddImage(name + std::wstring(file), path, nFlipRotation);
	}

}

void CRenderManager_2D::AddMirrorImage(const std::wstring& name, const std::wstring& path, WICBitmapTransformOptions nFlipRotation)
{
	AddLeftImage(name, path);
	AddRightImage(name, path);
}

void CRenderManager_2D::AddLeftImage(const std::wstring& name, const std::wstring& path, WICBitmapTransformOptions nFlipRotation)
{
	if (nullptr == FindImage(name))
	{
		ID2D1Bitmap* bitmap = nullptr;
		if (!LoadD2DImage(path, &bitmap, nFlipRotation))
		{
			MessageBox(gHwnd, TEXT("error"), path.c_str(), MB_OK);
			return;
		}
		m_mD2D_Texture.insert(std::make_pair(name + TEXT("_Left"), bitmap));
	}
}

void CRenderManager_2D::AddRightImage(const std::wstring& name, const std::wstring& path, WICBitmapTransformOptions nFlipRotation)
{
	if (nullptr == FindImage(name))
	{
		ID2D1Bitmap* bitmap = nullptr;
		if (!LoadD2DImage(path, &bitmap, nFlipRotation))
		{
			MessageBox(gHwnd, TEXT("error"), path.c_str(), MB_OK);
			return;
		}
		m_mD2D_Texture.insert(std::make_pair(name + TEXT("_Right"), bitmap));
	}
}

bool CRenderManager_2D::AddDropImage(const std::wstring & name, const std::wstring & path, WICBitmapTransformOptions nFlipRotation)
{
	//ID2D1Bitmap* bitmap = nullptr;
	//if (!LoadD2DImage(path, &bitmap, nFlipRotation))
	//{
	//	MessageBox(gHwnd, TEXT("error"), path.c_str(), MB_OK);
	//	return;
	//}
	//auto iter = m_mD2D_Texture.find(name);
	//
	////없다는 얘기임
	//if (iter == m_mD2D_Texture.end())
	//{
	//	m_mD2D_Texture.insert(std::make_pair(name, bitmap));
	//	return true;
	//}
	//
	////있다는 얘기임
	//else
	//{
	//	if (bitmap->GetPixelFormat() == iter->second->GetPixelFormat())
	//	{
	//		bitmap->Release();
	//		bitmap = nullptr;
	//		return false;
	//	}
	//	else
	//	{
	//		m_mD2D_Texture.insert(std::make_pair(name + TEXT("1"), bitmap));
	//		return true;
	//	}
	//}
	return true;

}

void CRenderManager_2D::AddImage(const std::wstring& name, const std::wstring& path, WICBitmapTransformOptions nFlipRotation)
{
	if (nullptr == FindImage(name))
	{
		ID2D1Bitmap* bitmap = nullptr;
		if (!LoadD2DImage(path, &bitmap, nFlipRotation))
		{
			MessageBox(gHwnd, TEXT("error"), path.c_str(), MB_OK);
			return;
		}
		m_mD2D_Texture.insert(std::make_pair(name, bitmap));
	}
}

void CRenderManager_2D::Render(ID2D1HwndRenderTarget* pd2dRenderTarget, const std::wstring& name, const D2D_RECT_F&  pos, const float& alpha)
{
	auto image = GetImage(name);
	pd2dRenderTarget->DrawBitmap(image, pos, alpha);
}

void CRenderManager_2D::Render(ID2D1HwndRenderTarget* pd2dRenderTarget, const std::wstring& name, const D2D_RECT_F&  pos, const float& alpha, const D2D_RECT_F& sprite)
{
	auto image = GetImage(name);
	pd2dRenderTarget->DrawBitmap(image, pos, alpha, D2D1_BITMAP_INTERPOLATION_MODE_LINEAR, sprite);
}

ID2D1Bitmap* CRenderManager_2D::FindImage(const std::wstring& name)
{
	auto iter = m_mD2D_Texture.find(name);

	if (iter == m_mD2D_Texture.end())
	{
		return nullptr;
	}
	else
		return iter->second;

}

ID2D1Bitmap* CRenderManager_2D::GetImage(const std::wstring& name)
{
	auto iter = m_mD2D_Texture.find(name);

	if (iter == m_mD2D_Texture.end())
	{
		return GetImage(TEXT("Default"));
	}
	else
		return iter->second;

}

bool CRenderManager_2D::Release()
{
	for (auto& bitmap : m_mD2D_Texture)
	{
		if(bitmap.second)   
			bitmap.second->Release();

		bitmap.second = nullptr;
	}
	
	m_mD2D_Texture.clear();

	return false;
}

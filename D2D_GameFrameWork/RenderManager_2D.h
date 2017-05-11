#pragma once

class CRenderManager_2D : public CSingleTonBase<CRenderManager_2D>
{

	Microsoft::WRL::ComPtr<IWICImagingFactory2>			m_wicFactory;
	Microsoft::WRL::ComPtr<ID2D1HwndRenderTarget>		m_hWndRenderTarget;

	std::map<std::wstring, ID2D1Bitmap*>				m_mD2D_Texture;


private:
	//AddÀü¿ë
	ID2D1Bitmap* FindImage(const std::wstring& name);


public:

	CRenderManager_2D(const std::string& name = "RenderManager");

	~CRenderManager_2D();

	void Load(Microsoft::WRL::ComPtr<IWICImagingFactory2> pwicFactory, Microsoft::WRL::ComPtr<ID2D1HwndRenderTarget> phWndRenderTarget);

	bool Release() override;

	//Default Image
	void AddImage(const std::wstring& name, const std::wstring& path, WICBitmapTransformOptions nFlipRotation = WICBitmapTransformRotate0);
	
	// Folder Reader
	void AddMirrorFolderImage(const std::wstring& path, const std::wstring& name_tag = TEXT(""), WICBitmapTransformOptions nFlipRotation = WICBitmapTransformRotate0);

	void AddFolderImage(const std::wstring& path, const std::wstring& name_tag = TEXT(""), WICBitmapTransformOptions nFlipRotation = WICBitmapTransformRotate0);

	//Right, Left Load
	void AddMirrorImage(const std::wstring& name, const std::wstring& path, WICBitmapTransformOptions nFlipRotation = WICBitmapTransformRotate0);

	void AddLeftImage(const std::wstring& name, const std::wstring& path, WICBitmapTransformOptions nFlipRotation = WICBitmapTransformRotate0);

	void AddRightImage(const std::wstring& name, const std::wstring& path, WICBitmapTransformOptions nFlipRotation = WICBitmapTransformFlipHorizontal);

	//Drop Image
	bool AddDropImage(const std::wstring& name, const std::wstring& path, WICBitmapTransformOptions nFlipRotation = WICBitmapTransformRotate0);

	void Render(ID2D1HwndRenderTarget *pd2dRenderTarget, const std::wstring& name, const D2D_RECT_F&  pos, const float& alpha, const D2D_RECT_F& sprite);

	void Render(ID2D1HwndRenderTarget *pd2dRenderTarget, const std::wstring& name, const D2D_RECT_F&  pos, const float& alpha = 255);

	ID2D1Bitmap* GetImage(const std::wstring& name);

	bool LoadD2DImage(const std::wstring& path, ID2D1Bitmap **ppd2dBitmap, WICBitmapTransformOptions nFlipRotation, D2D_RECT_U *pd2drcImage = nullptr, UINT nWidth = 0, UINT nHeight = 0)
	{
		HRESULT hResult;
		IWICBitmapDecoder *pwicBitmapDecoder = NULL;
		
		if (FAILED(hResult = m_wicFactory->CreateDecoderFromFilename(path.c_str(), NULL, GENERIC_READ, WICDecodeMetadataCacheOnDemand, &pwicBitmapDecoder))) 
			return(false);

		IWICBitmapFrameDecode *pwicBitmapFrameDecode = NULL;
		if (FAILED(hResult = pwicBitmapDecoder->GetFrame(0, &pwicBitmapFrameDecode))) return(false);
		IWICBitmapSource *pwicSource = pwicBitmapFrameDecode;
		UINT nImageWidth, nImageHeight;
		if (FAILED(hResult = pwicSource->GetSize(&nImageWidth, &nImageHeight))) return(false);
		IWICFormatConverter	*pwicFormatConverter = NULL;
		IWICBitmapScaler *pwicScaler = NULL;
		IWICBitmapClipper *pwicClipper = NULL;
		IWICBitmapFlipRotator *pwicFlipRotator = NULL;
		if (pd2drcImage)
		{
			if (pd2drcImage->left < 0) pd2drcImage->left = 0;
			if (pd2drcImage->top < 0) pd2drcImage->top = 0;
			if (pd2drcImage->right > nImageWidth) pd2drcImage->right = nImageWidth;
			if (pd2drcImage->bottom > nImageHeight) pd2drcImage->bottom = nImageHeight;
			WICRect wicRect = { static_cast<INT>(pd2drcImage->left), static_cast<INT>(pd2drcImage->top), static_cast<INT>((pd2drcImage->right - pd2drcImage->left)), static_cast<INT>((pd2drcImage->bottom - pd2drcImage->top)) };
			if (FAILED(hResult = m_wicFactory->CreateBitmapClipper(&pwicClipper))) return(false);
			if (FAILED(hResult = pwicClipper->Initialize(pwicSource, &wicRect))) return(false);
			pwicSource = pwicClipper;
		}
		if ((nWidth != 0) || (nHeight != 0))
		{
			if (nWidth == 0) nWidth = UINT(float(nHeight) / float(nImageHeight) * float(nImageWidth));
			if (nHeight == 0) nHeight = UINT(float(nWidth) / float(nImageWidth) * float(nImageHeight));
			if (FAILED(hResult = m_wicFactory->CreateBitmapScaler(&pwicScaler))) return(false);
			if (FAILED(hResult = pwicScaler->Initialize(pwicSource, nWidth, nHeight, WICBitmapInterpolationModeCubic))) return(false);
			pwicSource = pwicScaler;
		}
		if (nFlipRotation != WICBitmapTransformRotate0)
		{
			if (FAILED(hResult = m_wicFactory->CreateBitmapFlipRotator(&pwicFlipRotator))) return(false);
			if (FAILED(hResult = pwicFlipRotator->Initialize(pwicSource, nFlipRotation))) return(false);
			pwicSource = pwicFlipRotator;
		}
		if (FAILED(hResult = m_wicFactory->CreateFormatConverter(&pwicFormatConverter))) return(false);
		if (FAILED(hResult = pwicFormatConverter->Initialize(pwicSource, GUID_WICPixelFormat32bppPBGRA, WICBitmapDitherTypeNone, NULL, 0.f, WICBitmapPaletteTypeMedianCut))) return(false);
		if (FAILED(hResult = m_hWndRenderTarget->CreateBitmapFromWicBitmap(pwicFormatConverter, NULL, ppd2dBitmap))) return(false);

		if (pwicBitmapFrameDecode) pwicBitmapFrameDecode->Release();
		if (pwicBitmapDecoder) pwicBitmapDecoder->Release();
		if (pwicFormatConverter) pwicFormatConverter->Release();
		if (pwicClipper) pwicClipper->Release();
		if (pwicScaler) pwicScaler->Release();
		if (pwicFlipRotator) pwicFlipRotator->Release();

		return(true);
	}

};


#pragma once

class CGameFrameWork_D2D : public CSingleTonBase<CGameFrameWork_D2D>
{

	using float4 = struct { float x; float y; float z; float w; };

public:

		CGameFrameWork_D2D(const std::string& name = "GameFrameWork_D2D");

		~CGameFrameWork_D2D();

		void Initialize(HINSTANCE hInstance, HWND hWnd);

		bool Release() override;

	//---------------------------------

		void Update(const float& fTime = 0.17f);

		void Render();

		void FrameAdvance();

	//------------------------------------------------------------

		auto GetD2DFactory()		 const { return m_pd2dFactory.Get(); }
		auto GetDWriteFactory()		 const { return m_pdwFactory.Get(); }
		auto GetDWICImagingFactory() const { return m_wicFactory.Get(); }


private:
	bool CreateRenderTarget();
	bool CreateD2DFactory();
	bool CreateIndependentResources();
	bool CreateHwndRenderTarget();

private:
	RECT												m_rcWindowClient;
	float												m_fps;
	HINSTANCE											m_hInstance;
	HWND												m_hWnd	;

	TCHAR												m_CaptionTitle[TITLE_MAX_LENGTH];
	int													m_TitleLength;


private:
	Microsoft::WRL::ComPtr<ID2D1Factory2>				m_pd2dFactory;
	Microsoft::WRL::ComPtr<IDWriteFactory2>				m_pdwFactory;
	Microsoft::WRL::ComPtr<IWICImagingFactory2>			m_wicFactory;
	Microsoft::WRL::ComPtr<ID2D1HwndRenderTarget>		m_hWndRenderTarget;


};

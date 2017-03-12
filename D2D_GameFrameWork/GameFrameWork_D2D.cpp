#include "stdafx.h"
#include "GameFrameWork_D2D.h"


CGameFrameWork_D2D::CGameFrameWork_D2D(const std::string& name)
	: CSingleTonBase(name)
	, m_pd2dFactory(nullptr)
	, m_pdwFactory(nullptr)
	, m_wicFactory(nullptr)
	, m_hWndRenderTarget(nullptr)
	, m_hInstance(nullptr)
	, m_hWnd(nullptr)
{

}
	

CGameFrameWork_D2D::~CGameFrameWork_D2D()
{
}

void CGameFrameWork_D2D::Initialize(HINSTANCE hInstance, HWND hWnd)
{
	m_hInstance = hInstance;
	m_hWnd = hWnd;
	::GetClientRect(m_hWnd, &m_rcWindowClient);

	// 캡션 변경
	#if defined(TITLESTRING)
		lstrcpy(m_CaptionTitle, TITLESTRING);
	#else
		GetWindowText(m_hWnd, m_CaptionTitle, TITLE_MAX_LENGTH);
	#endif
	
	#if defined(SHOW_CAPTIONFPS)
		lstrcat(m_CaptionTitle, TEXT(" ("));
	#endif

		m_TitleLength = lstrlen(m_CaptionTitle);
	SetWindowText(m_hWnd, m_CaptionTitle);

	CreateIndependentResources();
	if (!CreateRenderTarget())
	{
		MessageBox(m_hWnd, L"Error", L"CreateRenderTarget", MB_OK);
	}


}

bool CGameFrameWork_D2D::Release()
{
	return false;
}

bool CGameFrameWork_D2D::CreateRenderTarget()
{
	return CreateHwndRenderTarget();
}

bool CGameFrameWork_D2D::CreateIndependentResources()
{
	HRESULT hResult = S_OK;

	// Direct2D 리소스를 초기화합니다.
	D2D1_FACTORY_OPTIONS options;
	ZeroMemory(&options, sizeof(D2D1_FACTORY_OPTIONS));

	#if defined(_DEBUG)
		// 프로젝트가 디버그 빌드 중인 경우 SDK 레이어를 통해 Direct2D 디버깅을 사용합니다.
		options.debugLevel = D2D1_DEBUG_LEVEL_INFORMATION;
	#endif

	// Direct2D 팩터리를 초기화합니다.
	if (FAILED(hResult = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED
		, __uuidof(decltype(m_pd2dFactory)::InterfaceType)
		, &options
		, &m_pd2dFactory
	))) return false;

	// DirectWrite 팩터리를 초기화합니다.
	if (FAILED(hResult = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED
		, __uuidof(decltype(m_pdwFactory)::InterfaceType)
		, &m_pdwFactory
	))) return false;

	// COM Library를 초기화합니다.
	// UWP에는 없어도 잘 돌아가더니 여기선 안 돌아가네.
	if (FAILED(hResult = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED))) return false;;

	// WIC(Windows Imaging Container) 팩터리를 초기화합니다.
	if (FAILED(hResult = CoCreateInstance(CLSID_WICImagingFactory
		, nullptr
		, CLSCTX_INPROC_SERVER
		, IID_PPV_ARGS(&m_wicFactory)
	))) return false;


	return true;
	
}

bool CGameFrameWork_D2D::CreateHwndRenderTarget()
{
	RECT rc{};
	::GetClientRect(m_hWnd, &rc);

	D2D1_SIZE_U size
	{
		static_cast<UINT32>(rc.right - rc.left)
		, static_cast<UINT32>(rc.bottom - rc.top)
	};

	auto result = m_pd2dFactory->CreateHwndRenderTarget
	(
		  D2D1::RenderTargetProperties()
		, D2D1::HwndRenderTargetProperties(m_hWnd, size, D2D1_PRESENT_OPTIONS_IMMEDIATELY)
		, &m_hWndRenderTarget
	);

	return m_hWndRenderTarget;
}

void CGameFrameWork_D2D::Update(const float& fTime)
{
}

void CGameFrameWork_D2D::Render()
{
	m_hWndRenderTarget->BeginDraw();

	m_hWndRenderTarget->Clear(ColorF{ ColorF::Gainsboro });

	Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> hbr;
	m_hWndRenderTarget->CreateSolidColorBrush(ColorF{ ColorF::AliceBlue }, &hbr);

	float angle = XMConvertToRadians(0.17f * 270.f);
	float x = 50 + cos(angle) * 25.f;
	float y = 50 + sin(angle) * 25.f;
	m_hWndRenderTarget->FillRectangle(RectF(x - 10.f, y - 10.f, x + 10.f, y + 10.f), hbr.Get());


	HRESULT hResult = m_hWndRenderTarget->EndDraw(); //	End Draw

}

void CGameFrameWork_D2D::FrameAdvance()
{
	auto fTick = TIMER->Tick(60.0f);

	// 지속적인 상수버퍼의 갱신을 확인하기 위한 Update 함수
	Update(fTick);

	Render();

	// 프레임레이트를 출력합니다.
	#if defined(SHOW_CAPTIONFPS)

		m_dCumulativefps += m_fps;
		m_nCumulativefpsCount++;

		m_UpdateElapsed = chrono::system_clock::now() - m_LastUpdate_time;
		if (m_UpdateElapsed.count() > MAX_UPDATE_FPS)
			m_LastUpdate_time = chrono::system_clock::now();
		else return;

		double resultFps = m_dCumulativefps / static_cast<double>(m_nCumulativefpsCount);

		m_dCumulativefps = 0.0;
		m_nCumulativefpsCount = 0;

	#if USE_DEBUG_WINDOW
		Event_CutsomLogger eventShowFPS(string("FPS"), to_string(m_fps));
		CLogSystem::PropagateNotification(nullptr, &eventShowFPS);
	#endif

		_itow_s(static_cast<int>(resultFps + 0.1), m_CaptionTitle + m_TitleLength, TITLE_MAX_LENGTH - m_TitleLength, 10);
		wcscat_s(m_CaptionTitle + m_TitleLength, TITLE_MAX_LENGTH - m_TitleLength, TEXT(" FPS)"));
		SetWindowText(m_hWnd, m_CaptionTitle);
	#endif



}

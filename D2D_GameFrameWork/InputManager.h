#pragma once

#include <deque>
#include <queue>
#include <deque>
#include <queue>

#include <XInput.h>
#pragma comment(lib, "XInput.lib")


enum GPAD_KEY
{
	GPAD_dLEFT		= XINPUT_GAMEPAD_DPAD_LEFT,
	GPAD_dRIGHT		= XINPUT_GAMEPAD_DPAD_RIGHT,
	GPAD_dUP		= XINPUT_GAMEPAD_DPAD_UP,
	GPAD_dDOWN		= XINPUT_GAMEPAD_DPAD_DOWN,
	GPAD_SPACE		= YK_SPACE, //bLeftTrigger,
	GPAD_LSHFIT		= YK_LSHIFT, //bRightTrigger,
	GPAD_LBUTTON	= XINPUT_GAMEPAD_LEFT_SHOULDER,
	GPAD_RBUTTON	= XINPUT_GAMEPAD_RIGHT_SHOULDER,
	GPAD_1			= XINPUT_GAMEPAD_A,
	GPAD_2			= XINPUT_GAMEPAD_B,
	GPAD_3			= XINPUT_GAMEPAD_X,
	GPAD_4			= XINPUT_GAMEPAD_Y,
	GPAD_C			= XINPUT_GAMEPAD_START,
	GPAD_G			= XINPUT_GAMEPAD_RIGHT_SHOULDER,
	GPAD_END		= 12,
	GPAD_NONE		= 0,
	GPAD_VIVERATE	= 50000,
	GPAD_BACK		= XINPUT_GAMEPAD_BACK
};
#define GPAD_DURING_VIVERATE 0.5f


typedef struct tagKeyState
{
	YT_KEY    ytkey;
	GPAD_KEY  padkey;
	bool	bUpCheck;
	bool	bDownCheck;
	bool	bStick;
	BYTE	BKey;

	tagKeyState::tagKeyState()
	{
		ytkey = YK_END;
		padkey = GPAD_END;
		bUpCheck = false;
		bDownCheck = false;
		bStick = false;
		BKey = NULL;
	}

}KEYSTATE;

typedef struct KeyStateCheck
{
	YT_KEY key;
	bool   bDown;

	KeyStateCheck() {};

	KeyStateCheck(YT_KEY inKey, bool inDown)
	{
		key = inKey;
		bDown = inDown;
	}
}keyStateCheck;

class CInputManager : public CSingleTonBase<CInputManager>
{
	//키보드
private:
	//Key Data
	std::vector<KEYSTATE>				m_vKeyState;

	//KeyState
	bool*								m_bKeyState;

	std::deque<KeyStateCheck>			m_bInputQueue;


	int									m_sWheel;
	POINT								pt;

	bool								m_bLeftCheck;
	bool								m_bRightCheck;

	//KYT 16'.04.17
	/*
		input 수정
	*/
	bool							m_bKeyBoardPressCheck;
	UCHAR							pKeysBuffer[256];
	//

	//KYT '16.05.03
	/*
	Character Player을 컴포넌트로 옮기기 위함
	*/
	POINT							m_ptOldCursorPos;

	//JJY '16.05.07
	/*
	m_OldcxDelta, m_OldcyDelta 함수 추가
	*/
	float m_OldcxDelta, m_OldcyDelta;


	//RSH '16.05.13
	/*
	GamePad<Byte> Vector
	*/
	std::vector<KEYSTATE>				m_vPadState;
	bool								m_bConnect;

	std::vector<std::string>		    m_stHashTable;

	//진동
	float								m_fVibrateDuringTime;
	float								m_fVibrateionFrame;
	bool								m_bVibrate;

public:
	CInputManager(const CInputManager& rhs) = delete;


public:
	CInputManager(const std::string& name = "InputManager");
	virtual ~CInputManager();


private:
	void AddKey(YT_KEY key, BYTE input, GPAD_KEY gPad = GPAD_NONE);


public:

	void Load();
	void Update(float fTimeEleasped);
	void UpdateKeyBoard();
	void UpdateGamePoad(float fTimeEleasped);

	// bKeyBoard_Container
	bool KeyDown(YT_KEY input);
	bool KeyBoardDown(YT_KEY key);
	bool KeyPadDown(YT_KEY key);

	// KeyUp
	bool KeyUp(YT_KEY input);
	bool KeyBoardUp(YT_KEY input);
	bool KeyPadUp(YT_KEY input);

	void ShowQueue();
	void ClearQueue() { m_bInputQueue.clear(); }

	//KeyUp은 사용하지 않고 KeyDown만 사용하는 키에서 사용
	bool OnlyKeyDown(YT_KEY input);
	bool OnlyKeyBoardDown(YT_KEY input);
	bool OnlyKeyPadDown(YT_KEY input);

	BYTE AnyOneKeyDown(int n, YT_KEY ...);


	//Mouse
	/*  Wheel Down < WheelNon < Wheel Up  */
	void SetWheel(int wheel);
	int GetWheel() { return m_sWheel; }
	void MouseWheel();
	void SetMousePoint(int qx, int y);
	void SetMousePoint(POINT _pt);
	bool MouseLeftDown();
	bool MouseRightDown();
	bool MouseLeftUp();
	bool MouseRightUp();
	void SetMouseLeft(bool click) { m_bLeftCheck = click; }
	void SetMouseRight(bool click) { m_bRightCheck = click; }
	POINT GetMousePoint() { return pt; }



	// Queue Clear 및 데이터 Popup
	void ShowInputData();

	//void DeleteQueue(){ m_bInputQueue.clear(); }

	int GetSize() { return m_bInputQueue.size(); }

	std::deque<KeyStateCheck> GetInputQueue();


	//KYT '16.04.17
	/*
		input 수정
	*/
	void SetKeyBoardPress(bool press) { m_bKeyBoardPressCheck = press; }
	//

	//KYT '16.05.02
	void SetOldCursorPos() { GetCursorPos(&m_ptOldCursorPos); }
	POINT GetOldCursorPos() const { return m_ptOldCursorPos; }

	//JJY '16.05.07
	/*
	GetOldcxDelta, GetOldcyDelta 함수 추가
	*/
	float GetOldcxDelta() { return m_OldcxDelta; }
	float GetOldcyDelta() { return m_OldcyDelta; }
	void SetOldcxDelta(float cxdelta) { m_OldcxDelta = cxdelta; }
	void SetOldcyDelta(float cydelta) { m_OldcyDelta = cydelta; }

private:
	//RSH '16.05.01 
	/*
	XBOX 조작을 위한 멤버 변수 추가
	*/
	XINPUT_STATE m_xGamepadState;
	SHORT		 m_oldThumbRX;
	SHORT		 m_oldThumbRY;
	SHORT		 m_oldThumbLX;
	SHORT		 m_oldThumbLY;

public:
	//RSH '16.05.01 
	/*
	XBOX 조작을 위한 멤버 함수 추가
	*/
	XINPUT_GAMEPAD GetGamepad();
	bool IsGamepadConnected() const { return m_bConnect; }
	void IsGamepadConnected(bool*);
	bool IsGamepadRightThumb_outsideDeadzoneX();
	bool IsGamepadRightThumb_outsideDeadzoneY();
	bool IsGamepadRightThumb_outsideDeadzone();

	bool IsGamepadLeftThumb_outsideDeadzoneX();
	bool IsGamepadLeftThumb_outsideDeadzoneY();
	bool IsGamepadLeftThumb_outsideDeadzone();

	bool IsGamepadLeftThumb_outsideDeadzoneLeft();
	bool IsGamepadLeftThumb_outsideDeadzoneRight();

	bool IsGamepadLeftThumb_outsideDeadzoneUp();
	bool IsGamepadLeftThumb_outsideDeadzoneDown();

	void      StartVibrate(const int& leftVal = GPAD_VIVERATE, const int& rightVal = GPAD_VIVERATE);
	void  StartLeftVibrate(const int& vibrate = GPAD_VIVERATE);
	void StartRightVibrate(const int& vibrate = GPAD_VIVERATE);
	void       StopVibrate(const int& leftVal = 0, const int& rightVal = 0);

};


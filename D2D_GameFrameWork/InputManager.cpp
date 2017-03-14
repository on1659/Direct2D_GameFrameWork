#include "stdafx.h"
#include "InputManager.h"
#include <iostream>

CInputManager::CInputManager(const std::string& name) : CSingleTonBase(name)
{
	m_vKeyState.reserve(YK_END);
	m_sWheel = 0;
	pt.x = pt.y = 0;

	m_bLeftCheck = false;
	m_bRightCheck = false;

	m_bKeyBoardPressCheck = false;
}

CInputManager::~CInputManager()
{

}

void CInputManager::Load()
{
	m_stHashTable.clear();

	//Pad Connect
	m_bConnect = false;
		
	//Vibe State
	m_fVibrateionFrame = 0.0f;
	m_fVibrateDuringTime = GPAD_DURING_VIVERATE;
	m_bVibrate = false;


	m_bKeyState = new bool[YK_END];

	memset(&pKeysBuffer, 0, sizeof(pKeysBuffer));

	CInputManager::AddKey(YK_LEFT, VK_LEFT, GPAD_dLEFT);
	CInputManager::AddKey(YK_RIGHT, VK_RIGHT, GPAD_dRIGHT);
	CInputManager::AddKey(YK_UP, VK_UP, GPAD_dUP);
	CInputManager::AddKey(YK_DOWN, VK_DOWN, GPAD_dDOWN);
	CInputManager::AddKey(YK_RBUTTON, VK_RBUTTON, GPAD_RBUTTON);
	CInputManager::AddKey(YK_LBUTTON, VK_LBUTTON, GPAD_LBUTTON);
	CInputManager::AddKey(YK_LSHIFT, VK_LSHIFT, GPAD_LSHFIT);
	CInputManager::AddKey(YK_SPACE, VK_SPACE, GPAD_SPACE);
	CInputManager::AddKey(YK_F1, VK_F1);
	CInputManager::AddKey(YK_F2, VK_F2);
	CInputManager::AddKey(YK_F3, VK_F3);
	CInputManager::AddKey(YK_F4, VK_F4);
	CInputManager::AddKey(YK_F5, VK_F5);
	CInputManager::AddKey(YK_F6, VK_F6);
	CInputManager::AddKey(YK_F7, VK_F7);
	CInputManager::AddKey(YK_F8, VK_F8);
	CInputManager::AddKey(YK_F9, VK_F9);
	CInputManager::AddKey(YK_F10, VK_F10);
	CInputManager::AddKey(YK_F11, VK_F11);
	CInputManager::AddKey(YK_F12, VK_F12);
	CInputManager::AddKey(YK_TAB, VK_TAB);
	CInputManager::AddKey(YK_CONTROL, VK_CONTROL);

	CInputManager::AddKey(YK_0, VK_0);
	CInputManager::AddKey(YK_1, VK_1);
	CInputManager::AddKey(YK_2, VK_2);
	CInputManager::AddKey(YK_3, VK_3);
	CInputManager::AddKey(YK_4, VK_4);
	CInputManager::AddKey(YK_5, VK_5);
	CInputManager::AddKey(YK_6, VK_6);
	CInputManager::AddKey(YK_7, VK_7);
	CInputManager::AddKey(YK_8, VK_8);
	CInputManager::AddKey(YK_9, VK_9);

	CInputManager::AddKey(YK_A, VK_A);
	CInputManager::AddKey(YK_B, VK_B);
	CInputManager::AddKey(YK_C, VK_C);
	CInputManager::AddKey(YK_D, VK_D);
	CInputManager::AddKey(YK_E, VK_E);
	CInputManager::AddKey(YK_F, VK_F);
	CInputManager::AddKey(YK_G, VK_G);
	CInputManager::AddKey(YK_H, VK_H);
	CInputManager::AddKey(YK_I, VK_I);
	CInputManager::AddKey(YK_J, VK_J);
	CInputManager::AddKey(YK_K, VK_K);
	CInputManager::AddKey(YK_L, VK_L);
	CInputManager::AddKey(YK_M, VK_M);
	CInputManager::AddKey(YK_N, VK_N);
	CInputManager::AddKey(YK_O, VK_O);
	CInputManager::AddKey(YK_P, VK_P);
	CInputManager::AddKey(YK_Q, VK_Q);
	CInputManager::AddKey(YK_R, VK_R);
	CInputManager::AddKey(YK_S, VK_S);
	CInputManager::AddKey(YK_T, VK_T);
	CInputManager::AddKey(YK_U, VK_U);
	CInputManager::AddKey(YK_V, VK_V);
	CInputManager::AddKey(YK_W, VK_W);
	CInputManager::AddKey(YK_X, VK_X);
	CInputManager::AddKey(YK_Y, VK_Y);
	CInputManager::AddKey(YK_Z, VK_Z);

}

void CInputManager::Update(float fTimeEleasped)
{
	IsGamepadConnected(&m_bConnect);

	if (m_bConnect)
		UpdateGamePoad(fTimeEleasped);
	else
		UpdateKeyBoard();

	//JJY '16.04.18
	/*
	InputDataSending함수 호출
	*/
	//
	#ifdef _CONNECT_SERVER_
		InputDataSending();
	#endif
	//
}
void CInputManager::UpdateKeyBoard()
{
	GetKeyboardState(pKeysBuffer);

	for (int i = 0; i < YT_KEY::YK_END; ++i)
	{
		if (m_bKeyState[i])
		{
			if (false == GetAsyncKeyState(m_vKeyState[i].BKey))
			{
				m_bKeyState[i] = false;
				m_bInputQueue.push_back(KeyStateCheck(m_vKeyState[i].ytkey, false));
			}
		}
	}
}
void CInputManager::UpdateGamePoad(float fTimeEleasped)
{

	if (m_bVibrate)
	{
		m_fVibrateionFrame += fTimeEleasped;
	}

	if (m_fVibrateionFrame > m_fVibrateDuringTime)
		StopVibrate();

	for (int i = 0; i < YT_KEY::YK_END; ++i)
	{

		if (m_bKeyState[i])
		{
			if (false == (m_xGamepadState.Gamepad.wButtons & m_vKeyState[i].padkey))
			{
				if (m_vKeyState[i].bStick)
				{
					if (i == YK_LEFT)
					{
						if (IsGamepadLeftThumb_outsideDeadzoneLeft())
							break;
					}
					else if (i == YK_RIGHT)
					{
						if (IsGamepadLeftThumb_outsideDeadzoneRight())
							break;
					}

					if (i == YK_UP)
					{
						if (IsGamepadLeftThumb_outsideDeadzoneUp())
							break;
					}
					else if (i == YK_DOWN)
					{
						if (IsGamepadLeftThumb_outsideDeadzoneDown())
							break;
					}
				}
				m_vKeyState[i].bStick = false;
				m_vKeyState[i].bUpCheck = true;
				m_bKeyState[i] = false;
				m_bInputQueue.push_back(KeyStateCheck(m_vKeyState[i].ytkey, false));
			}
		}
	}
}

void CInputManager::AddKey(YT_KEY key, BYTE input, GPAD_KEY gPad)
{
	tagKeyState keystate;
	keystate.BKey = input;
	keystate.ytkey = key;
	keystate.padkey = gPad;
	m_vKeyState.push_back(keystate);
	m_bKeyState[m_vKeyState.size() - 1] = false;
}


//Key Up
bool CInputManager::KeyUp(YT_KEY input)
{
	if (IsGamepadConnected())
		return KeyPadUp(input);
	return KeyBoardUp(input);
}
bool CInputManager::KeyBoardUp(YT_KEY input)
{
	if (pKeysBuffer[m_vKeyState[input].BKey] & 0xF0)
	{
		m_vKeyState[input].bUpCheck = true;
		return false;
	}
	else if (m_vKeyState[input].bUpCheck)
	{
		m_bKeyState[input] = false;
		m_vKeyState[input].bUpCheck = false;
		m_bInputQueue.push_back(KeyStateCheck(input, false));
		return true;
	}
	return false;
}
bool CInputManager::KeyPadUp(YT_KEY input)
{
	if (m_vKeyState[input].bUpCheck)
	{
		m_vKeyState[input].bUpCheck = false;
		return true;
	}
	return false;
}

//Only KeyDown
bool CInputManager::OnlyKeyDown(YT_KEY input)
{
	if (IsGamepadConnected())
		return OnlyKeyPadDown(input);
	return OnlyKeyBoardDown(input);
}
bool CInputManager::OnlyKeyBoardDown(YT_KEY input)
{
	if (pKeysBuffer[m_vKeyState[input].BKey] & 0x80)
	{
		if (!m_bKeyState[input])
		{
			m_bInputQueue.push_back(KeyStateCheck(input, true));
			m_bKeyState[input] = true;
			return true;
		}
	}
	return false;
}
bool CInputManager::OnlyKeyPadDown(YT_KEY input)
{
	//RSH '16.08.04
	/*
	일반키와 다른 트리거를 예외처리
	*/
	bool press = false;

	if (input == YT_KEY::YK_SPACE)
	{
		press = static_cast<bool>(m_xGamepadState.Gamepad.bLeftTrigger != NULL);
	}
	else if (input == YT_KEY::YK_LSHIFT)
	{
		press = static_cast<bool>(m_xGamepadState.Gamepad.bRightTrigger != NULL);
	}
	else
	{
		press = static_cast<bool>((m_xGamepadState.Gamepad.wButtons & (WORD)(m_vKeyState[input].padkey)));
	}
	if (press)
	{
		if (!m_bKeyState[input])
		{
			m_bInputQueue.push_back(KeyStateCheck(input, true));
			m_bKeyState[input] = true;
			m_vKeyState[input].bUpCheck = false;
			return true;
		}
	}
	return false;
}

//KeyDown
bool CInputManager::KeyDown(YT_KEY input)
{
	if (IsGamepadConnected())
		return KeyPadDown(input);
	return KeyBoardDown(input);
}
bool CInputManager::KeyBoardDown(YT_KEY input)
{
	if (pKeysBuffer[m_vKeyState[input].BKey] & 0xF0)
	{
		if (!m_bKeyState[input])
		{
			m_bInputQueue.push_back(KeyStateCheck(input, true));
			m_bKeyState[input] = true;
		}
		return true;
	}
	return false;
}
bool CInputManager::KeyPadDown(YT_KEY input)
{
	// -1 안눌림
	//  0 
	//  1 뭐라도눌림

	//RSH '16.08.04
	/*
	일반키와 다른 트리거, 조이스틱을 예외처리
	*/
	int press = -1;

	if (input == YT_KEY::YK_LEFT)
		press = IsGamepadLeftThumb_outsideDeadzoneLeft() ? 1 : -1;

	if (input == YT_KEY::YK_RIGHT)
		press = IsGamepadLeftThumb_outsideDeadzoneRight() ? 1 : -1;

	if (input == YT_KEY::YK_UP)
		press = IsGamepadLeftThumb_outsideDeadzoneUp() ? 1 : -1;

	if (input == YT_KEY::YK_DOWN)
		press = IsGamepadLeftThumb_outsideDeadzoneDown() ? 1 : -1;


	//--- 여기서 1이란거는 스틱으로 눌린 의미입니다.
	if (press == 1) m_vKeyState[input].bStick = true;
	//--- 여기서 1이란거는 스틱으로 눌린 의미입니다

	if (input == YT_KEY::YK_SPACE)
		press = (m_xGamepadState.Gamepad.bLeftTrigger) ? 1 : 0;

	if (input == YT_KEY::YK_LSHIFT)
		press = (m_xGamepadState.Gamepad.bRightTrigger) ? 1 : 0;

	if (-1 == press)
		press = ((m_xGamepadState.Gamepad.wButtons & m_vKeyState[input].padkey)) ? 1 : -1;

	if (1 == press)
	{
		if (false == m_bKeyState[input])
		{
			m_bInputQueue.push_back(KeyStateCheck(input, true));
			m_bKeyState[input] = true;
			m_vKeyState[input].bUpCheck = false;
		}
		return true;
	}
	return false;
}

//Show
void CInputManager::ShowQueue()
{
	//gotoxy(0, 0);
	for (auto &q : m_bInputQueue)
	{
		KeyStateCheck check = q;
		std::cout << "[Key : " << m_stHashTable[check.key] << " ------ ";

		if (check.bDown)
			std::cout << "True]" << std::endl;

		else
			std::cout << "False]" << std::endl;
	}
	if (m_bInputQueue.size() > 12)
		m_bInputQueue.clear();
}


BYTE CInputManager::AnyOneKeyDown(int n, YT_KEY ...)
{
	if (false == m_bKeyBoardPressCheck) return false;

	va_list _ArgList;
	va_start(_ArgList, n);
	bool press = false;
	while (n--)
	{
		auto input = va_arg(_ArgList, YT_KEY);
		press = OnlyKeyDown(input);
		if (press) return press;
	}
	return press;
}

void CInputManager::SetWheel(int wheel)
{
	if (wheel > WHEEL_NON)   m_sWheel = WHEEL_UP;
	else if (wheel < WHEEL_NON) m_sWheel = WHEEL_DOWN;
	else                  m_sWheel = WHEEL_NON;
}

void CInputManager::MouseWheel()
{
	if (GetAsyncKeyState(VK_MBUTTON) & 0x8000)
		std::cout << "0x800" << std::endl;

	if (GetAsyncKeyState(VK_MBUTTON) & 0xF0)
		std::cout << "0xF0" << std::endl;

	if (GetAsyncKeyState(VK_MBUTTON) & 0x00)
		std::cout << "0x00" << std::endl;

	if (GetAsyncKeyState(VK_MBUTTON) & 0x01)
		std::cout << "0x01" << std::endl;

	if (GetAsyncKeyState(VK_MBUTTON))
		std::cout << "VK_MBUTTON" << std::endl;
}

void CInputManager::SetMousePoint(int x, int y)
{
	pt.x = x; pt.y = y;
}

bool CInputManager::MouseLeftDown()
{
	return m_bLeftCheck;
}

bool CInputManager::MouseRightDown()
{
	return m_bLeftCheck;
}

//^ 같으면 1, 다르면 0
bool CInputManager::MouseLeftUp()
{
	return (m_bLeftCheck ^ false);
}

bool CInputManager::MouseRightUp()
{
	return (m_bRightCheck ^ false);
}

void CInputManager::SetMousePoint(POINT _pt)
{
	pt = _pt;
}
//

void CInputManager::ShowInputData()
{
	while (!m_bInputQueue.empty())
	{
		KeyStateCheck check = m_bInputQueue.front();
		m_bInputQueue.pop_front();
		std::cout << "[Key : " << m_stHashTable[check.key] << " ------ ";

		if (check.bDown)
			std::cout << "True]" << std::endl;

		else
			std::cout << "False]" << std::endl;
	}
}

//JJY 16'.04.18
/*
플레이어 InputDataSending함수 추가
*/

std::deque<KeyStateCheck> CInputManager::GetInputQueue()
{
	auto dequeue = m_bInputQueue;
	return dequeue;
}

XINPUT_GAMEPAD CInputManager::GetGamepad()
{
	ZeroMemory(&m_xGamepadState, sizeof(XINPUT_STATE));

	//번호에 해당하는 게임패드에 상태를 받는다.
	//(1개의 패드만 입력 받으므로 번호는 0번을 기본으로 한다. )
	XInputGetState(0, &m_xGamepadState);

	return m_xGamepadState.Gamepad;
}

void CInputManager::IsGamepadConnected(bool* connect)
{
	ZeroMemory(&m_xGamepadState, sizeof(XINPUT_STATE));
	*connect = (XInputGetState(0, &m_xGamepadState) == ERROR_SUCCESS);
}

bool CInputManager::IsGamepadRightThumb_outsideDeadzoneX()
{
	if (!m_bConnect)return true;
	auto RX = GetGamepad().sThumbRX;
	return (!(-XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE < RX && RX < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE));
}


bool CInputManager::IsGamepadRightThumb_outsideDeadzoneY()
{
	if (!m_bConnect)return !m_bConnect;
	auto RY = GetGamepad().sThumbRY;
	return (!(-XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE < RY && RY < XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE));
}

bool CInputManager::IsGamepadRightThumb_outsideDeadzone()
{
	if (!IsGamepadConnected()) return false;
	return (IsGamepadRightThumb_outsideDeadzoneX() || IsGamepadRightThumb_outsideDeadzoneY());
}


//-----------------------------------------------  Left_Thumb
bool CInputManager::IsGamepadLeftThumb_outsideDeadzoneX()
{
	if (!m_bConnect)return !m_bConnect;
	auto LX = GetGamepad().sThumbLX;
	return (!(-XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE < LX && LX < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE));
}

bool CInputManager::IsGamepadLeftThumb_outsideDeadzoneY()
{
	if (!m_bConnect)return !m_bConnect;
	auto LY = GetGamepad().sThumbLY;
	return (!(-XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE < LY && LY < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE));
}

//--------------------------------------------------------------------------------------------
bool CInputManager::IsGamepadLeftThumb_outsideDeadzone()
{
	return (IsGamepadLeftThumb_outsideDeadzoneX() || IsGamepadLeftThumb_outsideDeadzoneY());
}
//--------------------------------------------------------------------------------------------



//----------------------------------------------- LEFT 
bool CInputManager::IsGamepadLeftThumb_outsideDeadzoneLeft()
{
	if (!m_bConnect)return !m_bConnect;
	auto LX = GetGamepad().sThumbLX;
	return (LX < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
}

bool CInputManager::IsGamepadLeftThumb_outsideDeadzoneRight()
{
	if (!m_bConnect)return !m_bConnect;
	auto LX = GetGamepad().sThumbLX;
	return (XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE < LX);
}

bool CInputManager::IsGamepadLeftThumb_outsideDeadzoneUp()
{
	if (!m_bConnect)return !m_bConnect;
	auto LY = GetGamepad().sThumbLY;
	return (XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE < LY);
}

bool CInputManager::IsGamepadLeftThumb_outsideDeadzoneDown()
{
	if (!m_bConnect)return !m_bConnect;
	auto LY = GetGamepad().sThumbLY;
	return (LY < -XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE);
}

void CInputManager::StartVibrate(const int& leftVal, const int& rightVal)
{
	if (!m_bConnect)return;
	if (m_bVibrate)return;
	XINPUT_VIBRATION Vibration;
	Vibration.wLeftMotorSpeed = static_cast<WORD>(leftVal);
	Vibration.wRightMotorSpeed = static_cast<WORD>(rightVal);
	XInputSetState(0, &Vibration);
	m_bVibrate = true;
}

void CInputManager::StartLeftVibrate(const int& vibrate)
{
	if (!m_bConnect)return;
	if (m_bVibrate)return;
	XINPUT_VIBRATION Vibration;
	Vibration.wLeftMotorSpeed = static_cast<WORD>(vibrate);
	Vibration.wRightMotorSpeed = static_cast<WORD>(0);
	XInputSetState(0, &Vibration);
	m_bVibrate = true;
}

void CInputManager::StartRightVibrate(const int& vibrate)
{
	if (!m_bConnect)return;
	if (m_bVibrate)return;
	m_bVibrate = true;
	XINPUT_VIBRATION Vibration;

	Vibration.wLeftMotorSpeed = static_cast<WORD>(0);
	Vibration.wRightMotorSpeed = static_cast<WORD>(vibrate);

	XInputSetState(0, &Vibration);
}

void CInputManager::StopVibrate(const int& leftVal, const int& rightVal)
{
	m_bVibrate = false;
	m_fVibrateionFrame = 0.0f;

	XINPUT_VIBRATION Vibration;
	Vibration.wLeftMotorSpeed = static_cast<WORD>(leftVal);
	Vibration.wRightMotorSpeed = static_cast<WORD>(rightVal);
	XInputSetState(0, &Vibration);
}
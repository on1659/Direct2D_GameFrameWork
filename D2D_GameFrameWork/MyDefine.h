#pragma once


#define FRAMEWORK					CGameFrameWork_D2D::GetInstance()
#define TIMER						CGameTimer::GetInstance()
#define RENDERMGR_2D				CRenderManager_2D::GetInstance()
#define MY_COLOR(X)					MyColor::GetInstance()->GetColor(X)
#define INPUT						CInputManager::GetInstance()
#define Input						CInputManager::GetInstance()
		
#define TITLE_MAX_LENGTH			64



#define FRAME_WIDTH					720
#define FRAME_HEIGHT				720

#define  WIDTH						FRAME_WIDTH
#define  HEIGHT						FRAME_HEIGHT
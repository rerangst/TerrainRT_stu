#pragma once
#ifndef  APPLICATIONCLASS_H
#define APPLICATIONCLASS_H
/////////////
// GLOBALS //
/////////////
const bool FULL_SCREEN = true;
const bool VSYNC_ENABLED = false;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "InputClass.h"
#include "D3dClass.h"
#include "shadermanagerclass.h"
#include "timerclass.h"
#include "fpsclass.h"
#include "zoneclass.h"

////////////////////////////////////////////////////////////////////////////////
// Class name: ApplicationClass
////////////////////////////////////////////////////////////////////////////////
class ApplicationClass
{
	InputClass* m_Input;
	D3dClass* m_Direct3D;
	ShaderManagerClass* m_ShaderManager;
	TimerClass* m_Timer;
	FpsClass* m_Fps;
	ZoneClass* m_Zone;

public:
	ApplicationClass();	
	~ApplicationClass();

	bool Initialize(HINSTANCE hinstance, HWND hwnd, int screenWidth, int screenHeight);
	void Shutdown();
	bool Frame();	
};

#endif // ! APPLICATIONCLASS_H



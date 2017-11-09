#pragma once
#ifndef ZONECLASS_H
#define ZONECLASS_H
//The zone class is the main wrapper class for all of the terrain processing
//ex: move the camera, expanded to handle sky, trees, foliage...
#include "D3dClass.h"
#include "InputClass.h"
#include "shadermanagerclass.h"
#include "timerclass.h"
#include "userinterfaceclass.h"
#include "cameraclass.h"
#include "positionclass.h"
#include "terrainclass.h"
class ZoneClass
{
	void HandleMovementInput(InputClass* Input, float frameTime);
	bool Render(D3dClass* Direct3D, ShaderManagerClass* ShaderManager);


	UserInterfaceClass* m_UserInterface;
	CameraClass* m_Camera;
	PositionClass* m_Position;
	TerrainClass* m_Terrain;
	bool m_displayUI, m_wireFrame;
public:
	ZoneClass();
	~ZoneClass();

	bool Initialize(D3dClass * Direct3D, HWND hwnd, int screenWidth, int screenHeight, float screenDepth);
	void Shutdown();
	bool Frame(D3dClass*, InputClass*, ShaderManagerClass*, float, int);

};

#endif // !ZONECLASS_H



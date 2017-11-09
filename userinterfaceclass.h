////////////////////////////////////////////////////////////////////////////////
// Filename: userinterfaceclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _USERINTERFACECLASS_H_
#define _USERINTERFACECLASS_H_


///////////////////////
// MY CLASS INCLUDES //
///////////////////////
#include "textclass.h"


////////////////////////////////////////////////////////////////////////////////
// Class name: UserInterfaceClass
////////////////////////////////////////////////////////////////////////////////
class UserInterfaceClass
{
public:
	UserInterfaceClass();
	UserInterfaceClass(const UserInterfaceClass&);
	~UserInterfaceClass();

	bool Initialize(D3dClass*, int, int);
	void Shutdown();
	
	bool Frame(ID3D11DeviceContext*, int, float, float, float, float, float, float);
	bool Render(D3dClass* Direct3D, ShaderManagerClass* ShaderManager, D3DXMATRIX worldMatrix,
		D3DXMATRIX viewMatrix, D3DXMATRIX orthoMatrix);

private:
	bool UpdateFpsString(ID3D11DeviceContext*, int);
	bool UpdatePositionStrings(ID3D11DeviceContext*, float, float, float, float, float, float);

private:
	FontClass* m_Font1;
	TextClass *m_FpsString, *m_VideoStrings, *m_PositionStrings;
	TextClass *m_memoryString;
	int m_previousFps;
	int m_previousPosition[6];
};

#endif
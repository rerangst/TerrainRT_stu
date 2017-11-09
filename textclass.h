////////////////////////////////////////////////////////////////////////////////
// Filename: textclass.h
////////////////////////////////////////////////////////////////////////////////
#ifndef _TEXTCLASS_H_
#define _TEXTCLASS_H_


//////////////
// INCLUDES //
//////////////
#include "fontclass.h"
#include "shadermanagerclass.h"


////////////////////////////////////////////////////////////////////////////////
// Class name: TextClass
////////////////////////////////////////////////////////////////////////////////
class TextClass
{
private:
	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR2 texture;
	};

public:
	TextClass();
	TextClass(const TextClass&);
	~TextClass();

	bool Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, int screenWidth, int screenHeight, int maxLength,
		bool shadow, FontClass* Font, char* text, int positionX, int positionY, float red, float green, float blue);
	void Shutdown();
	void Render(ID3D11DeviceContext* deviceContext, ShaderManagerClass* ShaderManager, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix,
		D3DXMATRIX orthoMatrix, ID3D11ShaderResourceView* fontTexture);

	bool UpdateSentence(ID3D11DeviceContext* deviceContext, FontClass* Font, char* text, int positionX, int positionY, float red,
		float green, float blue);

private:
	bool InitializeSentence(ID3D11Device*, ID3D11DeviceContext*, FontClass*, char*, int, int, float, float, float);
	void RenderSentence(ID3D11DeviceContext* deviceContext, ShaderManagerClass* ShaderManager, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix,
		D3DXMATRIX orthoMatrix, ID3D11ShaderResourceView* fontTexture);

private:
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer, *m_vertexBuffer2, *m_indexBuffer2;
	int m_screenWidth, m_screenHeight, m_maxLength, m_vertexCount, m_indexCount;
	bool m_shadow;
	D3DXVECTOR4 m_pixelColor;
};

#endif
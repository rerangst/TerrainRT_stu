#pragma once
#ifndef TERRAINCLASS_H
#define TERRAINCLASS_H
#include <d3d11.h>
#include <D3DX10math.h>
//#include <xnamath.h>

class TerrainClass
{
	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR4 color;
	};
	//
	bool InitializeBuffers(ID3D11Device* device);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext* deviceContext);
	//
	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;

public:
	TerrainClass();
	~TerrainClass();

	bool Initialize(ID3D11Device* device);
	void Shutdown();
	bool Render(ID3D11DeviceContext* deviceContext);

	int GetIndexCount();
};


#endif // !TERRAINCLASS_H



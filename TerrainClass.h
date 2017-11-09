#pragma once
#ifndef TERRAINCLASS_H
#define TERRAINCLASS_H
#include <d3d11.h>
#include <D3DX10math.h>
#include <fstream>
#include <stdio.h>
using namespace std;

class TerrainClass
{
	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR4 color;
	};
	struct HeightMapType
	{
		float x, y, z;
	};
	struct ModelType
	{
		float x, y, z;
	};
	//
	bool InitializeBuffers(ID3D11Device* device);
	void ShutdownBuffers();
	void RenderBuffers(ID3D11DeviceContext* deviceContext);
	//
	bool LoadSetupFile(char * fileName);
	bool LoadBitmapHeightMap();
	void ShutdownHeightMap();
	void SetTerrainCoordinates();
	bool BuildTerrainModel();
	void ShutdownTerrainModel();

	ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
	int m_vertexCount, m_indexCount;
	int m_terrainHeight, m_terrainWidth;
	//heightmap
	float m_heightScale;
	char* m_terrainFilename;
	HeightMapType* m_heightMap;
	ModelType* m_terrainModel;

public:
	TerrainClass();
	~TerrainClass();

	bool Initialize(ID3D11Device * device, char* setupFilename);
	void Shutdown();
	bool Render(ID3D11DeviceContext* deviceContext);

	int GetIndexCount();
};


#endif // !TERRAINCLASS_H



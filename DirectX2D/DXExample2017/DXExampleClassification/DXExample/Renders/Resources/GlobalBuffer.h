#pragma once

#include "stdafx.h"

class WorldBuffer : public ShaderBuffer
{
public:
	WorldBuffer() : ShaderBuffer(&data, sizeof(WorldStruct))
	{
		D3DXMatrixIdentity(&data.world);
	}

	void SetWorld(D3DXMATRIX world) 
	{
		D3DXMatrixTranspose(&data.world, &world);
	}

	struct WorldStruct
	{
		D3DXMATRIX world;
	};
private:
	WorldStruct data;

};

class ViewProjectionBuffer : public ShaderBuffer
{
public: 
	ViewProjectionBuffer() :ShaderBuffer(&data, sizeof(ViewProjStruct))
	{
		D3DXMatrixIdentity(&data.View);
		D3DXMatrixIdentity(&data.Projection);
	}
	void SetView(D3DXMATRIX view)
	{
		D3DXMatrixTranspose(&data.View, &view);
	}
	void SetProjection(D3DXMATRIX projection)
	{
		D3DXMatrixTranspose(&data.Projection, &projection);
	}
		
		
	struct ViewProjStruct
	{
		D3DXMATRIX View;
		D3DXMATRIX Projection;
	};

private :
	ViewProjStruct data;
};
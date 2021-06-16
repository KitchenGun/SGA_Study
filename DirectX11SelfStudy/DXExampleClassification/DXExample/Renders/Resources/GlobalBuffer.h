#pragma once

#include "stdafx.h"
//world & view,projection �̷��� ���������� �̵��� �����Ҷ� world ��ĸ� ������ �Ǳ⶧���̴�
//dx ��켱 gpu ���켱 ��� �׷��� ������ ��ġ ����� �ʿ���

class WorldBuffer : public ShaderBuffer
{
public:
	WorldBuffer() : ShaderBuffer(&data, sizeof(WorldStruct))
	{
		//�׵��࿭
		D3DXMatrixIdentity(&data.world);
	}

	void SetWorld(D3DXMATRIX world) 
	{
		//��ġ ��Ų��
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
		//�׵��࿭
		D3DXMatrixIdentity(&data.View);
		D3DXMatrixIdentity(&data.Projection);
	}
	void SetView(D3DXMATRIX view)
	{
		//��ġ ��Ų��
		D3DXMatrixTranspose(&data.View, &view);
	}
	void SetProjection(D3DXMATRIX projection)
	{
		//��ġ ��Ų��
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

class ColorBuffer : ShaderBuffer
{
public:
	ColorBuffer() : ShaderBuffer(&data, sizeof(Struct))
	{
		data.color = D3DXCOLOR(0, 0, 0, 1);
	}

	void SetColor(D3DXCOLOR color)
	{
		data.color = color;
	}

	struct Struct
	{
		D3DXCOLOR color;
	};

private:
	Struct data;
};
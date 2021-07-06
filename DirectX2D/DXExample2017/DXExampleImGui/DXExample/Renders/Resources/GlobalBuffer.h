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

	void SetWorld(Matrix world) 
	{
		//��ġ ��Ų��
		D3DXMatrixTranspose(&data.world, &world);
	}

	struct WorldStruct
	{
		Matrix world;
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
	void SetView(Matrix view)
	{
		//��ġ ��Ų��
		D3DXMatrixTranspose(&data.View, &view);
	}
	void SetProjection(Matrix projection)
	{
		//��ġ ��Ų��
		D3DXMatrixTranspose(&data.Projection, &projection);
	}
		
		
	struct ViewProjStruct
	{
		Matrix View;
		Matrix Projection;
	};

private :
	ViewProjStruct data;
};

class ColorBuffer : public ShaderBuffer
{
public:
	ColorBuffer() : ShaderBuffer(&data, sizeof(Struct))
	{
		data.color = Color(0, 0, 0, 1);
	}

	void SetColor(Color color)
	{
		data.color = color;
	}

	struct Struct
	{
		Color color;
	};

private:
	Struct data;
};
#include "stdafx.h"
#include "Scene8_Texture2D.h"

Scene8::Scene8()
{
	//loadinfo = nullptr상태 정의 안해줌
	tex2D = new Texture2D(L"./_Textures/Image2.png");

	vector<D3DXCOLOR> color;
	DirectX::TexMetadata metaData;
	tex2D->GetImageInfo(&metaData);
	tex2D->ReadPixel(metaData.format, &color);

	ID3D11Texture2D* originalTex;
	tex2D->GetSRV()->GetResource((ID3D11Resource**)&originalTex);
	tex2D->SaveFile(L"./Test.png", originalTex, color, tex2D->GetWidth(), tex2D->GetHeight());
}

Scene8::~Scene8()
{
	SAFE_DELETE(textureRect);
}

void Scene8::Init()
{
	textureRect = new TextureRect(Vector3(100, 100, 0), Vector3(100, 100, 1), 0);
	textureRect->SetSRV(tex2D->GetSRV());
}

void Scene8::Update()
{
	
}

void Scene8::PreRender()
{
}

void Scene8::Render()
{
	textureRect->Render();
}

void Scene8::PostRender()
{
	
}

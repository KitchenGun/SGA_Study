#include "stdafx.h"
#include "Texture2D.h"


using namespace DirectX;

vector<TextureDesc> Textures::descs;

Texture2D::Texture2D(wstring filePath, D3DX11_IMAGE_LOAD_INFO * loadInfo)
	: filePath(filePath)
{
	Textures::Load(this, loadInfo);
}

Texture2D::~Texture2D()
{
}

D3D11_TEXTURE2D_DESC Texture2D::ReadPixel(DXGI_FORMAT readFormat, vector<D3DXCOLOR>* pixels)
{
	ID3D11Texture2D* srcTexture;
	view->GetResource((ID3D11Resource**)&srcTexture);

	return ReadPixel(srcTexture, readFormat, pixels);
}

D3D11_TEXTURE2D_DESC Texture2D::ReadPixel(ID3D11Texture2D * src, DXGI_FORMAT readFormat, vector<D3DXCOLOR>* pixels)
{
	D3D11_TEXTURE2D_DESC srcDesc;
	src->GetDesc(&srcDesc);

	D3D11_TEXTURE2D_DESC desc;
	ZeroMemory(&desc, sizeof(D3D11_TEXTURE2D_DESC));
	desc.Width = srcDesc.Width;
	desc.Height = srcDesc.Height;
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.Format = readFormat;
	desc.SampleDesc = srcDesc.SampleDesc;
	desc.CPUAccessFlags = D3D11_CPU_ACCESS_READ;
	desc.Usage = D3D11_USAGE_STAGING;

	ID3D11Texture2D* texture;
	ASSERT(DEVICE->CreateTexture2D(&desc, nullptr, &texture));
	ASSERT(D3DX11LoadTextureFromTexture(DC, src, nullptr, texture));

	UINT* colors = new UINT[desc.Width * desc.Height];
	D3D11_MAPPED_SUBRESOURCE subResource;
	DC->Map(texture, 0, D3D11_MAP_READ, NULL, &subResource);
	{
		memcpy(colors, subResource.pData, sizeof(UINT) * desc.Width * desc.Height);
	}
	DC->Unmap(texture, 0);

	for (UINT y = 0; y < desc.Height; y++)
	{
		for (UINT x = 0; x < desc.Width; x++)
		{
			UINT index = desc.Width * y + x;

			float f = 1.0f / 255.0f;

			float b = f * (float)((0x000000FF & colors[index]) >> 0);
			float g = f * (float)((0x0000FF00 & colors[index]) >> 8);
			float r = f * (float)((0x00FF0000 & colors[index]) >> 16);
			float a = f * (float)((0xFF000000 & colors[index]) >> 24);

			pixels->push_back(D3DXCOLOR(r, g, b, a));
		}
	}

	SAFE_DELETE_ARRAY(colors);
	SAFE_RELEASE(texture);

	return desc;
}

void Texture2D::SaveFile(wstring filePath)
{
	ID3D11Texture2D* srcTexture;
	view->GetResource((ID3D11Resource**)&srcTexture);

	SaveFile(filePath, srcTexture);
}

void Texture2D::SaveFile(wstring filePath, ID3D11Texture2D * originalTex, vector<D3DXCOLOR>& pixels, UINT width, UINT height)
{
	view->GetResource((ID3D11Resource**)&originalTex);
	D3D11_TEXTURE2D_DESC originalDesc;
	originalTex->GetDesc(&originalDesc);

	ID3D11Texture2D* srcTexture;
	D3D11_TEXTURE2D_DESC destDesc;
	ZeroMemory(&destDesc, sizeof(D3D11_TEXTURE2D_DESC));
	destDesc.Width = width;
	destDesc.Height = height;
	destDesc.MipLevels = 1;
	destDesc.ArraySize = 1;
	destDesc.Format = originalDesc.Format;
	destDesc.SampleDesc = originalDesc.SampleDesc;
	destDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	destDesc.Usage = D3D11_USAGE_STAGING;

	HRESULT hr = DEVICE->CreateTexture2D(&destDesc, nullptr, &srcTexture);
	ASSERT(hr);

	UINT* rawPixels = new UINT[width * height];
	for (UINT y = 0; y < height; y++)
	{
		for (UINT x = 0; x < width; x++)
		{
			UINT index = width * y + x;

			rawPixels[index] = pixels[index];
		}
	}

	D3D11_MAPPED_SUBRESOURCE subResource;
	DC->Map(srcTexture, 0, D3D11_MAP_WRITE, NULL, &subResource);
	{
		memcpy(subResource.pData, rawPixels, sizeof(UINT) * width * height);
	}
	DC->Unmap(srcTexture, 0);

	SAFE_DELETE_ARRAY(rawPixels);

	SaveFile(filePath, srcTexture);
}

void Texture2D::SaveFile(wstring file, ID3D11Texture2D * src)
{
	D3D11_TEXTURE2D_DESC srcDesc;
	src->GetDesc(&srcDesc);

	ID3D11Texture2D* dest;
	D3D11_TEXTURE2D_DESC destDesc;
	ZeroMemory(&dest, sizeof(D3D11_TEXTURE2D_DESC));
	destDesc.Width = srcDesc.Width;
	destDesc.Height = srcDesc.Height;
	destDesc.MipLevels = 1;
	destDesc.ArraySize = 1;
	destDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
	destDesc.SampleDesc = srcDesc.SampleDesc;
	destDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	destDesc.Usage = D3D11_USAGE_STAGING;

	HRESULT hr = DEVICE->CreateTexture2D(&destDesc, nullptr, &dest);
	ASSERT(hr);

	hr = D3DX11LoadTextureFromTexture(DC, src, nullptr, dest);
	ASSERT(hr);

	wstring ext = Path::GetExtension(file);
	transform(ext.begin(), ext.end(), ext.begin(), toupper);

	if (ext == L"BMP")
		hr = D3DX11SaveTextureToFile(DC, dest, D3DX11_IFF_BMP, file.c_str());
	else
		hr = D3DX11SaveTextureToFile(DC, dest, D3DX11_IFF_PNG, file.c_str());

	ASSERT(hr);

	SAFE_RELEASE(dest);
}

ID3D11Texture2D * Texture2D::GetTexture()
{
	return nullptr;
}

void Textures::Create()
{
}

void Textures::Delete()
{
}

void Textures::Load(Texture2D * texture, D3DX11_IMAGE_LOAD_INFO * loadInfo)
{
}

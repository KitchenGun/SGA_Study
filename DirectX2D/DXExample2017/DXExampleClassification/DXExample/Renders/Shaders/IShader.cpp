#include "stdafx.h"
#include "IShader.h"

IShader::IShader()
{
}


void IShader::CompileShader(wstring path, string entryName, string profile, ID3DBlob ** blob)
{
	this->path = path;
	this->entryName = entryName;
	this->profile = profile;

	ID3DBlob* error = nullptr;
	HRESULT hr = D3DCompileFromFile
	(
		path.c_str(),
		nullptr,
		nullptr,
		entryName.c_str(),
		profile.c_str(),
		D3DCOMPILE_ENABLE_STRICTNESS,//flag 옛 구문 사용 안함
		0,
		blob,
		&error //에러 추가
	);
	CheckShaderError(hr, error);
	SAFE_RELEASE(error);
}

void IShader::CheckShaderError(HRESULT hr, ID3DBlob * error)
{
	if (FAILED(hr))
	{
		if (error)
		{
			string str = (const char*)error->GetBufferPointer();
			MessageBoxA(NULL, str.c_str(), "Shader Error", MB_OK);
		}
		ASSERT(false);
	}
}

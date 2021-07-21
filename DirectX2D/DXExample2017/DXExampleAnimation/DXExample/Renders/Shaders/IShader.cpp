#include "stdafx.h"
#include "IShader.h"

IShader::IShader()
{
}


void IShader::CompileShader(wstring path, string entryName, string profile, ID3DBlob ** blob)
{//���������͸� ����� �Լ�
	this->path = path;
	this->entryName = entryName;
	this->profile = profile;

	ID3DBlob* error = nullptr;
	HRESULT hr = D3DCompileFromFile
	(
		path.c_str(),												//�����̸�
		nullptr,													//hlsl define ���� �κ�
		//#include�� hlsl���� �����ֵ��� �ϴ� �ɼ�
		D3D_COMPILE_STANDARD_FILE_INCLUDE,							//hlsl include ���� �κ�
		entryName.c_str(),											//������ ������ ���� �������� ����ϴ� �Լ� ���� �κ�(������ �Լ� �̸�)
		profile.c_str(),											//���̴� �� ���� ����
		D3DCOMPILE_ENABLE_STRICTNESS,	//flag �� ���� ��� ����		//���̴� ������ �÷��� //Ư�� ���� ���� ���θ� �����ϴ� ���̴�
		0,															//ȿ�� ������ �÷���	//Ư�� ���� ���� ���θ� �����ϴ� ���̴�(���� �ʿ���� 0)
		blob,														//���� �������� ����  -> ��ǻ�Ͱ� ���� �� �ִ� ����� ����� ���� ���̳ʸ�����������Ʈ
		&error //���� �߰�											//error msg
	);																
	CheckShaderError(hr, error);									//������ ������ Ȯ�ο�
	SAFE_RELEASE(error);
}

void IShader::CheckShaderError(HRESULT hr, ID3DBlob * error)
{
	if (FAILED(hr))
	{
		if (error)
		{
			string str = (const char*)error->GetBufferPointer();	
			MessageBoxA(NULL, str.c_str(), "Shader Error", MB_OK);	//�����޼����� �޼��� �ڽ�(ok��ư�� �����ϴ�)�� ���� ����
		}
		ASSERT(false);
	}
}

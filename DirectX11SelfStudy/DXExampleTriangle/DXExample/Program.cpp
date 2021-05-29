#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	//vertexdata
	{
		vertices = new VertexColor[9];
		vertices[0].position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		vertices[0].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		vertices[1].position = D3DXVECTOR3(0.5, 0.0f, 0.0f);
		vertices[1].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		vertices[2].position = D3DXVECTOR3(0.65f, -0.45f, 0.0f);
		vertices[2].color = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);

		vertices[3].position = D3DXVECTOR3(0.3f, 0.0f, 0.0f);
		vertices[3].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		vertices[4].position = D3DXVECTOR3(0.8f, 0.0f, 0.0f);
		vertices[4].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		vertices[5].position = D3DXVECTOR3(0.15f, -0.45f, 0.0f);
		vertices[5].color = D3DXCOLOR(1.0f, 0.0f, 1.0f, 1.0f);

		vertices[6].position = D3DXVECTOR3(0.4f, 0.35f, 0.0f);
		vertices[6].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		vertices[7].position = D3DXVECTOR3(0.55f, -0.2f, 0.0f);
		vertices[7].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		vertices[8].position = D3DXVECTOR3(0.15f, -0.45f, 0.0f);
		vertices[8].color = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	}
	//vertex buffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		D3D11_SUBRESOURCE_DATA subData;//���� �ڿ�������  ->��ǻ� ���ҽ����� �ִ� ���� ������
		ZeroMemory(&subData, sizeof(D3D11_SUBRESOURCE_DATA));
		CreateVertexBuffer(desc, subData, *vertexBuffer,vertices);
		HRESULT hr = Graphics::Get()->GetDevice()->CreateBuffer(&desc, &subData, &vertexBuffer);
		assert(SUCCEEDED(hr));

	}

	//vertex shader
	{
		HRESULT hr = D3DX11CompileFromFileA//� ���Ϸ� ���� ����� �����ϴ� ����
		(
			"./Color.hlsl",					//�����̸�
			nullptr,						//hlsl define ���� �κ�
			nullptr,						//hlsl include ���� �κ�
			"VS",							//������ ������ ���� �������� ����ϴ� �Լ� ���� �κ�(������ �Լ� �̸�)
			"vs_5_0",						//���̴� �� 5.0�� ����Ѵ�  ���� ����
			0,								//���̴� ������ �÷��� //Ư�� ���� ���� ���θ� �����ϴ� ���̴�(���� �ʿ���� 0)
			0,								//ȿ�� ������ �÷���	//Ư�� ���� ���� ���θ� �����ϴ� ���̴�(���� �ʿ���� 0)
			nullptr,						//������ �����忡�� �񵿱������� �����ϰ� ������ 
			&vsBlob,						//���� �������� ����  -> ��ǻ�Ͱ� ���� �� �ִ� ����� ����� ���� ���̳ʸ�����������Ʈ��
			nullptr,						//error msg
			nullptr							//����� ���ÿ� hr������⶧���� ���� ��ȯ �ʿ����
		);
		//��� vsBlob�� hlsl���� �Է� ������ �����ϰ� ���� �ܰ踦 ���� �غ� �Ѵ�
		assert(SUCCEEDED(hr));

		hr = Graphics::Get()->GetDevice()->CreateVertexShader
		(
			vsBlob->GetBufferPointer(),   //Ư���� ���¶� �̷������� �ҷ��;��Ѵ�
			vsBlob->GetBufferSize(),
			nullptr,
			&vertexShader
		);
		assert(SUCCEEDED(hr));
	}
	//inputLayout �� �ֵ��� ��ġ �迭
	{
		D3D11_INPUT_ELEMENT_DESC LayoutDesc[]
		{
			{
				"POSITION",					//�ø�ƽ �̸�
				0,							//�ø�ƽ �ε��� 
				DXGI_FORMAT_R32G32B32_FLOAT,//����						//��ä�δ� �� ��Ʈ���� �˷��ִ¿��̴�. ���� 32��Ʈ �� 4����Ʈ  vector3 = 4*8��Ʈ(1����Ʈ) 
				0,							//��ǲ ����					//gpu�� �ѱ�� 16���� vertex buffer�� ã�� ���� ���̴� 
				0,							//AlignedByteOffset			//���������� �󸶳� �������ִ°� ���� �Է��� �޸��� ũ�⸦ ���ϴ� ���̴�.
				D3D11_INPUT_PER_VERTEX_DATA,//InputSlotClass			//���ø����̼� �ν��Ͻ̿� ����Ѵ� (���� �뵵�� ���� 3d���� ���� ��)
				0							//�ν��Ͻ� ������ ���ܷ���Ʈ //���� �ν��Ͻ��� Ȱ���
			},
			{
				"COLOR",
				0,
				DXGI_FORMAT_R32G32B32A32_FLOAT,
				0,
				sizeof(D3DXVECTOR3),
				D3D11_INPUT_PER_VERTEX_DATA,
				0
			},
		};
		HRESULT hr = Graphics::Get()->GetDevice()->CreateInputLayout
		(
			LayoutDesc,
			2,
			vsBlob->GetBufferPointer(),
			vsBlob->GetBufferSize(),
			&inputLayout
		);
		assert(SUCCEEDED(hr));
	}

	//pixel shader
	{
		HRESULT hr = D3DCompileFromFile
		(
			L"./Color.hlsl",
			nullptr,
			nullptr,
			"PS",			//function ���Ӱ� ����
			"ps_5_0",
			0,
			0,
			&psBlob,
			nullptr
		);
		assert(SUCCEEDED(hr));
		
		hr = Graphics::Get()->GetDevice()->CreatePixelShader
		(
			psBlob->GetBufferPointer(),
			psBlob->GetBufferSize(),
			nullptr,
			&pixelShader
		);
		assert(SUCCEEDED(hr));

	}

}

Program::~Program()
{

	SAFE_RELEASE(pixelShader);
	SAFE_RELEASE(psBlob);
	SAFE_RELEASE(inputLayout);
	SAFE_RELEASE(vertexShader);
	SAFE_RELEASE(vsBlob);

	SAFE_RELEASE(vertexBuffer);

	SAFE_DELETE_ARRAY(vertices);

}

void Program::Update()
{
	
}

void Program::Render()
{
	UINT stride = sizeof(VertexColor);
	UINT offset = 0;

	Graphics::Get()->GetDC()->IASetVertexBuffers
	(
		0,
		1,
		&vertexBuffer,
		&stride,
		&offset
	);
	Graphics::Get()->GetDC()->IASetInputLayout
	(
		inputLayout
	);
	Graphics::Get()->GetDC()->IASetPrimitiveTopology
	(
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST
	);
	Graphics::Get()->GetDC()->VSSetShader
	(
		vertexShader,
		nullptr,
		0
	);
	Graphics::Get()->GetDC()->PSSetShader
	(
		pixelShader,
		nullptr,
		0
	);
	Graphics::Get()->GetDC()->Draw
	(
		9,
		0
	);
}

void Program::CreateVertexBuffer(D3D11_BUFFER_DESC &desc, D3D11_SUBRESOURCE_DATA &subData, ID3D11Buffer &buffer, VertexColor* vertices)
{
	desc.Usage = D3D11_USAGE_IMMUTABLE;//������ ���� �뵵 
	desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;//vertex ���� ��°� �˷��ִ¿뵵
	desc.ByteWidth = sizeof(VertexColor) * 9;

	subData.pSysMem = vertices;  //<-���� ������ �־������ ������ �ʱ�ȭ ���ִ� ����
}

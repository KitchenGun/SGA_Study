#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	//vertexdata  //local ��ǥ�� 
	{
		vertices = new VertexColor[4];
		vertices[0].position = D3DXVECTOR3(-0.5f, -0.5f, 0.0f);
		vertices[0].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		vertices[1].position = D3DXVECTOR3(-0.5f, 0.5f, 0.0f);
		vertices[1].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		vertices[2].position = D3DXVECTOR3(0.5f, -0.5f, 0.0f);
		vertices[2].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		vertices[3].position = D3DXVECTOR3(0.5f, 0.5f, 0.0f);
		vertices[3].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	}
	//vertex buffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));

		desc.Usage = D3D11_USAGE_IMMUTABLE;//������ ���� �뵵 
		/*
		���� ��Ŀ� ���� ������   (�ڿ� ������ �����ϸ� �����͸� �����Ҽ��ִ�)
		D3D11_USAGE_DEFAULT	= gpu�� ������ �а� �����ִ�
		D3D11_USAGE_IMMUTABLE = gpu�� �����͸� �б⸸ �Ѵ�/cpu���� ���������� �Ұ���/������ ���ÿ� �ʱ�ȭ�� �ؾ��Ѵ�/���� ������
		D3D11_USAGE_DYNAMIC	= gpu �б� ���	/cpu ���� ���  /�� ����� ����ؼ� cpu���� �����ؼ� ������ ������/cpu���� �������Ӵ� �ѹ��� ������Ʈ �ʿ��� �ڿ��� ���
		D3D11_USAGE_STAGING	= gpu �޸𸮿��� cpu �޸𸮷� ���� ��� (�б� ���� ���� �ٵ�)  /�ӵ��� ���� ����
		*/
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;//vertex ���� ��°� �˷��ִ¿뵵
		desc.ByteWidth = sizeof(VertexColor) * 4;
		
		D3D11_SUBRESOURCE_DATA subData;//���� �ڿ�������  ->��ǻ� ���ҽ����� �ִ� ���� ������
		ZeroMemory(&subData, sizeof(D3D11_SUBRESOURCE_DATA));
		subData.pSysMem = vertices;  //<-���� ������ �־������ ������ �ʱ�ȭ ���ִ� ����

		HRESULT hr = Graphics::Get()->GetDevice()->CreateBuffer(&desc, &subData, &vertexBuffer);
		assert(SUCCEEDED(hr));
	}
	
	//indexData  ��ġ�� ������ ���̱� ���ؼ� ���� 
	{
		//012 213 ������ �������
		indices = new UINT[6]{0,1,2,2,1,3};
	}

	//indexBuffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));

		desc.Usage = D3D11_USAGE_IMMUTABLE;
		desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		desc.ByteWidth = sizeof(UINT) * 6;
		D3D11_SUBRESOURCE_DATA subData;
		subData.pSysMem = indices;//���� ���� ������ ���� ������ �ʱ�ȭ ���ִ� ����

		HRESULT hr = Graphics::Get()->GetDevice()->CreateBuffer(&desc, &subData, &indexBuffer);
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
			LayoutDesc,						//��ǲ ���̾ƿ� desc
			2,								//�Է� ������ �׸� ��
			vsBlob->GetBufferPointer(),		//���������� 
			vsBlob->GetBufferSize(),		//���������� ũ��
			&inputLayout					//����� ���� ������ ��ü
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
	
	SAFE_RELEASE(indexBuffer);
	SAFE_DELETE_ARRAY(indices);

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
		0,						//���� ���� ����
		1,						//���� ����
		&vertexBuffer,			//����
		&stride,				//���� ũ��
		&offset					//���� ���� ũ��
	);
	Graphics::Get()->GetDC()->IASetIndexBuffer
	(
		indexBuffer,			//�ε�������
		DXGI_FORMAT_R32_UINT,	//����
		0						//���۰� ũ����
	);
	Graphics::Get()->GetDC()->IASetInputLayout
	(
		inputLayout
	);
	Graphics::Get()->GetDC()->IASetPrimitiveTopology//�׸��� ��� 
	(
		//D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED		// �⺻ ���������� ���� ���� ������ �۵��ȵ�  �� ���Ƿ� ������ �����ؼ� ����ϴ� �� ��
		//D3D11_PRIMITIVE_TOPOLOGY_POINTLIST		//������ �����͸� �� ���� �׸���
		//D3D11_PRIMITIVE_TOPOLOGY_LINELIST			//�� ����� �����ؼ� ��ü���� �׸���
		//D3D11_PRIMITIVE_TOPOLOGY_LINELIST_ADJ		//���� ������ ���� �ﰢ��
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST		//�ﰢ�� ����� �����ؼ� ��ü���� �׸���
		//D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP	//�ﰢ�� �츦 �����ؼ� ��ü���� �׸���
		//D3D11_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST //�����ڷ� n���� ���������� ����Ѵ�
	);
	Graphics::Get()->GetDC()->VSSetShader
	(
		vertexShader,//���̴�
		nullptr,	 //�ν��Ͻ� 3d���� ����
		0
	);
	Graphics::Get()->GetDC()->PSSetShader
	(
		pixelShader,
		nullptr,
		0
	);

	Graphics::Get()->GetDC()->DrawIndexed
	(
		6,	//�׷��� �ϴ� �ε��� ��
		0,	//�׸��� ������ �ε��� �ѹ�
		0	//���� ���ۿ��� ������ �б� ���� �� �ε����� �߰� �� ���Դϴ�.
	);

	//Graphics::Get()->GetDC()->Draw
	//(
	//	4, //�׸� ������ ��
	//	0  //���� ������
	//);
}

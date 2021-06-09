#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	//vertexdata  //local ��ǥ��
	//{
	//	vertices = new VertexColor[4];
	//	vertices[0].position = D3DXVECTOR3(-0.5f, -0.5f, 0.0f);
	//	vertices[0].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	//	vertices[1].position = D3DXVECTOR3(-0.5f, 0.5f, 0.0f);
	//	vertices[1].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	//	vertices[2].position = D3DXVECTOR3(0.5f, -0.5f, 0.0f);
	//	vertices[2].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	//	vertices[3].position = D3DXVECTOR3(0.5f, 0.5f, 0.0f);
	//	vertices[3].color = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
	//}

	//vertex Texture  //local ��ǥ��
	{
		vertices = new VertexTexture[4];
		vertices[0].position = D3DXVECTOR3(-0.5f, -0.5f, 0.0f);
		vertices[0].uv = D3DXVECTOR2(0.0f, 1.0f);
		vertices[1].position = D3DXVECTOR3(-0.5f, 0.5f, 0.0f);
		vertices[1].uv = D3DXVECTOR2(0.0f, 0.0f);
		vertices[2].position = D3DXVECTOR3(0.5f, -0.5f, 0.0f);
		vertices[2].uv = D3DXVECTOR2(1.0f, 1.0f);
		vertices[3].position = D3DXVECTOR3(0.5f, 0.5f, 0.0f);
		vertices[3].uv = D3DXVECTOR2(1.0f, 0.0f);
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
		desc.ByteWidth = sizeof(VertexTexture) * 4;

		D3D11_SUBRESOURCE_DATA subData;//���� �ڿ�������  ->��ǻ� ���ҽ����� �ִ� ���� ������
		ZeroMemory(&subData, sizeof(D3D11_SUBRESOURCE_DATA));
		subData.pSysMem = vertices;  //<-���� ������ �־������ ������ �ʱ�ȭ ���ִ� ����

		HRESULT hr = Graphics::Get()->GetDevice()->CreateBuffer(&desc, &subData, &vertexBuffer);
		assert(SUCCEEDED(hr));
	}
	//indexData  ��ġ�� ������ ���̱� ���ؼ� ����
	{
		//012 213 ������ �������
		indices = new UINT[6]{ 0,1,2,2,1,3 };
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
			"./Texture.hlsl",					//�����̸�
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
		//D3D11_INPUT_ELEMENT_DESC LayoutDesc[]
		//{
		//	{
		//		"POSITION",					//�ø�ƽ �̸�
		//		0,							//�ø�ƽ �ε���
		//		DXGI_FORMAT_R32G32B32_FLOAT,//����						//��ä�δ� �� ��Ʈ���� �˷��ִ¿��̴�. ���� 32��Ʈ �� 4����Ʈ  vector3 = 4*8��Ʈ(1����Ʈ)
		//		0,							//��ǲ ����					//gpu�� �ѱ�� 16���� vertex buffer�� ã�� ���� ���̴�
		//		0,							//AlignedByteOffset			//���������� �󸶳� �������ִ°� ���� �Է��� �޸��� ũ�⸦ ���ϴ� ���̴�.
		//		D3D11_INPUT_PER_VERTEX_DATA,//InputSlotClass			//���ø����̼� �ν��Ͻ̿� ����Ѵ� (���� �뵵�� ���� 3d���� ���� ��)
		//		0							//�ν��Ͻ� ������ ���ܷ���Ʈ //���� �ν��Ͻ��� Ȱ���
		//	},
		//	{
		//		"COLOR",
		//		0,
		//		DXGI_FORMAT_R32G32B32A32_FLOAT,
		//		0,
		//		sizeof(D3DXVECTOR3),
		//		D3D11_INPUT_PER_VERTEX_DATA,
		//		0
		//	},
		//};
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
				"TEXCOORD",
				0,
				DXGI_FORMAT_R32G32_FLOAT,
				0,
				sizeof(D3DXVECTOR3),  //���� �׸�ũ��
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
			//L"./Color.hlsl",
			L"./Texture.hlsl",
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
	//CreateWorldViewProjection
	{
		//���� ��ķ� �ʱ�ȭ
		D3DXMatrixIdentity(&world);
		D3DXMatrixIdentity(&view);
		D3DXMatrixIdentity(&projection);
		//view//ī�޶� ���
		D3DXMatrixLookAtLH(&view, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 0, 1), &D3DXVECTOR3(0, 1, 0));
		//projection //2d�� ���� ����
		//D3DXMatrixOrthoLH
		//(
		//	&projection,
		//	WinMaxWidth,
		//	WinMaxHeight,
		//	0,//������	3D
		//	1//�հ�		3D
		//);//�޼� ��ǥ��
		D3DXMatrixOrthoOffCenterLH//������ ���ϴ�
		(
			&projection,
			0,
			WinMaxWidth,
			0,
			WinMaxHeight,//�ٲٸ� �ø��� �����Ǵ� ������ �ٲ�����Ѵ�
			0,//near
			1//far
		);
		cout << "View Matrix" << endl;
		cout << view._11 << " " << view._12 << " " << view._13 << " " << view._14 << endl;
		cout << view._21 << " " << view._22 << " " << view._23 << " " << view._24 << endl;
		cout << view._31 << " " << view._32 << " " << view._33 << " " << view._34 << endl;
		cout << view._41 << " " << view._42 << " " << view._43 << " " << view._44 << endl;

		cout << endl;

		cout << "Projection Matrix" << endl;
		cout << projection._11 << " " << projection._12 << " " << projection._13 << " " << projection._14 << endl;
		cout << projection._21 << " " << projection._22 << " " << projection._23 << " " << projection._24 << endl;
		cout << projection._31 << " " << projection._32 << " " << projection._33 << " " << projection._34 << endl;
		cout << projection._41 << " " << projection._42 << " " << projection._43 << " " << projection._44 << endl;

		cout << endl;
		//world
		D3DXMatrixIdentity(&S);
		D3DXMatrixIdentity(&R);
		D3DXMatrixIdentity(&T);
		//ũ��
		D3DXMatrixScaling(&S, 400, 400, 1);
		cout << "S Matrix" << endl;
		cout << S._11 << " " << S._12 << " " << S._13 << " " << S._14 << endl;
		cout << S._21 << " " << S._22 << " " << S._23 << " " << S._24 << endl;
		cout << S._31 << " " << S._32 << " " << S._33 << " " << S._34 << endl;
		cout << S._41 << " " << S._42 << " " << S._43 << " " << S._44 << endl;
		cout << endl;
		//������ z���� ������
		D3DXMatrixRotationZ(&R, static_cast<float>(D3DXToRadian(0)));//��������� float
		cout << "R Matrix" << endl;
		cout << R._11 << " " << R._12 << " " << R._13 << " " << R._14 << endl;
		cout << R._21 << " " << R._22 << " " << R._23 << " " << R._24 << endl;
		cout << R._31 << " " << R._32 << " " << R._33 << " " << R._34 << endl;
		cout << R._41 << " " << R._42 << " " << R._43 << " " << R._44 << endl;
		cout << endl;
		//�̵�
		D3DXMatrixTranslation(&T, 400, 400, 0);
		cout << "T Matrix" << endl;
		cout << T._11 << " " << T._12 << " " << T._13 << " " << T._14 << endl;
		cout << T._21 << " " << T._22 << " " << T._23 << " " << T._24 << endl;
		cout << T._31 << " " << T._32 << " " << T._33 << " " << T._34 << endl;
		cout << T._41 << " " << T._42 << " " << T._43 << " " << T._44 << endl;
		cout << endl;

		world = S * R * T;
	}
	//CreateConstantBuffere
	{//��� ���� desc
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(desc));

		desc.Usage = D3D11_USAGE_DYNAMIC;
		desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		desc.ByteWidth = sizeof(TransformData);
		//������ �е�  �����͸� 16����Ʈ ������ �°� �����ִ°�  ������ �ʿ���� �Ƚ���
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

		HRESULT hr = Graphics::Get()->GetDevice()->CreateBuffer(&desc, nullptr, &gpuBuffer);
		assert(SUCCEEDED(hr));
	}
	//CreateRasterizerState  // �ڵ� ������ �ƴ� �ɼ�
	{
		D3D11_RASTERIZER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_RASTERIZER_DESC));

		desc.FillMode = D3D11_FILL_SOLID;//���� ä���ش�
		//D3D11_FILL_WIREFRAME  ������ �׷��ش� ���߿� ���� üũ������ �����ִ�
		desc.CullMode = D3D11_CULL_BACK;//back face culling �� frontcull�� �ո��� �ڸ���
		//culling �̶� ó������ �׸��� �ʴ´�  cliping �׸����� �߶󳽴�
		desc.FrontCounterClockwise = false;  //�ݽð������ �ո��̴�.
		HRESULT hr = Graphics::Get()->GetDevice()->CreateRasterizerState(&desc, &rsState);
		assert(SUCCEEDED(hr));
	}
	//CreateSRV//shaderresourceview  //�ؽ��ĸ� ��ȸ������ �����Ѵ� 12������ �Ⱦ�
	{
		HRESULT hr = D3DX11CreateShaderResourceViewFromFileA//������ �����Ͽ� �ҷ��´�
		(
			Graphics::Get()->GetDevice(),
			"./Image2.png",
			nullptr,
			nullptr,
			&SRV,
			nullptr
		);
		assert(SUCCEEDED(hr));
	}
	//CreateSamplerState
	{
		D3D11_SAMPLER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_SAMPLER_DESC));
		//min=���,mag=Ȯ��, 
		//mip=�θ� (�̹����� 1/4�� �ٿ��� �������� �غ��س��°�)ex 256*256 128*128 �޸𸮸� ���� ������ ������ �ӵ��� ���� �����
		//linear ���� ���� �ϰڴٴ� �̾߱��� ��հ��� ���´�		����� ��ΰ� ���� ����
		//POINT ��ġ�� �ȼ��� ������ �ϳ��� ����Ѵٴ� �̾߱��		����� ������ ���� ������
		desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;	

		/*D3D11_TEXTURE_ADDRESS_WRAP
		���(u, v) ���� ���տ��� �ؽ�ó�� Ÿ�ϸ��մϴ�.���� ���, 0���� 3 ������ u ���� ���� �ؽ�ó�� �� �� �ݺ��˴ϴ�.
		D3D11_TEXTURE_ADDRESS_MIRROR
			���(u, v) ���� ���տ��� �ؽ�ó�� �������ϴ�.���� ���, 0�� 1 ������ u ���� ��� �ؽ�ó�� ���������� ó���˴ϴ�. 
			1�� 2 ���̿��� �ؽ�ó�� ��Ī �̵��˴ϴ�. 2�� 3 ���̿��� �ؽ�ó�� �ٽ� �����Դϴ�.
		D3D11_TEXTURE_ADDRESS_CLAMP
			[0.0, 1.0] ������ ��� �ؽ�ó ��ǥ�� ���� 0.0 �Ǵ� 1.0�� �ؽ�ó �������� �����˴ϴ�.
		D3D11_TEXTURE_ADDRESS_BORDER
			[0.0, 1.0] ������ ����� �ؽ�ó ��ǥ�� D3D11_SAMPLER_DESC �Ǵ� HLSL �ڵ忡 ������ �׵θ� �������� �����˴ϴ� .
		D3D11_TEXTURE_ADDRESS_MIRROR_ONCE
			D3D11_TEXTURE_ADDRESS_MIRROR �� D3D11_TEXTURE_ADDRESS_CLAMP�� �����մϴ�.
			�ؽ�ó ��ǥ�� ���� ��(���� 0�� �߽����� �̷���)�� ���� ���� �ִ� ������ �����մϴ�.
		��ǥ�� �Ѿ �κ��� ó���ϴ� ����̴�
		*/
		desc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
		desc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
		desc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;
		//�Ѿ�� ������ rgba
		desc.BorderColor[0] = 1;
		desc.BorderColor[1] = 0;
		desc.BorderColor[2] = 0;
		desc.BorderColor[3] = 1;
													   //D3D11_COMPARISON_NEVER �׻� ���Ѵ�   ���������Ϳ� ���� ������(?) 
		desc.ComparisonFunc = D3D11_COMPARISON_ALWAYS; //D3D11_COMPARISON_ALWAYS  pass�� ������ = �񱳸� �н� �Ѵ� = �񱳾��Ѵ�  
		//�׻� ���ο� ���ø� �����Ͱ� ������ ����� ��Ų��.
		desc.MaxAnisotropy = 16; //���漺 ���͸� �������� ���� ������ 2D���� �ǹ̾���
		desc.MinLOD = numeric_limits<float>::min(); //level of detail  TS���� ����  
		//�׼����̼� �ܰ�
		//�Ѹ޽��� �ﰢ������ �� �߰� �ɰ��� ���ο� �ﰢ���� ����� ������ ���Ѵ�
		desc.MaxLOD = numeric_limits<float>::max();
		desc.MipLODBias = 0.0f;						//ī�޶󿡼� �־������� �帮�����ϰ� ���̵��� �������ϴ°� 
		HRESULT hr = Graphics::Get()->GetDevice()->CreateSamplerState(&desc,&samplerState);
		assert(SUCCEEDED(hr));
	}
	//CreateBlendState
	{
		D3D11_BLEND_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BLEND_DESC));
		desc.AlphaToCoverageEnable = false;
		//�����׽�Ʈ�� ��Ƽ���̽��� �����ϰ� �� 3d���� ����Ұ� ������ �ٰ� ���� ��Ȳ���� ������ ��Ƽ���ø��� ���ؼ� ��������� ����
		desc.IndependentBlendEnable = false;
		//���������� ���� ���� ���� ������ false�� �����ϸ� RenderTarget 0���� �������� ��� Ÿ�ٿ� �����Ѵ� ��� ���̴�
		//RenderTarget8���� max�� �Ǿ��ִ� render target view ���� ����������
		desc.RenderTarget[0].BlendEnable = true;
		//������ �ϰڴ�.			RenderTarget = rtv�� �Ҹ� == ������� �� ==������ �ǹ��Ѵ�   
		desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;//�ҽ��� �츮�� �־��� �ؽ��� ������ rgba���� �ǹ���	 
		//blend 1�� �ҽ��� ��ü ���İ� 1�� ���� �����´�	�׷��� �������� ���		
		desc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;//DestBlend ����� rgba = 1 - �ҽ��� ���ĸ� ���ڴ�  �ι��� �� 
		//���⼭ ������ ����� �ǵ��� ����
		//blend�� blend operator ����
		//blend �ȼ� ���̴� �� ���� ����� ���� �ٲٴ� ���
		//blend ������ �������� ���� ���� ���� �۾� ����� ����
		//float4 color =(src*srcblend) Blend op (des*destblend)
		//���� ���� ��� ����� ���ϱ⸦ �Ͽ��� ����� ��
		desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		//���İ��� ���� �������� �� //default
		desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
		desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		//Ư��ä�θ� ����ϰڴ�. �������͸� ����ٰ� �����ϸ� �ȴ�
		desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
		HRESULT hr = Graphics::Get()->GetDevice()->CreateBlendState(&desc, &blendState);
		assert(SUCCEEDED(hr));
	}
}

Program::~Program()
{
	SAFE_RELEASE(samplerState);

	SAFE_RELEASE(SRV);

	SAFE_RELEASE(rsState);

	SAFE_RELEASE(gpuBuffer);
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
	/*
	��Ŀ� ���� ����
	//ũ��
	world._11 = 50;
	world._22 = 50;

	//ȸ��
	//D3DXMatrixRotationZ(&view, D3DXToRadian(45));

	//�̵�
	world._41 = 100;
	world._42 = 100;
	*/


	//dx ��켱 gpu ���켱 ���
	D3DXMatrixTranspose(&cpuBuffer.world, &world);
	D3DXMatrixTranspose(&cpuBuffer.view, &view);
	D3DXMatrixTranspose(&cpuBuffer.projection, &projection);

	//11���� lock �Ŵ� ���� map unmap ���� �ٲ�
	D3D11_MAPPED_SUBRESOURCE mappedSubResource;
	Graphics::Get()->GetDC()->Map
	(
		gpuBuffer,
		0,
		D3D11_MAP_WRITE_DISCARD,//���ؼ� ���� ������
		0,
		&mappedSubResource
	);
	memcpy(mappedSubResource.pData, &cpuBuffer, sizeof(TransformData));
	Graphics::Get()->GetDC()->Unmap
	(
		gpuBuffer,
		0
	);
}

void Program::Render()
{
	//UINT stride = sizeof(VertexColor);
	UINT stride = sizeof(VertexTexture);
	UINT offset = 0;
	//IA
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
	//cbuffer
	Graphics::Get()->GetDC()->VSSetConstantBuffers//ndc ��ǥ��� ���ٰ� ������ȯ�� �������ν� ������ ��ȯ �ʿ���
	(
		0,
		1,
		&gpuBuffer
	);
	//VS
	Graphics::Get()->GetDC()->VSSetShader
	(
		vertexShader,//���̴�
		nullptr,	 //�ν��Ͻ� 3d���� ����
		0
	);
	
	//RS
	Graphics::Get()->GetDC()->RSSetState(rsState);

	//PS
	Graphics::Get()->GetDC()->PSSetShader
	(
		pixelShader,
		nullptr,
		0
	);
	Graphics::Get()->GetDC()->PSSetShaderResources
	(
		0,
		1,
		&SRV
	);
	Graphics::Get()->GetDC()->PSSetSamplers
	(
		0,
		1,
		&samplerState
	);
	//OM
	Graphics::Get()->GetDC()->OMSetBlendState
	(
		blendState,
		nullptr,			//�⺻���̶�� ��������
		0xFFFFFFF
	);
	//drawcall
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

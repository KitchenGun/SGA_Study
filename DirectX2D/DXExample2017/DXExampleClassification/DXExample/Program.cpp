#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	//vertexdata  //local 좌표계
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

	//vertex Texture  //local 좌표계
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

		desc.Usage = D3D11_USAGE_IMMUTABLE;//설명서에 적힌 용도
		/*
		접근 방식에 대한 지정법   (자원 접근이 가능하면 데이터를 변경할수있다)
		D3D11_USAGE_DEFAULT	= gpu만 데이터 읽고 쓸수있다
		D3D11_USAGE_IMMUTABLE = gpu가 데이터를 읽기만 한다/cpu접근 마찬가지로 불가능/생성과 동시에 초기화를 해야한다/제일 빠르다
		D3D11_USAGE_DYNAMIC	= gpu 읽기 허용	/cpu 쓰기 허용  /맵 언맵을 사용해서 cpu에서 접근해서 수정이 가능함/cpu에서 한프레임당 한번씩 업데이트 필요한 자원에 사용
		D3D11_USAGE_STAGING	= gpu 메모리에서 cpu 메모리로 복사 허용 (읽기 쓰기 전부 다됨)  /속도가 제일 느림
		*/
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;//vertex 버퍼 라는것 알려주는용도
		desc.ByteWidth = sizeof(VertexTexture) * 4;

		D3D11_SUBRESOURCE_DATA subData;//보조 자원데이터  ->사실상 리소스내에 있는 실제 데이터
		ZeroMemory(&subData, sizeof(D3D11_SUBRESOURCE_DATA));
		subData.pSysMem = vertices;  //<-정점 정보를 넣어줘야함 선언후 초기화 해주는 과정

		HRESULT hr = Graphics::Get()->GetDevice()->CreateBuffer(&desc, &subData, &vertexBuffer);
		assert(SUCCEEDED(hr));
	}
	//indexData  겹치는 정점을 줄이기 위해서 사용됨
	{
		//012 213 구도로 만들거임
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
		subData.pSysMem = indices;//정점 제작 순서에 대한 정보를 초기화 해주는 과정

		HRESULT hr = Graphics::Get()->GetDevice()->CreateBuffer(&desc, &subData, &indexBuffer);
		assert(SUCCEEDED(hr));
	}

	//vertex shader
	{
		HRESULT hr = D3DX11CompileFromFileA//어떤 파일로 부터 기계어로 번역하는 과정
		(
			"./Texture.hlsl",					//파일이름
			nullptr,						//hlsl define 쓰는 부분
			nullptr,						//hlsl include 쓰는 부분
			"VS",							//랜더링 파이프 라인 진입점에 사용하는 함수 쓰는 부분(진입점 함수 이름)
			"vs_5_0",						//쉐이더 모델 5.0을 사용한다  버전 기입
			0,								//쉐이더 컴파일 플래그 //특정 동작 수행 여부를 결정하는 것이다(현재 필요없음 0)
			0,								//효과 컴파일 플래그	//특정 동작 수행 여부를 결정하는 것이다(현재 필요없음 0)
			nullptr,						//별도의 쓰레드에서 비동기적으로 실행하고 싶을때
			&vsBlob,						//이진 데이터의 집합  -> 컴퓨터가 읽을 수 있는 기계어로 만드는 과정 바이너리라지오브젝트ㅠ
			nullptr,						//error msg
			nullptr							//만듬과 동시에 hr만들었기때문에 따로 반환 필요없음
		);
		//결론 vsBlob에 hlsl에서 입력 정보를 저장하고 다음 단계를 위한 준비를 한다
		assert(SUCCEEDED(hr));

		hr = Graphics::Get()->GetDevice()->CreateVertexShader
		(
			vsBlob->GetBufferPointer(),   //특수한 형태라서 이런식으로 불러와야한다
			vsBlob->GetBufferSize(),
			nullptr,
			&vertexShader
		);
		assert(SUCCEEDED(hr));
	}
	//inputLayout 들어갈 애들의 배치 배열
	{
		//D3D11_INPUT_ELEMENT_DESC LayoutDesc[]
		//{
		//	{
		//		"POSITION",					//시멘틱 이름
		//		0,							//시멘틱 인덱스
		//		DXGI_FORMAT_R32G32B32_FLOAT,//포멧						//한채널당 몇 비트인지 알려주는용이다. 현재 32비트 는 4바이트  vector3 = 4*8비트(1바이트)
		//		0,							//인풋 슬롯					//gpu로 넘기는 16개의 vertex buffer를 찾기 위한 값이다
		//		0,							//AlignedByteOffset			//시작점에서 얼마나 덜어져있는가 이전 입력한 메모리의 크기를 말하는 것이다.
		//		D3D11_INPUT_PER_VERTEX_DATA,//InputSlotClass			//어플리케이션 인스턴싱에 사용한다 (복사 용도로 쓰임 3d에서 많이 씀)
		//		0							//인스턴스 데이터 스텝레이트 //역시 인스턴스에 활용됨
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
				"POSITION",					//시멘틱 이름
				0,							//시멘틱 인덱스
				DXGI_FORMAT_R32G32B32_FLOAT,//포멧						//한채널당 몇 비트인지 알려주는용이다. 현재 32비트 는 4바이트  vector3 = 4*8비트(1바이트)
				0,							//인풋 슬롯					//gpu로 넘기는 16개의 vertex buffer를 찾기 위한 값이다
				0,							//AlignedByteOffset			//시작점에서 얼마나 덜어져있는가 이전 입력한 메모리의 크기를 말하는 것이다.
				D3D11_INPUT_PER_VERTEX_DATA,//InputSlotClass			//어플리케이션 인스턴싱에 사용한다 (복사 용도로 쓰임 3d에서 많이 씀)
				0							//인스턴스 데이터 스텝레이트 //역시 인스턴스에 활용됨
			},
			{
				"TEXCOORD",
				0,
				DXGI_FORMAT_R32G32_FLOAT,
				0,
				sizeof(D3DXVECTOR3),  //이전 항목크기
				D3D11_INPUT_PER_VERTEX_DATA,
				0
			},
		};
		HRESULT hr = Graphics::Get()->GetDevice()->CreateInputLayout
		(
			LayoutDesc,						//인풋 레이아웃 desc
			2,								//입력 데이터 항목 수
			vsBlob->GetBufferPointer(),		//이진데이터
			vsBlob->GetBufferSize(),		//이진데이터 크기
			&inputLayout					//결과물 넣을 포인터 객체
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
			"PS",			//function 네임과 동일
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
		//단위 행렬로 초기화
		D3DXMatrixIdentity(&world);
		D3DXMatrixIdentity(&view);
		D3DXMatrixIdentity(&projection);
		//view//카메라 행렬
		D3DXMatrixLookAtLH(&view, &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 0, 1), &D3DXVECTOR3(0, 1, 0));
		//projection //2d라서 직교 투영
		//D3DXMatrixOrthoLH
		//(
		//	&projection,
		//	WinMaxWidth,
		//	WinMaxHeight,
		//	0,//가까운곳	3D
		//	1//먼곳		3D
		//);//왼손 좌표계
		D3DXMatrixOrthoOffCenterLH//원점이 좌하단
		(
			&projection,
			0,
			WinMaxWidth,
			0,
			WinMaxHeight,//바꾸면 컬모드와 투영되는 방향을 바꿔줘야한다
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
		//크기
		D3DXMatrixScaling(&S, 400, 400, 1);
		cout << "S Matrix" << endl;
		cout << S._11 << " " << S._12 << " " << S._13 << " " << S._14 << endl;
		cout << S._21 << " " << S._22 << " " << S._23 << " " << S._24 << endl;
		cout << S._31 << " " << S._32 << " " << S._33 << " " << S._34 << endl;
		cout << S._41 << " " << S._42 << " " << S._43 << " " << S._44 << endl;
		cout << endl;
		//로컬의 z축을 돌린다
		D3DXMatrixRotationZ(&R, static_cast<float>(D3DXToRadian(0)));//명시적으로 float
		cout << "R Matrix" << endl;
		cout << R._11 << " " << R._12 << " " << R._13 << " " << R._14 << endl;
		cout << R._21 << " " << R._22 << " " << R._23 << " " << R._24 << endl;
		cout << R._31 << " " << R._32 << " " << R._33 << " " << R._34 << endl;
		cout << R._41 << " " << R._42 << " " << R._43 << " " << R._44 << endl;
		cout << endl;
		//이동
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
	{//상수 버퍼 desc
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(desc));

		desc.Usage = D3D11_USAGE_DYNAMIC;
		desc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		desc.ByteWidth = sizeof(TransformData);
		//데이터 패딩  데이터를 16바이트 단위에 맞게 보내주는것  지금은 필요없음 안썼음
		desc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

		HRESULT hr = Graphics::Get()->GetDevice()->CreateBuffer(&desc, nullptr, &gpuBuffer);
		assert(SUCCEEDED(hr));
	}
	//CreateRasterizerState  // 코드 수정이 아닌 옵션
	{
		D3D11_RASTERIZER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_RASTERIZER_DESC));

		desc.FillMode = D3D11_FILL_SOLID;//가득 채워준다
		//D3D11_FILL_WIREFRAME  선으로 그려준다 나중에 정점 체크용으로 쓸수있다
		desc.CullMode = D3D11_CULL_BACK;//back face culling 중 frontcull은 앞면을 자른다
		//culling 이란 처음부터 그리지 않는다  cliping 그린다음 잘라낸다
		desc.FrontCounterClockwise = false;  //반시계방향이 앞면이다.
		HRESULT hr = Graphics::Get()->GetDevice()->CreateRasterizerState(&desc, &rsState);
		assert(SUCCEEDED(hr));
	}
	//CreateSRV//shaderresourceview  //텍스쳐를 우회적으로 생성한다 12에서는 안씀
	{
		HRESULT hr = D3DX11CreateShaderResourceViewFromFileA//색값을 추출하여 불러온다
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
		//min=축소,mag=확대, 
		//mip=민맵 (이미지를 1/4씩 줄여서 집합으로 준비해놓는것)ex 256*256 128*128 메모리를 많이 먹지만 랜더링 속도를 위해 사용함
		//linear 선형 보간 하겠다는 이야기임 평균값을 섞는다		비용이 비싸고 질이 좋다
		//POINT 겹치는 픽셀이 있으면 하나를 폐기한다는 이야기다		비용이 싸지만 질이 안좋다
		desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;	

		/*D3D11_TEXTURE_ADDRESS_WRAP
		모든(u, v) 정수 접합에서 텍스처를 타일링합니다.예를 들어, 0에서 3 사이의 u 값에 대해 텍스처가 세 번 반복됩니다.
		D3D11_TEXTURE_ADDRESS_MIRROR
			모든(u, v) 정수 접합에서 텍스처를 뒤집습니다.예를 들어, 0과 1 사이의 u 값의 경우 텍스처는 정상적으로 처리됩니다. 
			1과 2 사이에서 텍스처가 대칭 이동됩니다. 2와 3 사이에서 텍스처는 다시 정상입니다.
		D3D11_TEXTURE_ADDRESS_CLAMP
			[0.0, 1.0] 범위를 벗어난 텍스처 좌표는 각각 0.0 또는 1.0의 텍스처 색상으로 설정됩니다.
		D3D11_TEXTURE_ADDRESS_BORDER
			[0.0, 1.0] 범위를 벗어나는 텍스처 좌표는 D3D11_SAMPLER_DESC 또는 HLSL 코드에 지정된 테두리 색상으로 설정됩니다 .
		D3D11_TEXTURE_ADDRESS_MIRROR_ONCE
			D3D11_TEXTURE_ADDRESS_MIRROR 및 D3D11_TEXTURE_ADDRESS_CLAMP와 유사합니다.
			텍스처 좌표의 절대 값(따라서 0을 중심으로 미러링)을 취한 다음 최대 값으로 고정합니다.
		좌표별 넘어간 부분을 처리하는 방법이다
		*/
		desc.AddressU = D3D11_TEXTURE_ADDRESS_BORDER;
		desc.AddressV = D3D11_TEXTURE_ADDRESS_BORDER;
		desc.AddressW = D3D11_TEXTURE_ADDRESS_BORDER;
		//넘어가는 영역의 rgba
		desc.BorderColor[0] = 1;
		desc.BorderColor[1] = 0;
		desc.BorderColor[2] = 0;
		desc.BorderColor[3] = 1;
													   //D3D11_COMPARISON_NEVER 항상 비교한다   원본데이터와 뎁스 데이터(?) 
		desc.ComparisonFunc = D3D11_COMPARISON_ALWAYS; //D3D11_COMPARISON_ALWAYS  pass가 생략됨 = 비교를 패스 한다 = 비교안한다  
		//항상 새로운 샘플링 데이터가 들어오면 통과를 시킨다.
		desc.MaxAnisotropy = 16; //비등방성 필터링 기울어진것 선명도 높여줌 2D에서 의미없음
		desc.MinLOD = numeric_limits<float>::min(); //level of detail  TS에서 사용됨  
		//테셀레이션 단계
		//한메시의 삼각형들을 더 잘게 쪼개서 새로운 삼각형을 만드는 과정을 말한다
		desc.MaxLOD = numeric_limits<float>::max();
		desc.MipLODBias = 0.0f;						//카메라에서 멀어질수록 흐리멍텅하게 보이도록 렌더링하는것 
		HRESULT hr = Graphics::Get()->GetDevice()->CreateSamplerState(&desc,&samplerState);
		assert(SUCCEEDED(hr));
	}
	//CreateBlendState
	{
		D3D11_BLEND_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BLEND_DESC));
		desc.AlphaToCoverageEnable = false;
		//알파테스트에 안티에이싱을 가능하게 함 3d에서 사용할것 조밀한 잎과 같은 상황에서 유용함 멀티샘플링을 통해서 계단현상을 줄임
		desc.IndependentBlendEnable = false;
		//독립적으로 블랜드 가능 지금 당장은 false로 설정하면 RenderTarget 0번의 설정값을 모든 타겟에 적용한다 라는 뜻이다
		//RenderTarget8개가 max로 되어있다 render target view 역시 마찬가지다
		desc.RenderTarget[0].BlendEnable = true;
		//블랜딩을 하겠다.			RenderTarget = rtv란 소리 == 백버퍼의 색 ==배경색을 의미한다   
		desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;//소스는 우리가 넣어줄 텍스쳐 원본의 rgba값을 의미함	 
		//blend 1은 소스의 전체 알파값 1로 만들어서 가져온다	그래서 검은색이 출력		
		desc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;//DestBlend 배경의 rgba = 1 - 소스의 알파를 쓰겠다  인버스 함 
		//여기서 배경색이 출력이 되도록 변경
		//blend와 blend operator 차이
		//blend 픽셀 셰이더 및 렌더 대상의 값을 바꾸는 방법
		//blend 연산자 설정해준 값에 대한 블랜딩 작업 방식을 선택
		//float4 color =(src*srcblend) Blend op (des*destblend)
		//위에 식을 계산 현재는 더하기를 하여서 계산을 함
		desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		//알파값만 따로 연산으로 뺌 //default
		desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
		desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
		//특정채널만 출력하겠다. 색상필터를 씌운다고 생각하면 된다
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
	행렬에 직접 접근
	//크기
	world._11 = 50;
	world._22 = 50;

	//회전
	//D3DXMatrixRotationZ(&view, D3DXToRadian(45));

	//이동
	world._41 = 100;
	world._42 = 100;
	*/


	//dx 행우선 gpu 열우선 행렬
	D3DXMatrixTranspose(&cpuBuffer.world, &world);
	D3DXMatrixTranspose(&cpuBuffer.view, &view);
	D3DXMatrixTranspose(&cpuBuffer.projection, &projection);

	//11부터 lock 거는 것이 map unmap 으로 바뀜
	D3D11_MAPPED_SUBRESOURCE mappedSubResource;
	Graphics::Get()->GetDC()->Map
	(
		gpuBuffer,
		0,
		D3D11_MAP_WRITE_DISCARD,//맵해서 쓰고 버린다
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
		0,						//시작 버퍼 슬롯
		1,						//버퍼 갯수
		&vertexBuffer,			//버퍼
		&stride,				//버퍼 크기
		&offset					//버퍼 간의 크기
	);
	Graphics::Get()->GetDC()->IASetIndexBuffer
	(
		indexBuffer,			//인덱스버퍼
		DXGI_FORMAT_R32_UINT,	//포맷
		0						//버퍼간 크기차
	);
	Graphics::Get()->GetDC()->IASetInputLayout
	(
		inputLayout
	);
	Graphics::Get()->GetDC()->IASetPrimitiveTopology//그리는 방법
	(
		//D3D11_PRIMITIVE_TOPOLOGY_UNDEFINED		// 기본 토폴로지가 정의 되지 않으면 작동안됨  걍 임의로 최적을 선택해서 출력하는 듯 함
		//D3D11_PRIMITIVE_TOPOLOGY_POINTLIST		//꼭지점 데이터를 점 으로 그린다
		//D3D11_PRIMITIVE_TOPOLOGY_LINELIST			//선 목록을 적용해서 물체들을 그린다
		//D3D11_PRIMITIVE_TOPOLOGY_LINELIST_ADJ		//인접 정보를 가진 삼각형
		D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST		//삼각형 목록을 적용해서 물체들을 그린다
		//D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP	//삼각형 띠를 적용해서 물체들을 그린다
		//D3D11_PRIMITIVE_TOPOLOGY_30_CONTROL_POINT_PATCHLIST //정점자료 n개의 제어점들을 사용한다
	);
	//cbuffer
	Graphics::Get()->GetDC()->VSSetConstantBuffers//ndc 좌표계로 보다가 공간변환을 해줌으로써 스케일 변환 필요함
	(
		0,
		1,
		&gpuBuffer
	);
	//VS
	Graphics::Get()->GetDC()->VSSetShader
	(
		vertexShader,//쉐이더
		nullptr,	 //인스턴스 3d에서 공부
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
		nullptr,			//기본값이라고 생각하자
		0xFFFFFFF
	);
	//drawcall
	Graphics::Get()->GetDC()->DrawIndexed
	(
		6,	//그려야 하는 인덱스 수
		0,	//그리기 시작할 인덱스 넘버
		0	//정점 버퍼에서 정점을 읽기 전에 각 인덱스에 추가 된 값입니다.
	);

	//Graphics::Get()->GetDC()->Draw
	//(
	//	4, //그릴 폴리곤 수
	//	0  //시작 폴리곤
	//);
}

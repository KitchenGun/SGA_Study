#include "stdafx.h"
#include "Program.h"

Program::Program()
{
	//vertexdata  //local 좌표계 
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

		desc.Usage = D3D11_USAGE_IMMUTABLE;//설명서에 적힌 용도 
		/*
		접근 방식에 대한 지정법   (자원 접근이 가능하면 데이터를 변경할수있다)
		D3D11_USAGE_DEFAULT	= gpu만 데이터 읽고 쓸수있다
		D3D11_USAGE_IMMUTABLE = gpu가 데이터를 읽기만 한다/cpu접근 마찬가지로 불가능/생성과 동시에 초기화를 해야한다/제일 빠르다
		D3D11_USAGE_DYNAMIC	= gpu 읽기 허용	/cpu 쓰기 허용  /맵 언맵을 사용해서 cpu에서 접근해서 수정이 가능함/cpu에서 한프레임당 한번씩 업데이트 필요한 자원에 사용
		D3D11_USAGE_STAGING	= gpu 메모리에서 cpu 메모리로 복사 허용 (읽기 쓰기 전부 다됨)  /속도가 제일 느림
		*/
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;//vertex 버퍼 라는것 알려주는용도
		desc.ByteWidth = sizeof(VertexColor) * 4;
		
		D3D11_SUBRESOURCE_DATA subData;//보조 자원데이터  ->사실상 리소스내에 있는 실제 데이터
		ZeroMemory(&subData, sizeof(D3D11_SUBRESOURCE_DATA));
		subData.pSysMem = vertices;  //<-정점 정보를 넣어줘야함 선언후 초기화 해주는 과정

		HRESULT hr = Graphics::Get()->GetDevice()->CreateBuffer(&desc, &subData, &vertexBuffer);
		assert(SUCCEEDED(hr));
	}
	
	//indexData  겹치는 정점을 줄이기 위해서 사용됨 
	{
		//012 213 구도로 만들거임
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
		subData.pSysMem = indices;//정점 제작 순서에 대한 정보를 초기화 해주는 과정

		HRESULT hr = Graphics::Get()->GetDevice()->CreateBuffer(&desc, &subData, &indexBuffer);
		assert(SUCCEEDED(hr));
	}




	//vertex shader
	{
		HRESULT hr = D3DX11CompileFromFileA//어떤 파일로 부터 기계어로 번역하는 과정
		(
			"./Color.hlsl",					//파일이름
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
			L"./Color.hlsl",
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
	Graphics::Get()->GetDC()->VSSetShader
	(
		vertexShader,//쉐이더
		nullptr,	 //인스턴스 3d에서 공부
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

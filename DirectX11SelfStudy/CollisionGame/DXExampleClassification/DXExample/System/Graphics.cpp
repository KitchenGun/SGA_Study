#include "stdafx.h"

Graphics* Graphics::instance = nullptr;

void Graphics::Create()
{
	if (instance == nullptr)
	{
		instance = new Graphics();
	}
}

void Graphics::Delete()
{
	if (instance != nullptr)
	{
		SAFE_DELETE(instance);
	}
}

Graphics* Graphics::Get()
{
	return instance;
}
//생성자
Graphics::Graphics()
{
	SetGPUInfo();		//gpu정보 불러오기 모니터정보도 불러옴
	CreateSwapChain();	//스왑체인 제작
}
//소멸자
Graphics::~Graphics()
{
	SAFE_RELEASE(rtv);
	SAFE_RELEASE(swapChain);
	SAFE_RELEASE(deviceContext);
	SAFE_RELEASE(device);
}

void Graphics::SetGPUInfo()
{
	EnumerateAdapters();
}

void Graphics::CreateSwapChain()
{
	SAFE_RELEASE(device);
	SAFE_RELEASE(deviceContext);
	SAFE_RELEASE(swapChain);
	//swap chain desc 제작
	DXGI_SWAP_CHAIN_DESC desc;
	//초기화
	ZeroMemory(&desc, sizeof(DXGI_SWAP_CHAIN_DESC));
	//백버퍼 초기화
	desc.BufferDesc.Width = 0;
	desc.BufferDesc.Height = 0;

	if (bVsync)//수직동기화 켜져있으면 주사율을 맞춰준다
	{
		desc.BufferDesc.RefreshRate.Numerator = adapterInfos[0]->outputInfo->numerator;  //가장 첫번째 그래픽 카드에 접근해서->
		desc.BufferDesc.RefreshRate.Denominator = adapterInfos[0]->outputInfo->denominator;
	}
	else
	{
		//1/0 이라는 이야기임  초당 0번 그리지고 지워진다
		desc.BufferDesc.RefreshRate.Numerator = 0;
		desc.BufferDesc.RefreshRate.Denominator =1;
	}
	desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;			//0~255까지 값을 부호가 없이 0~1 비례하게 표현// unsigned nomalrize 란 각 색상에 8비트씩 할당
	desc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;	//선을 어떤 식으로 그리는가?
	/*
	DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED
	스캔 라인 순서가 지정되지 않았습니다 .
	DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE
	이미지는 건너 뛰지 않고 첫 번째 스캔 라인에서 마지막 스캔 라인까지 생성됩니다.
	DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST
	상위 필드부터 이미지가 생성됩니다.
	DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST
	이미지는 하단 필드부터 생성됩니다.
	*/
	desc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;					//화면 축소 확대시 어떤 효과 줄것인가
	desc.BufferCount = 1;														//버퍼 개수
	desc.SampleDesc.Count = 1;													//픽셀당 멀티 샘플의 수
	desc.SampleDesc.Quality = 0;												//이미지 품질 수준// 높을수록 성능이 저하됩니다. 유효 범위는 0~1
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;							//랜더타겟 뷰란? 백버퍼에 그려지기 전에 임시로 그려지는 공간
	desc.OutputWindow = handle;													//출력하는 화면	
	desc.Windowed = true;														//창모드 사용 비사용?
	desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;									//버퍼끼리 바꿀때 주는 효과  현재 사용하지 않음

	desc.Flags = 0;

	//flag 넣어줄 용도로 제작
	UINT creationFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;//d2d로 스왑체인을 만들수있음 그렇기 때문에 이 옵션이 존재함 
														  //bgra rgb거꾸로 한거임 이런 포맷을 지원하게 하는 거임
#if defined(_DEBUG)//디버그 모드에서 사용할 플래그
	//비트 or 연산자
	creationFlags = D3DCOMPILE_PREFER_FLOW_CONTROL | D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
					//컴파일러가 가능한 경우 흐름 제어 구문을 사용하도록 지시합니다.	
					//디버그 파일 / 줄 / 유형 / 기호 정보를 출력 코드에 삽입하도록 컴파일러에 지시합니다.
					//코드 생성 중에 최적화 단계를 건너 뛰도록 컴파일러에 지시합니다. 디버그 목적으로 만이 상수를 설정하는 것이 좋습니다.
#endif

	vector<D3D_FEATURE_LEVEL> featureLevel			//기능 수준	무슨 버전을 사용할것인지 
	{
		D3D_FEATURE_LEVEL_11_1,						
		//D3D_FEATURE_LEVEL_11_0,
		//D3D_FEATURE_LEVEL_10_1,
		//D3D_FEATURE_LEVEL_10_0
	};

	UINT maxVideoMemory = 0;//vram 크기에서 sharedMemory를 제외한 크기
	for (UINT i = 0; i < adapterInfos.size(); i++) //가지고있는 그래픽 카드 개수 만큼
	{
		//순수 비디오 전용메모리와 maxVideoMemory 비교하여  //DedicatedVideoMemory shared가 있는데 
		if (adapterInfos[i]->adapterDesc.DedicatedVideoMemory > maxVideoMemory)
		{
			selectedAdapterIndex = i;
			maxVideoMemory = adapterInfos[i]->adapterDesc.DedicatedVideoMemory;
		}
	}
	//0번이 모니터에 관한 정보를 들고있다
	numerator = adapterInfos[0]->outputInfo->numerator;
	denominator = adapterInfos[0]->outputInfo->denominator;
	//가장 큰 메모리를 가진 것을 선택
	gpuMemorySize = adapterInfos[selectedAdapterIndex]->adapterDesc.DedicatedVideoMemory / 1024 / 1024; //mb단위로보기위해서 나눔//gb로 하지 않은 이유는 정확한 값을 보기위함
	gpuDescription = adapterInfos[selectedAdapterIndex]->adapterDesc.Description;  //설명 가져와서 넣음
	//디버그 일때 콘솔창에 출력
	cout << "DedicatedVideoMemory : " << gpuMemorySize << endl;
	wcout << "GPU Description : " << gpuDescription << endl;//유니코드 출력용

	cout << "Numerator : " << numerator << endl;
	cout << "Denominator : " << numerator << endl;

	HRESULT hr = D3D11CreateDeviceAndSwapChain
	(
		adapterInfos[selectedAdapterIndex]->adapter, //사용할 그래픽카드에 대한 포인터
		D3D_DRIVER_TYPE_UNKNOWN,//D3D_DRIVER_TYPE_UNKNOWN 드라이버 유형을 정하지 않음
		//하드웨어 가속을 사용한다 만약에 지원하지 않을 경우 소프트웨어 드라이버로 대체한다 
		//reference 3d를 지원하는 소프트웨어 타입 정확도에 초점을 맞춤(버그 찾을때)
		//null reference와 동일한 기능을 하지만 랜더링이 빠져있음 
		//software 그래픽카드가 없거나 cpu만 사용해서 구동할 경우 사용
		//warp 제일 빠름
		nullptr,
		creationFlags,					//플래그
		featureLevel.data(),			//기능 수준의 포인터를 넘겨줌
		featureLevel.size(),			//기능 수준의 포인터의 사이즈를 넘겨줌
		D3D11_SDK_VERSION,				//sdk 버전
		&desc,							//위에서 세팅한 desc 사용
		&swapChain,						//스왑체인에 사용되는 포인터 객체 주소
		&device,
		nullptr,
		&deviceContext					//deviceContext주소 넘겨줌
	);
	ASSERT(hr);

	Resize(WinMaxWidth, WinMaxHeight);
}

void Graphics::EnumerateAdapters() 
{
	IDXGIFactory1* factory;
	//생성 실패하면 반환			//IDXGIFactory1 개체 의 GUID ,IDXGIFactory1 포인터 객체
	if (FAILED(CreateDXGIFactory1(__uuidof(IDXGIFactory1), (void**)&factory)))
		return;

	UINT index = 0;
	while (true)
	{
		IDXGIAdapter1* adapter;

		HRESULT hr = factory->EnumAdapters1(index, &adapter);//인덱스에 맞는 그래픽카드 전부 열거
		if (hr == DXGI_ERROR_NOT_FOUND)//그래픽카드를 못 찾았을 경우
		{
			break;
		}
		ASSERT(hr);

		D3DEnumAdapterInfo* adapterInfo = new D3DEnumAdapterInfo();
		ZeroMemory(adapterInfo, sizeof(D3DEnumAdapterInfo));
		adapterInfo->adapterOrdinal = index;
		
		adapter->GetDesc1(&adapterInfo->adapterDesc);
		adapterInfo->adapter = adapter;

		EnumerateAdapterOutput(adapterInfo);
		adapterInfos.push_back(adapterInfo);
		++index;
	}
	SAFE_RELEASE(factory);
}

bool Graphics::EnumerateAdapterOutput(D3DEnumAdapterInfo * adapterInfos)
{
	//디스플레이 정보
	IDXGIOutput* output = nullptr;
	HRESULT hr = adapterInfos->adapter->EnumOutputs(0, &output); //adapter output인포를 받음
	
	if (DXGI_ERROR_NOT_FOUND == hr)
		return false;
	//객체 만들고 동적할당
	D3DEnumOutputInfo* outputInfo = new D3DEnumOutputInfo();
	ZeroMemory(outputInfo, sizeof(D3DEnumOutputInfo));
	
	hr = output->GetDesc(&outputInfo->outputDesc);
	ASSERT(hr);

	outputInfo->output = output;

	UINT numModes = 0;
	DXGI_MODE_DESC* displayModes = nullptr;
	DXGI_FORMAT format = DXGI_FORMAT_R8G8B8A8_UNORM;
	//???
	hr = output->GetDisplayModeList
	(
		format,						//색상 형식 값
		DXGI_ENUM_MODES_INTERLACED, //flag
		&numModes,					//GetDisplayModeList이 반환 하는 표시 모드 수를받는 변수에 대한 포인터
		nullptr						//디스플레이 모드 수를 얻으려면 NULL
	);
	ASSERT(hr);
	
	displayModes = new DXGI_MODE_DESC[numModes];

	//열거식힐 색상의 포멧을 넣고 플래그 넣어줌 //11이상부터는 GetDisplayModeList1을 사용하라고함
	hr = output->GetDisplayModeList
	(
		format,						//색상 형식 값
		DXGI_ENUM_MODES_INTERLACED, //flag
		&numModes,					//GetDisplayModeList이 반환 하는 표시 모드 수를받는 변수에 대한 포인터
		displayModes				//디스플레이 모드 수를 얻으려면 NULL
	);
	ASSERT(hr);
	//???
	for (UINT i = 0; i < numModes; i++)
	{
		bool bCheck = true;
		bCheck &= displayModes[i].Width == WinMaxWidth;
		bCheck &= displayModes[i].Height == WinMaxHeight;
		
		if (bCheck==true)
		{
			outputInfo->numerator = displayModes[i].RefreshRate.Numerator;
			outputInfo->denominator = displayModes[i].RefreshRate.Denominator;
		}
	}
	adapterInfos->outputInfo = outputInfo;
	SAFE_DELETE_ARRAY(displayModes);

	return true;
}
/*
//생성자에서 호출
void Graphics::Init()
{
	DXGI_SWAP_CHAIN_DESC desc;													//swapchain을 구성하기 위한 요청서
	ZeroMemory(&desc, sizeof(DXGI_SWAP_CHAIN_DESC));							//초기화
	desc.BufferDesc.Width = 0;													//백버퍼 초기화
	desc.BufferDesc.Height = 0;
	desc.BufferDesc.RefreshRate.Numerator = 60;									//화면 주사율 fps
	desc.BufferDesc.RefreshRate.Denominator = 1;								//   1/60 이라는 이야기임  초당 60번 그리지고 지워진다
	desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;						// unsigned nomalrize 란 각 색상에 8비트씩 할당  
																				//0~255까지 값을 부호가 없이 0~1 비례하게 표현

	desc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;	//선을 어떤순서로 그리는가 쓸일 없음
	desc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;					//화면 축소 확대시 어떤 효과 줄것인가
	desc.BufferCount = 1;														//버퍼 개수
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;							//버퍼 용도 지정  랜더 타겟 뷰로 쓴다  
																				//랜더타겟 뷰란?백버퍼에 그려지기 전에 임시로 그려지는 공간
	desc.SampleDesc.Count = 1;													//안씀 나중에 설명
	desc.SampleDesc.Quality = 0;												//안씀 나중에 설명				
	desc.OutputWindow = handle;													//출력하는 화면
	desc.Windowed = true;														//창모드 사용 비사용?
	desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;									//버퍼끼리 바꿀때 주는 효과  현재 사용하지 않음 	

	vector<D3D_FEATURE_LEVEL> featureLevel			//기능 수준	무슨 버전을 사용할것인지 
	{
		D3D_FEATURE_LEVEL_11_1,						//윈도우에 기본적으로 포함되어있기때문에 기존 경로가 지워져 있어서 사용을 할수없었다.
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0
	};

	HRESULT hr = D3D11CreateDeviceAndSwapChain					//HRESULT 객체가 제대로 생성이 되었는지 확인용  함수가 호출시 HRESULT값이 반환이 되어서 객체 생성여부 확인가능
	(
		//HRESULT는 BOOL과 다르게 RETURN값이 필수가 아니다 하지만 (true= 0/false=1)로 반대로 된다
		nullptr,												//화면이랑 연동되는것 지금당장 필요없음
		D3D_DRIVER_TYPE_HARDWARE,								//하드웨어 가속을 사용한다 만약에 지원하지 않을 경우 소프트웨어 드라이버로 대체한다 
																//reference 3d를 지원하는 소프트웨어 타입 정확도에 초점을 맞춤(버그 찾을때)
																//null reference와 동일한 기능을 하지만 랜더링이 빠져있음 
																//software 그래픽카드가 없거나 cpu만 사용해서 구동할 경우 사용
																//warp 제일 빠름
		nullptr,
		0,														//flag
		featureLevel.data(),									//기능 수준의 포인터를 넘겨줌
		featureLevel.size(),									//기능 수준의 포인터의 사이즈를 넘겨줌 
		D3D11_SDK_VERSION,										//sdk 무엇을 사용할 것인지 
		&desc,													//만들어준것 넣어주기
		&swapChain,														
		&device,
		nullptr,												//현재 사용하는 featherlevel 일단 nullptr
		&deviceContext													
	);
	assert(SUCCEEDED(hr));										//만든 객체가 성공했는지 실패했는지 판단 

	CreateBackBuffer();

}
//생성시 backbuffer생성을 위해서 사용
void Graphics::CreateBackBuffer()//백버퍼 생성 과정
{
	HRESULT hr = swapChain->ResizeBuffers  //우리가 맞춘 화면 크기로 조절  바뀐거 없으면 0
	(
		0,
		WinMaxWidth,
		WinMaxHeight,
		DXGI_FORMAT_UNKNOWN,
		0						//flag 특별한 기능 없음
	);
	assert(SUCCEEDED(hr));

	ID3D11Texture2D* backBuffer = nullptr;
	
	/*
	자원은 자료형에 따라 달라진다
	buffer 데이터를 임시로 담는 것  // 랜더링파이프 라인에 직접꽂을수있다
	buffer -> 정점 버퍼, 인덱스 버퍼,상수 버퍼
	texture //랜더링 파이프 라인에 직접 꽂을수 없기 때문에 리소스뷰를 사용한다 
	1d,2d,3d

	//Resource View의 종류 4가지 - 렌더링 파이프 라인에 꽂아주는 역할 
	//ID3D11RenderTargetView			//다음 프레임에 그려질 화면 저장하는 역할 
	//ID3D11ShaderResourceView		//쉐이더 형으로 꽂아주기 위함
	//ID3D11DepthStencilView			//깊이 정보를 랜더링 파이프 라인에 넣기 위함
	//ID3D11UnorderedAccessView		//
	

	hr = swapChain->GetBuffer  //만든걸 실제로 꽂아주는 과정 그림 용도로 사용중 
	(
		0,
		__uuidof(ID3D11Texture2D),//인터페이스에 GUID요구 (전역 고유 식별자)겹칠확률이 거의 없음 
		(void**)&backBuffer
	);
	assert(SUCCEEDED(hr));

	hr = device->CreateRenderTargetView	//화면에 송출전에 rtv에 임시 저장함      rtv가 여러개가 아니면 사실상 백 버퍼다  
	(
		backBuffer,
		nullptr,
		&rtv		
	);
	assert(SUCCEEDED(hr));

	//보여지는 화면에 대한 정보
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;
	viewport.Width = (float)WinMaxWidth;
	viewport.Height = (float)WinMaxHeight;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	//rtv에 다 넣었으면 backbuffer를 지워야함
	SAFE_RELEASE(backBuffer);//rtv에 들어가면 백버퍼의 역할이 끝나기 때문에 바로 지워주면 됨 

}
*/
void Graphics::Resize(const UINT & width, const UINT & height)
{
	DeleteSurface();
	{
		HRESULT hr = swapChain->ResizeBuffers
		(
			0,
			width,
			height,
			DXGI_FORMAT_UNKNOWN,
			0
		);
	}
	CreateRenderTargetView();
	SetViewport(width, height);
}

void Graphics::CreateRenderTargetView()
{
	ID3D11Texture2D* backBuffer = nullptr;
	HRESULT hr = swapChain->GetBuffer
	(
		0,
		__uuidof(ID3D11Texture2D),
		(void**)&backBuffer
	);
	ASSERT(hr);

	hr = device->CreateRenderTargetView
	(
		backBuffer,
		nullptr,
		&rtv
	);
	ASSERT(hr);
	SAFE_RELEASE(backBuffer);
}
//rtv에서 내보내는 부분이 viewport이다
void Graphics::SetViewport(const UINT & width, const UINT & height)
{
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;
	viewport.Width = (float)width;
	viewport.Height = (float)height;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
}

//반복호출
void Graphics::Begin()
{
	//dc는 그리는 도구집합
	deviceContext->OMSetRenderTargets(1, &rtv, nullptr);	//최종 병합 단계 view 1개 효과 정보 넘기고 depth안씀    
															//om 단계 프로그래밍 불가능 그래서 rtv를 꽂아줌 다음 프레임에 그려질 화면을 넘겨줌
	deviceContext->RSSetViewports(1, &viewport);			//viewport 세팅 rs 단계에서 수행
	deviceContext->ClearRenderTargetView(rtv, clearColor);	//rtv를 미리 세팅한 클리어 칼라로 지움
}
void Graphics::End()
{
	HRESULT hr = swapChain->Present(1, 0); // 백버퍼를 프론트랑 교체해서 보여주다 
	assert(SUCCEEDED(hr));//교체 잘됬는지 확인 
}

void Graphics::DeleteSurface()
{
	SAFE_RELEASE(rtv);
}
//////////////////////////////////////////////////////////////////////////////////////////////
D3DEnumAdapterInfo::~D3DEnumAdapterInfo()
{
	SAFE_RELEASE(adapter);
	SAFE_DELETE(outputInfo);
}
D3DEnumOutputInfo::~D3DEnumOutputInfo()
{
	SAFE_RELEASE(output);
}



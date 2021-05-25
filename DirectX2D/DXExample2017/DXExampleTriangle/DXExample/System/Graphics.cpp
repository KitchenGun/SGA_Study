#include "stdafx.h"
#include "Graphics.h"

Graphics* Graphics::instance = nullptr;

Graphics::Graphics()
{
	Init();
}

Graphics::~Graphics()
{
	SAFE_RELEASE(rtv);
	SAFE_RELEASE(swapChain);
	SAFE_RELEASE(deviceContext);
	SAFE_RELEASE(device);
}

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
	
	/*//자원의 종류 4가지
	/ID3D11RenderTargetView
	/ID3D11ShaderResourceView
	/ID3D11DepthStencilView
	/ID3D11UnorderedAccessView
	*/

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

void Graphics::Begin()
{
	//dc는 그리는 도구집합
	deviceContext->OMSetRenderTargets(1, &rtv, nullptr);	//최종 병합 단계 view 1개 효과 정보 넘기고 depth안씀
	deviceContext->RSSetViewports(1, &viewport);			//viewport 세팅 rs 단계에서 수행
	deviceContext->ClearRenderTargetView(rtv, clearColor);	//rtv를 미리 세팅한 클리어 칼라로 지움
}


void Graphics::End()
{
	HRESULT hr = swapChain->Present(1, 0); // 백버퍼를 프론트랑 교체해서 보여주다 
	assert(SUCCEEDED(hr));//교체 잘됬는지 확인 
}


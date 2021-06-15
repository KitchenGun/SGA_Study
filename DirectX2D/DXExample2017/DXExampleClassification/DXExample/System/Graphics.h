#pragma once
//싱글톤 
//GPU다루는 것이 핵심 = DX
//쉐이더 표현을 하기위해서 사용하는 것 HLSL

class D3DEnumAdapterInfo;
class D3DEnumOutputInfo;

class Graphics
{
public:
	static void Create();
	static void Delete();
	static Graphics* Get();

public:
	void Init();
	void CreateBackBuffer();

	ID3D11Device*GetDevice() { return device; }
	ID3D11DeviceContext* GetDC() { return deviceContext; }

	void Resize(const UINT& width, const UINT& height);
	void SetViewport(const UINT& width, const UINT& height);

	void Begin();
	void End();

private:
	void CreateSwapChain();
	void CreateRenderTargetView();
	void DeleteSurface();

private:
	Graphics();
	~Graphics();

	static Graphics* instance;

	void EnumerateAdapters();
	bool EnumerateAdapterOutput(D3DEnumAdapterInfo* adapterInfos);
	void SetGPUInfo();
	
private:
	ID3D11Device* device=nullptr;					//자원을 생성하는 역할  desc(설명서 주문서)와 유사한 역할
													//com interface (componant object model)내부에 이미 할당되어서 수정하지 않는 영역  앞에 I가 붙어있는 경우  삭제가 아니라 해제하는 것 
	ID3D11DeviceContext* deviceContext=nullptr;		//그림그릴때 씀
													//safe release로 지워야함
	IDXGISwapChain* swapChain = nullptr;			//이중 버퍼링 해주는 객체 //프론트와 백을 교체해주는 체인
	ID3D11RenderTargetView* rtv = nullptr;			//백버퍼에 연결되어있는 화면에 rtv효과를 만들어 저장하여 스왑체인이 동작하면 연결되어 실행됨
													//비트맵 같은 효과
	D3D11_VIEWPORT viewport = { 0 };				//보여지는 영역	
	D3DXCOLOR clearColor = 0xff555566;				//초기색 

	UINT numerator;
	UINT denominator;

	UINT gpuMemorySize;
	wstring gpuDescription;

	vector<D3DEnumAdapterInfo*> adapterInfos;
	int selectedAdapterIndex;

	bool bVsync = true; // 수직 동기화 모니터에 맞춰서 해줌 평균 60hz라고 생각하면됨//현재 모디터와 주사율을 맞춘다   
	//티어링 현상을 방지하기 위해서 사용
	
};

//////////////////////////////////////////////////////////////////////////////////////////
class D3DEnumAdapterInfo
{
public:
	D3DEnumAdapterInfo()=default;
	~D3DEnumAdapterInfo();

	UINT adapterOrdinal = 0;
	IDXGIAdapter1* adapter = nullptr;		//핵심 com interface 디스플레이 서브 시스템 여러 gpu의 정보 및 메모리를 받아올수있다.
	DXGI_ADAPTER_DESC1 adapterDesc = { 0 };

	D3DEnumOutputInfo* outputInfo = nullptr;

	
private:
	const D3DEnumAdapterInfo& operator = (const D3DEnumAdapterInfo& rhs);
};

class D3DEnumOutputInfo
{
public:
	D3DEnumOutputInfo() = default;
	~D3DEnumOutputInfo();

	IDXGIOutput* output = nullptr;			//핵심 com interface 모니터 정보를 받아오는데 사용함
	DXGI_OUTPUT_DESC outputDesc = { 0 };
	
	UINT numerator;
	UINT denominator;

private:
	const D3DEnumOutputInfo &operator = (const D3DEnumOutputInfo& rhs);
};
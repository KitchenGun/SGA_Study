#pragma once
//싱글톤 
//GPU다루는 것이 핵심 = DX
//쉐이더 표현을 하기위해서 사용하는 것 HLSL

class Graphics
{
public:
	static void Create();
	static void Delete();
	static Graphics* Get();

public:
	void Init();
	void CreateBackBuffer();

	void Begin();
	void End();

	ID3D11Device*GetDevice() { return device; }
	ID3D11DeviceContext* GetDC() { return deviceContext; }


private:
	Graphics();
	~Graphics();

	static Graphics* instance;
private:
	ID3D11Device* device=nullptr;					//자원을 생성하는 역할  desc(설명서 주문서)와 유사한 역할
													//com interface 내부에 이미 할당되어서 수정하지 않는 영역  앞에 I가 붙어있는 경우  삭제가 아니라 해제하는 것 
	ID3D11DeviceContext* deviceContext=nullptr;		//그림그릴때 씀
													//safe release로 지워야함
	IDXGISwapChain* swapChain = nullptr;			//이중 버퍼링 해주는 객체 //프론트와 백을 교체해주는 체인
	ID3D11RenderTargetView* rtv = nullptr;			//백버퍼에 연결되어있는 화면에 rtv효과를 만들어 저장하여 스왑체인이 동작하면 연결되어 실행됨
													//비트맵 같은 효과
	D3D11_VIEWPORT viewport = { 0 };				//보여지는 영역	
	D3DXCOLOR clearColor = 0xff555566;				//초기색 

};
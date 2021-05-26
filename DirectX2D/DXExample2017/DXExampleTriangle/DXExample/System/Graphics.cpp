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
	DXGI_SWAP_CHAIN_DESC desc;													//swapchain�� �����ϱ� ���� ��û��
	ZeroMemory(&desc, sizeof(DXGI_SWAP_CHAIN_DESC));							//�ʱ�ȭ
	desc.BufferDesc.Width = 0;													//����� �ʱ�ȭ
	desc.BufferDesc.Height = 0;
	desc.BufferDesc.RefreshRate.Numerator = 60;									//ȭ�� �ֻ��� fps
	desc.BufferDesc.RefreshRate.Denominator = 1;								//   1/60 �̶�� �̾߱���  �ʴ� 60�� �׸����� ��������
	desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;						// unsigned nomalrize �� �� ���� 8��Ʈ�� �Ҵ�  
																				//0~255���� ���� ��ȣ�� ���� 0~1 ����ϰ� ǥ��

	desc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;	//���� ������� �׸��°� ���� ����
	desc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;					//ȭ�� ��� Ȯ��� � ȿ�� �ٰ��ΰ�
	desc.BufferCount = 1;														//���� ����
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;							//���� �뵵 ����  ���� Ÿ�� ��� ����  
																				//����Ÿ�� ���?����ۿ� �׷����� ���� �ӽ÷� �׷����� ����
	desc.SampleDesc.Count = 1;													//�Ⱦ� ���߿� ����
	desc.SampleDesc.Quality = 0;												//�Ⱦ� ���߿� ����				
	desc.OutputWindow = handle;													//����ϴ� ȭ��
	desc.Windowed = true;														//â��� ��� ����?
	desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;									//���۳��� �ٲܶ� �ִ� ȿ��  ���� ������� ���� 	

	vector<D3D_FEATURE_LEVEL> featureLevel			//��� ����	���� ������ ����Ұ����� 
	{
		D3D_FEATURE_LEVEL_11_1,						//�����쿡 �⺻������ ���ԵǾ��ֱ⶧���� ���� ��ΰ� ������ �־ ����� �Ҽ�������.
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0
	};

	HRESULT hr = D3D11CreateDeviceAndSwapChain					//HRESULT ��ü�� ����� ������ �Ǿ����� Ȯ�ο�  �Լ��� ȣ��� HRESULT���� ��ȯ�� �Ǿ ��ü �������� Ȯ�ΰ���
	(
		//HRESULT�� BOOL�� �ٸ��� RETURN���� �ʼ��� �ƴϴ� ������ (true= 0/false=1)�� �ݴ�� �ȴ�
		nullptr,												//ȭ���̶� �����Ǵ°� ���ݴ��� �ʿ����
		D3D_DRIVER_TYPE_HARDWARE,								//�ϵ���� ������ ����Ѵ� ���࿡ �������� ���� ��� ����Ʈ���� ����̹��� ��ü�Ѵ� 
																//reference 3d�� �����ϴ� ����Ʈ���� Ÿ�� ��Ȯ���� ������ ����(���� ã����)
																//null reference�� ������ ����� ������ �������� �������� 
																//software �׷���ī�尡 ���ų� cpu�� ����ؼ� ������ ��� ���
																//warp ���� ����
		nullptr,
		0,														//flag
		featureLevel.data(),									//��� ������ �����͸� �Ѱ���
		featureLevel.size(),									//��� ������ �������� ����� �Ѱ��� 
		D3D11_SDK_VERSION,										//sdk ������ ����� ������ 
		&desc,													//������ذ� �־��ֱ�
		&swapChain,														
		&device,
		nullptr,												//���� ����ϴ� featherlevel �ϴ� nullptr
		&deviceContext													
	);
	assert(SUCCEEDED(hr));										//���� ��ü�� �����ߴ��� �����ߴ��� �Ǵ� 

	CreateBackBuffer();

}

void Graphics::CreateBackBuffer()//����� ���� ����
{
	HRESULT hr = swapChain->ResizeBuffers  //�츮�� ���� ȭ�� ũ��� ����  �ٲ�� ������ 0
	(
		0,
		WinMaxWidth,
		WinMaxHeight,
		DXGI_FORMAT_UNKNOWN,
		0						//flag Ư���� ��� ����
	);
	assert(SUCCEEDED(hr));

	ID3D11Texture2D* backBuffer = nullptr;
	
	/*
	�ڿ��� �ڷ����� ���� �޶�����
	buffer �����͸� �ӽ÷� ��� ��  // ������������ ���ο� �����������ִ�
	buffer -> ���� ����, �ε��� ����,��� ����
	texture //������ ������ ���ο� ���� ������ ���� ������ ���ҽ��並 ����Ѵ� 
	1d,2d,3d
	*/

	/*//Resource View�� ���� 4���� - ������ ������ ���ο� �Ⱦ��ִ� ���� 
	/ID3D11RenderTargetView			//���� �����ӿ� �׷��� ȭ�� �����ϴ� ���� 
	/ID3D11ShaderResourceView		//���̴� ������ �Ⱦ��ֱ� ����
	/ID3D11DepthStencilView			//���� ������ ������ ������ ���ο� �ֱ� ����
	/ID3D11UnorderedAccessView		//
	*/

	hr = swapChain->GetBuffer  //����� ������ �Ⱦ��ִ� ���� �׸� �뵵�� ����� 
	(
		0,
		__uuidof(ID3D11Texture2D),//�������̽��� GUID�䱸 (���� ���� �ĺ���)��ĥȮ���� ���� ���� 
		(void**)&backBuffer
	);
	assert(SUCCEEDED(hr));

	hr = device->CreateRenderTargetView	//ȭ�鿡 �������� rtv�� �ӽ� ������      rtv�� �������� �ƴϸ� ��ǻ� �� ���۴�  
	(
		backBuffer,
		nullptr,
		&rtv		
	);
	assert(SUCCEEDED(hr));

	//�������� ȭ�鿡 ���� ����
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;
	viewport.Width = (float)WinMaxWidth;
	viewport.Height = (float)WinMaxHeight;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	//rtv�� �� �־����� backbuffer�� ��������
	SAFE_RELEASE(backBuffer);//rtv�� ���� ������� ������ ������ ������ �ٷ� �����ָ� �� 

}

void Graphics::Begin()
{
	//dc�� �׸��� ��������
	deviceContext->OMSetRenderTargets(1, &rtv, nullptr);	//���� ���� �ܰ� view 1�� ȿ�� ���� �ѱ�� depth�Ⱦ�    
															//om �ܰ� ���α׷��� �Ұ��� �׷��� rtv�� �Ⱦ��� ���� �����ӿ� �׷��� ȭ���� �Ѱ���
	deviceContext->RSSetViewports(1, &viewport);			//viewport ���� rs �ܰ迡�� ����
	deviceContext->ClearRenderTargetView(rtv, clearColor);	//rtv�� �̸� ������ Ŭ���� Į��� ����
}


void Graphics::End()
{
	HRESULT hr = swapChain->Present(1, 0); // ����۸� ����Ʈ�� ��ü�ؼ� �����ִ� 
	assert(SUCCEEDED(hr));//��ü �߉���� Ȯ�� 
}


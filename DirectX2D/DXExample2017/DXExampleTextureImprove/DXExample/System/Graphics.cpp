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
//������
Graphics::Graphics()
{
	SetGPUInfo();		//gpu���� �ҷ����� ����������� �ҷ���
	CreateSwapChain();	//����ü�� ����
}
//�Ҹ���
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
	//swap chain desc ����
	DXGI_SWAP_CHAIN_DESC desc;
	//�ʱ�ȭ
	ZeroMemory(&desc, sizeof(DXGI_SWAP_CHAIN_DESC));
	//����� �ʱ�ȭ
	desc.BufferDesc.Width = 0;
	desc.BufferDesc.Height = 0;

	if (bVsync)//��������ȭ ���������� �ֻ����� �����ش�
	{
		desc.BufferDesc.RefreshRate.Numerator = adapterInfos[0]->outputInfo->numerator;  //���� ù��° �׷��� ī�忡 �����ؼ�->
		desc.BufferDesc.RefreshRate.Denominator = adapterInfos[0]->outputInfo->denominator;
	}
	else
	{
		//1/0 �̶�� �̾߱���  �ʴ� 0�� �׸����� ��������
		desc.BufferDesc.RefreshRate.Numerator = 0;
		desc.BufferDesc.RefreshRate.Denominator =1;
	}
	desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;			//0~255���� ���� ��ȣ�� ���� 0~1 ����ϰ� ǥ��// unsigned nomalrize �� �� ���� 8��Ʈ�� �Ҵ�
	desc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;	//���� � ������ �׸��°�?
	/*
	DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED
	��ĵ ���� ������ �������� �ʾҽ��ϴ� .
	DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE
	�̹����� �ǳ� ���� �ʰ� ù ��° ��ĵ ���ο��� ������ ��ĵ ���α��� �����˴ϴ�.
	DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST
	���� �ʵ���� �̹����� �����˴ϴ�.
	DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST
	�̹����� �ϴ� �ʵ���� �����˴ϴ�.
	*/
	desc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;					//ȭ�� ��� Ȯ��� � ȿ�� �ٰ��ΰ�
	desc.BufferCount = 1;														//���� ����
	desc.SampleDesc.Count = 1;													//�ȼ��� ��Ƽ ������ ��
	desc.SampleDesc.Quality = 0;												//�̹��� ǰ�� ����// �������� ������ ���ϵ˴ϴ�. ��ȿ ������ 0~1
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;							//����Ÿ�� ���? ����ۿ� �׷����� ���� �ӽ÷� �׷����� ����
	desc.OutputWindow = handle;													//����ϴ� ȭ��	
	desc.Windowed = true;														//â��� ��� ����?
	desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;									//���۳��� �ٲܶ� �ִ� ȿ��  ���� ������� ����

	desc.Flags = 0;

	//flag �־��� �뵵�� ����
	UINT creationFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;//d2d�� ����ü���� ��������� �׷��� ������ �� �ɼ��� ������ 
														  //bgra rgb�Ųٷ� �Ѱ��� �̷� ������ �����ϰ� �ϴ� ����
#if defined(_DEBUG)//����� ��忡�� ����� �÷���
	//��Ʈ or ������
	creationFlags = D3DCOMPILE_PREFER_FLOW_CONTROL | D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
					//�����Ϸ��� ������ ��� �帧 ���� ������ ����ϵ��� �����մϴ�.	
					//����� ���� / �� / ���� / ��ȣ ������ ��� �ڵ忡 �����ϵ��� �����Ϸ��� �����մϴ�.
					//�ڵ� ���� �߿� ����ȭ �ܰ踦 �ǳ� �ٵ��� �����Ϸ��� �����մϴ�. ����� �������� ���� ����� �����ϴ� ���� �����ϴ�.
#endif

	vector<D3D_FEATURE_LEVEL> featureLevel			//��� ����	���� ������ ����Ұ����� 
	{
		D3D_FEATURE_LEVEL_11_1,						
		//D3D_FEATURE_LEVEL_11_0,
		//D3D_FEATURE_LEVEL_10_1,
		//D3D_FEATURE_LEVEL_10_0
	};

	UINT maxVideoMemory = 0;//vram ũ�⿡�� sharedMemory�� ������ ũ��
	for (UINT i = 0; i < adapterInfos.size(); i++) //�������ִ� �׷��� ī�� ���� ��ŭ
	{
		//���� ���� ����޸𸮿� maxVideoMemory ���Ͽ�  //DedicatedVideoMemory shared�� �ִµ� 
		if (adapterInfos[i]->adapterDesc.DedicatedVideoMemory > maxVideoMemory)
		{
			selectedAdapterIndex = i;
			maxVideoMemory = adapterInfos[i]->adapterDesc.DedicatedVideoMemory;
		}
	}
	//0���� ����Ϳ� ���� ������ ����ִ�
	numerator = adapterInfos[0]->outputInfo->numerator;
	denominator = adapterInfos[0]->outputInfo->denominator;
	//���� ū �޸𸮸� ���� ���� ����
	gpuMemorySize = adapterInfos[selectedAdapterIndex]->adapterDesc.DedicatedVideoMemory / 1024 / 1024; //mb�����κ������ؼ� ����//gb�� ���� ���� ������ ��Ȯ�� ���� ��������
	gpuDescription = adapterInfos[selectedAdapterIndex]->adapterDesc.Description;  //���� �����ͼ� ����
	//����� �϶� �ܼ�â�� ���
	cout << "DedicatedVideoMemory : " << gpuMemorySize << endl;
	wcout << "GPU Description : " << gpuDescription << endl;//�����ڵ� ��¿�

	cout << "Numerator : " << numerator << endl;
	cout << "Denominator : " << numerator << endl;

	HRESULT hr = D3D11CreateDeviceAndSwapChain
	(
		adapterInfos[selectedAdapterIndex]->adapter, //����� �׷���ī�忡 ���� ������
		D3D_DRIVER_TYPE_UNKNOWN,//D3D_DRIVER_TYPE_UNKNOWN ����̹� ������ ������ ����
		//�ϵ���� ������ ����Ѵ� ���࿡ �������� ���� ��� ����Ʈ���� ����̹��� ��ü�Ѵ� 
		//reference 3d�� �����ϴ� ����Ʈ���� Ÿ�� ��Ȯ���� ������ ����(���� ã����)
		//null reference�� ������ ����� ������ �������� �������� 
		//software �׷���ī�尡 ���ų� cpu�� ����ؼ� ������ ��� ���
		//warp ���� ����
		nullptr,
		creationFlags,					//�÷���
		featureLevel.data(),			//��� ������ �����͸� �Ѱ���
		featureLevel.size(),			//��� ������ �������� ����� �Ѱ���
		D3D11_SDK_VERSION,				//sdk ����
		&desc,							//������ ������ desc ���
		&swapChain,						//����ü�ο� ���Ǵ� ������ ��ü �ּ�
		&device,
		nullptr,
		&deviceContext					//deviceContext�ּ� �Ѱ���
	);
	ASSERT(hr);

	Resize(WinMaxWidth, WinMaxHeight);
}

void Graphics::EnumerateAdapters() 
{
	IDXGIFactory1* factory;
	//���� �����ϸ� ��ȯ			//IDXGIFactory1 ��ü �� GUID ,IDXGIFactory1 ������ ��ü
	if (FAILED(CreateDXGIFactory1(__uuidof(IDXGIFactory1), (void**)&factory)))
		return;

	UINT index = 0;
	while (true)
	{
		IDXGIAdapter1* adapter;

		HRESULT hr = factory->EnumAdapters1(index, &adapter);//�ε����� �´� �׷���ī�� ���� ����
		if (hr == DXGI_ERROR_NOT_FOUND)//�׷���ī�带 �� ã���� ���
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
	//���÷��� ����
	IDXGIOutput* output = nullptr;
	HRESULT hr = adapterInfos->adapter->EnumOutputs(0, &output); //adapter output������ ����
	
	if (DXGI_ERROR_NOT_FOUND == hr)
		return false;
	//��ü ����� �����Ҵ�
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
		format,						//���� ���� ��
		DXGI_ENUM_MODES_INTERLACED, //flag
		&numModes,					//GetDisplayModeList�� ��ȯ �ϴ� ǥ�� ��� �����޴� ������ ���� ������
		nullptr						//���÷��� ��� ���� �������� NULL
	);
	ASSERT(hr);
	
	displayModes = new DXGI_MODE_DESC[numModes];

	//���Ž��� ������ ������ �ְ� �÷��� �־��� //11�̻���ʹ� GetDisplayModeList1�� ����϶����
	hr = output->GetDisplayModeList
	(
		format,						//���� ���� ��
		DXGI_ENUM_MODES_INTERLACED, //flag
		&numModes,					//GetDisplayModeList�� ��ȯ �ϴ� ǥ�� ��� �����޴� ������ ���� ������
		displayModes				//���÷��� ��� ���� �������� NULL
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
//�����ڿ��� ȣ��
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
//������ backbuffer������ ���ؼ� ���
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

	//Resource View�� ���� 4���� - ������ ������ ���ο� �Ⱦ��ִ� ���� 
	//ID3D11RenderTargetView			//���� �����ӿ� �׷��� ȭ�� �����ϴ� ���� 
	//ID3D11ShaderResourceView		//���̴� ������ �Ⱦ��ֱ� ����
	//ID3D11DepthStencilView			//���� ������ ������ ������ ���ο� �ֱ� ����
	//ID3D11UnorderedAccessView		//
	

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
//rtv���� �������� �κ��� viewport�̴�
void Graphics::SetViewport(const UINT & width, const UINT & height)
{
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;
	viewport.Width = (float)width;
	viewport.Height = (float)height;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
}

//�ݺ�ȣ��
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

void Graphics::SetViewport()
{
	deviceContext->RSSetViewports(1, &viewport);
}

void Graphics::SetBackBufferToRTV()
{
	deviceContext->OMSetRenderTargets(1, &rtv, nullptr);
	deviceContext->ClearRenderTargetView(rtv, clearColor);
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



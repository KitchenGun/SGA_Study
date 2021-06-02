#pragma once
//�̱��� 
//GPU�ٷ�� ���� �ٽ� = DX
//���̴� ǥ���� �ϱ����ؼ� ����ϴ� �� HLSL

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
	ID3D11Device* device=nullptr;					//�ڿ��� �����ϴ� ����  desc(���� �ֹ���)�� ������ ����
													//com interface ���ο� �̹� �Ҵ�Ǿ �������� �ʴ� ����  �տ� I�� �پ��ִ� ���  ������ �ƴ϶� �����ϴ� �� 
	ID3D11DeviceContext* deviceContext=nullptr;		//�׸��׸��� ��
													//safe release�� ��������
	IDXGISwapChain* swapChain = nullptr;			//���� ���۸� ���ִ� ��ü //����Ʈ�� ���� ��ü���ִ� ü��
	ID3D11RenderTargetView* rtv = nullptr;			//����ۿ� ����Ǿ��ִ� ȭ�鿡 rtvȿ���� ����� �����Ͽ� ����ü���� �����ϸ� ����Ǿ� �����
													//��Ʈ�� ���� ȿ��
	D3D11_VIEWPORT viewport = { 0 };				//�������� ����	
	D3DXCOLOR clearColor = 0xff555566;				//�ʱ�� 

};
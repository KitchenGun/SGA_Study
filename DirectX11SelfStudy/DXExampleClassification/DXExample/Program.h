#pragma once

class Program
{
public:
	Program();
	~Program();

	void SetGlobalBuffers();

	void Update();
	void Render();

private:
	ViewProjectionBuffer* VPBuffer;

	D3DXMATRIX view;			//ī�޶� ��ȯ ī�޶� �����ؼ� ���� ����
	D3DXMATRIX projection;		//���� ��ȯ ���������� ��������

	Circle* circle;
	Square* square;
};
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

	Matrix view;			//ī�޶� ��ȯ ī�޶� �����ؼ� ���� ����
	Matrix projection;		//���� ��ȯ ���������� ��������

	Square* square;
	Square* square2;
};
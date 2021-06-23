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

	SYSTEMTIME time;
	float tempFrameCount = 0.0f;
	Square* box;
};
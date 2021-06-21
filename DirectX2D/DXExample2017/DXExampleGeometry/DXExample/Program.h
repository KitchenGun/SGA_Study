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

	Square* square;
	Square* square2;
	Line* line;
};
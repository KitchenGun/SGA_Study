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

	D3DXMATRIX view;			//카메라 변환 카메라를 원점해서 만든 공간
	D3DXMATRIX projection;		//투영 변환 원근투영과 직교투영

	int temp=0;
	Square* square;
	Square* square2;
};
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

	Matrix view;			//카메라 변환 카메라를 원점해서 만든 공간
	Matrix projection;		//투영 변환 원근투영과 직교투영

	SYSTEMTIME time;

	Line* Hour;
	Line* Min;
	Line* Sec;
};
#pragma once

class Program
{
public:
	Program();
	~Program();

	void Init();

	void SetGlobalBuffers();

	void Update();

	void PreRender();
	void Render();
	void PostRender();

private:
	ViewProjectionBuffer* VPBuffer;

	Matrix view;			//ī�޶� ��ȯ ī�޶� �����ؼ� ���� ����
	Matrix projection;		//���� ��ȯ ���������� ��������

	Scene* currentScene;
	vector<Scene*> sceneList;


};
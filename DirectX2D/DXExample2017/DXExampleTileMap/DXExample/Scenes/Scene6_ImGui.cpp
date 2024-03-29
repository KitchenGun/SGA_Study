#include "stdafx.h"
#include "Scene6_ImGui.h"

Scene6::Scene6()
{
	Path::GetFiles(&paths, L"./_Textures/", L"*.*", true);

	Path::CreateFolders(L"./Directory/Sub1/Sub1_1");
	Path::CreateFolders(L"./Directory/Sub1/Sub1_2");
	Path::CreateFolders(L"./Directory/Sub2/Sub2_1");
	//L"*" 모든 파일을 불러옴
	//L"*.*" .을 가지고 있는 파일을 모두 불러옴
	Path::GetFiles(&paths, L"./Directory/", L"*", true);
}

Scene6::~Scene6()
{
	if (trVec.size() > 0)
	{
		for (TextureRect* tr : trVec)
			SAFE_DELETE(tr);
	}
}

void Scene6::Init()
{
	cout << endl;

	for (wstring path : paths)
	{
		wstring str = Path::GetFileNameWithoutExtension(path);
		wcout << str << endl;
	}
}



void Scene6::Update()
{
	if (Keyboard::Get()->Down(VK_SPACE))
		trVec.push_back(new TextureRect({ Mouse::Get()->GetPosition() }, { 300, 300, 1 }, 0));
	
	for (TextureRect* tr : trVec)
		tr->Update();
}

void Scene6::PreRender()
{
}

void Scene6::Render()
{
	for (TextureRect* tr : trVec)
		tr->Render();
}

void Scene6::PostRender()
{
	Gui::Get()->TextureRectGUIS(trVec, "TextureRects");
}

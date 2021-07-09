#include "stdafx.h"
#include "Scene6_ImGui.h"

Scene6::Scene6()
{
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
	Path::GetFiles(&paths, L"./_Textures/", L"*.*", true);
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

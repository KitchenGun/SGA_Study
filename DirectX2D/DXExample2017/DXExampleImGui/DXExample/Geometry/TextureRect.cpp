#include "stdafx.h"
#include "TextureRect.h"

TextureRect::TextureRect(Vector3 position, Vector3 size, float rotation)
	:
	position(position),
	size(size),
	rotation(rotation)
{
	//���� ���� �Է�
	vertices.assign(4, VertexTexture());
	vertices[0].position = Vector3(-0.5f, -0.5f, 0.0f);
	vertices[0].uv = Vector2(0.0f, 1.0f);

	vertices[1].position = Vector3(-0.5f, 0.5f, 0.0f);
	vertices[1].uv = Vector2(0.0f, 0.0f);

	vertices[2].position = Vector3(0.5f, -0.5f, 0.0f);
	vertices[2].uv = Vector2(1.0f, 1.0f);

	vertices[3].position = Vector3(0.5f, 0.5f, 0.0f);
	vertices[3].uv = Vector2(1.0f, 0.0f);

	indices = { 0,1,2,2,1,3 };

	//Ŭ����ȭ �� ��ü ����
	VB = new VertexBuffer();
	IB = new IndexBuffer();

	VS = new VertexShader();
	PS = new PixelShader();

	IL = new InputLayout();

	WB = new WorldBuffer();

	//��ü���� �Լ� ȣ��
	VB->Create(vertices, D3D11_USAGE_DYNAMIC);
	IB->Create(indices, D3D11_USAGE_IMMUTABLE);


	shaderPath = L"./_Shaders/VertexTexture.hlsl";
	//����� ����ȭ
	VS->Create(shaderPath, "VS");
	PS->Create(shaderPath, "PS");

	IL->Create(VertexTexture::descs, VertexTexture::count, VS->GetBlob());

	D3DXMatrixIdentity(&world);

	D3DXMatrixIdentity(&S);
	D3DXMatrixIdentity(&R);
	D3DXMatrixIdentity(&T);

	D3DXMatrixScaling(&S, size.x, size.y, size.z);
	D3DXMatrixRotationZ(&R, (float)D3DXToRadian(rotation));
	D3DXMatrixTranslation(&T, position.x, position.y, position.z);

	world = S * R * T;

	WB->SetWorld(world);
	//������ colorbuffer��� ���
	SB = new SelectBuffer();
	//blur ��� ������
	BB = new BlurBuffer();
	LB = new LocalBuffer();
	//�»�� ���� ��ǥ
	LB->SetLocalRect({ 100,100,400,400 });
}

TextureRect::~TextureRect()
{
	SAFE_RELEASE(srv);

	SAFE_DELETE(LB);
	SAFE_DELETE(BB);
	SAFE_DELETE(SB);

	SAFE_DELETE(WB);

	SAFE_DELETE(IL);

	SAFE_DELETE(PS);
	SAFE_DELETE(VS);

	SAFE_DELETE(IB);
	SAFE_DELETE(VB);
}

void TextureRect::SetSRV(wstring path)
{
	texturePath = path;
	//�ؽ��İ� ���̴��� ���� �� �� �ְ� ��
	ViewFactory::GenerateSRV(path, &srv);
}

void TextureRect::SetShader(wstring shaderPath)
{
	//vs��ps��ü�� �Լ� ȣ��// �����߰��� ��ü�Ҽ��ֵ��� �Լ�ȭ �Ͽ���
	if (VS)
	{
		VS->Clear();
		VS->Create(shaderPath, "VS");
	}

	if (PS)
	{	
		PS->Clear();
		PS->Create(shaderPath, "PS");
	}
}

void TextureRect::Move(Vector3 position)
{
	this->position += position;
	D3DXMatrixTranslation(&T, this->position.x, this->position.y, this->position.z);

	world = S * R * T;
	WB->SetWorld(world);
}

void TextureRect::MoveLocalRect(Vector4 localMove)
{	//���������� �����Ͽ� �̵��� ó����
	LB->MoveLocalRect(localMove);
}

void TextureRect::Update()
{
	if (Keyboard::Get()->Down(VK_00))
	{
		BB->SetCount(1);
	}
	else if (Keyboard::Get()->Down(VK_01))//1�� ������ selection���� �ٲ�
	{
		SB->SetSelection(1);
		BB->SetCount(2);
	}
	else if(Keyboard::Get()->Down(VK_02))
	{
		SB->SetSelection(2);
		BB->SetCount(4);
	}
	else if(Keyboard::Get()->Down(VK_03))
	{
		SB->SetSelection(3);
		BB->SetCount(8);
	}
	else if (Keyboard::Get()->Down(VK_04))
	{
		SB->SetSelection(4);
		BB->SetCount(32);
	}

}

void TextureRect::Render()
{
	VB->SetIA();
	IB->SetIA();
	IL->SetIA();
	//�⺻ ���� ���� ��� ����
	DC->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);


	WB->SetVSBuffer(0);
	VS->SetShader();

	PS->SetShader();
	if (srv)
	{
		DC->PSSetShaderResources(0, 1, &srv);
	}
	SB->SetPSBuffer(0);//ps�ܰ迡�� ����ϴ� ù��° ���̿��� 0���� �Է��ص���
	//��ȿ�����ؼ� �߰���
	BB->SetPSBuffer(1);
	LB->SetPSBuffer(2);
	//�ε��� ���۸� �̿��ؼ� �׸���
	DC->DrawIndexed(IB->GetCount(), 0, 0);
}

void TextureRect::GUI(int ordinal)
{
	string objName = "TextureRect" + to_string(ordinal);//ordinal�� ���� ������ ��
	if (ImGui::BeginMenu(objName.c_str()))
	{//â�ȿ� �޴��� ���ڴ�
		ImGui::Text(objName.c_str());
		ImGui::Text(String::ToString(texturePath).c_str());
		ImGui::Text(String::ToString(shaderPath).c_str());

		if (ImGui::Button("ChangeImage", ImVec2(100, 30)))
		{
			ChangeImageFunc();
		}
		if (ImGui::Button("ChangeShader", ImVec2(100, 30)))
		{
			ChangeShaderFunc();
		}
		if (ImGui::InputText("InputText", text, sizeof(text), ImGuiInputTextFlags_EnterReturnsTrue))
		{
			SaveTextAsFile(text);
		}
		ImGui::EndMenu();
	}
	else
	{

	}
}

void TextureRect::ChangeImageFunc(const wstring & path)
{
	if (path.length() < 1)
	{
		function<void(wstring)> func = bind(&TextureRect::ChangeImageFunc, this, placeholders::_1);
		Path::OpenFileDialog(L"", Path::ImageFilter, L"./_Textures/", func, handle);
	}
	else
	{
		SetSRV(path);
	}
}

void TextureRect::ChangeShaderFunc(const wstring & path)
{
	if (path.length() < 1)
	{
		function<void(wstring)> func = bind(&TextureRect::ChangeShaderFunc, this, placeholders::_1);
		Path::OpenFileDialog(L"", Path::ShaderFilter, L"./_Shaders/", func, handle);
	}
	else
	{
		SetShader(path);
	}
}

void TextureRect::SaveTextAsFile(const string & text, const wstring & path)
{
	if (path.length() < 1)
	{
		function<void(wstring)> func = bind(&TextureRect::SaveTextAsFile, this, text, placeholders::_1);
		Path::SaveFileDialog(L"", Path::TextFilter, L"./", func, handle);
	}
	else
	{
		ofstream writefile(path.c_str());
		if (writefile.is_open())
		{
			writefile << text << endl;
			writefile.clear();
		}
		writefile.close();
	}
}

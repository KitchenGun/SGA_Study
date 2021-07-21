#include "stdafx.h"
#include "AnimationRect.h"

AnimationRect::AnimationRect(Vector3 position, Vector3 size, float rotation)
	:position(position),
	size(size),
	rotation(rotation)
{
	vertices.assign(4, VertexTexture());
	vertices[0].position = Vector3(-0.5f, -0.5f, 0.0f);
	vertices[0].uv = Vector2(0.0f, 1.0f);

	vertices[1].position = Vector3(-0.5f, -0.5f, 0.0f);
	vertices[1].uv = Vector2(0.0f, 1.0f);
	
	vertices[2].position = Vector3(-0.5f, -0.5f, 0.0f);
	vertices[2].uv = Vector2(0.0f, 1.0f);
			 
	vertices[3].position = Vector3(-0.5f, -0.5f, 0.0f);
	vertices[3].uv = Vector2(0.0f, 1.0f);

	indices = { 0,1,2,2,1,3 };

	//클래스화 한 객체 생성
	VB = new VertexBuffer();
	IB = new IndexBuffer();

	VS = new VertexShader();
	PS = new PixelShader();

	IL = new InputLayout();

	WB = new WorldBuffer();

	//객체에서 함수 호출
	VB->Create(vertices, D3D11_USAGE_DYNAMIC);
	IB->Create(indices, D3D11_USAGE_IMMUTABLE);


	wstring shaderPath = L"./_Shaders/Animation.hlsl";
	//경로의 변수화
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
	
	rockman = new Texture2D(L"./_Textures/록맨.bmp");

	runR = new AnimationClip(L"RunR", rockman, 10, { 0,0 }, { (float)rockman->GetWidth(),(float)rockman->GetHeight() / 2 });
	runL = new AnimationClip(L"RunL", rockman, 10, { 0,(float)rockman->GetHeight() / 2 },});

}

AnimationRect::~AnimationRect()
{
	SAFE_RELEASE(SS);
	SAFE_RELEASE(BS);

	SAFE_DELETE(rockman);
	SAFE_DELETE(animator);
	SAFE_DELETE(runR);
	SAFE_DELETE(runL);

	SAFE_DELETE(WB);

	SAFE_DELETE()
}

void AnimationRect::Update()
{
}

void AnimationRect::Render()
{
}

void AnimationRect::Move(Vector3 position)
{
}

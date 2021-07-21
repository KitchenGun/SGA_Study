#include "stdafx.h"
#include "AnimationRect.h"
#include "Utilities/Animator.h"

AnimationRect::AnimationRect(Vector3 position, Vector3 size, float rotation)
	:position(position),
	size(size),
	rotation(rotation)
{
	vertices.assign(4, VertexTexture());
	vertices[0].position = Vector3(-0.5f, -0.5f, 0.0f);
	vertices[0].uv = Vector2(0.0f, 1.0f);

	vertices[1].position = Vector3(-0.5f, 0.5f, 0.0f);
	vertices[1].uv = Vector2(0.0f, 0.0f);

	vertices[2].position = Vector3(0.5f, -0.5f, 0.0f);
	vertices[2].uv = Vector2(1.0f, 1.0f);

	vertices[3].position = Vector3(0.5f, 0.5f, 0.0f);
	vertices[3].uv = Vector2(1.0f, 0.0f);

	indices = { 0, 1, 2, 2, 1, 3 };

	VB = new VertexBuffer();
	IB = new IndexBuffer();

	VS = new VertexShader();
	PS = new PixelShader();

	IL = new InputLayout();

	VB->Create(vertices, D3D11_USAGE_DYNAMIC);
	IB->Create(indices, D3D11_USAGE_IMMUTABLE);

	wstring shaderPath = L"./_Shaders/Animation.hlsl";
	VS->Create(shaderPath, "VS");
	PS->Create(shaderPath, "PS");

	IL->Create(VertexTexture::descs, VertexTexture::count, VS->GetBlob());

	WB = new WorldBuffer();
	D3DXMatrixIdentity(&world);

	D3DXMatrixIdentity(&S);
	D3DXMatrixIdentity(&R);
	D3DXMatrixIdentity(&T);

	D3DXMatrixScaling(&S, size.x, size.y, size.z);
	D3DXMatrixRotationZ(&R, (float)D3DXToRadian(rotation));
	D3DXMatrixTranslation(&T, position.x, position.y, position.z);

	world = S * R * T;

	WB->SetWorld(world);

	rockman = new Texture2D(L"./_Textures/·Ï¸Ç.bmp");

	runR = new AnimationClip(L"RunR", rockman, 10, { 0, 0 }, { (float)rockman->GetWidth(), (float)rockman->GetHeight() / 2 });
	runL = new AnimationClip(L"RunL", rockman, 10, { 0, (float)rockman->GetHeight() / 2 }, { (float)rockman->GetWidth(), (float)rockman->GetHeight() }, true);
	animator = new Animator(runR);
	animator->AddAnimClip(runL);

	//Create BlnedState
	{
		D3D11_BLEND_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BLEND_DESC));

		desc.AlphaToCoverageEnable = false;
		desc.IndependentBlendEnable = false;

		desc.RenderTarget[0].BlendEnable = true;
		desc.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
		desc.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
		desc.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;
		desc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
		desc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
		desc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
		desc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;

		HRESULT hr = DEVICE->CreateBlendState(&desc, &BS);
		ASSERT(hr);
	}

	//Create SamplerState
	{
		D3D11_SAMPLER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_SAMPLER_DESC));

		desc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
		desc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
		desc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;

		desc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
		desc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
		desc.MaxAnisotropy = 16;
		desc.MinLOD = numeric_limits<float>::min();
		desc.MaxLOD = numeric_limits<float>::max();
		desc.MipLODBias = 0.0f;

		HRESULT hr = DEVICE->CreateSamplerState(&desc, &SS);
		ASSERT(hr);
	}

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

	SAFE_DELETE(IL);

	SAFE_DELETE(PS);
	SAFE_DELETE(VS);

	SAFE_DELETE(IB);
	SAFE_DELETE(VB);
}

void AnimationRect::Update()
{
	animator->Update();

	{
		D3D11_MAPPED_SUBRESOURCE subResource;
		DC->Map(VB->GetResource(), 0, D3D11_MAP_WRITE_DISCARD, 0, &subResource);

		vertices[0].uv = Vector2(animator->GetCurrentFrame().x, animator->GetCurrentFrame().y + animator->GetTexelFrameSize().y);
		vertices[1].uv = animator->GetCurrentFrame();
		vertices[2].uv = animator->GetCurrentFrame() + animator->GetTexelFrameSize();
		vertices[3].uv = Vector2(animator->GetCurrentFrame().x + animator->GetTexelFrameSize().x, animator->GetCurrentFrame().y);

		memcpy(subResource.pData, vertices.data(), sizeof(VertexTexture) * vertices.size());
		DC->Unmap(VB->GetResource(), 0);
	}
}

void AnimationRect::Render()
{
}

void AnimationRect::Move(Vector3 position)
{
}

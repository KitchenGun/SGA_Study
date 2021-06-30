//glsl과의 차이는 메인 함수없이 특정함수를 진입점으로 사용할수있는 특징이 있다
struct VertexInput//pos 색 들어있음
{
	float4 position : POSITION0;
	//Semantics이란?	
	//사용자가 임의로 설정하는 전역변수나 버텍스 쉐이더의 입력 구조체의 변수들이 어떤 자료와 연결될지 알려주는 것이 시맨틱이다
	float2 uv : TEXCOORD0;
};
struct PixelInput
{
	float4 position : SV_POSITION0;//sv_ system value의 약자로 특별한 의미를 가진 Semantics name으로 사용됨
    float2 uv : TEXCOORD0;
};


cbuffer World : register(b0)
{
    matrix _world;
};

cbuffer ViewProjection : register(b1) //상수 버퍼를 보낸다
{
    matrix _view;
    matrix _proj;
};

cbuffer Selection : register(b0)
{
	int _selection;
};



	PixelInput VS(
	VertexInput input)//입력 pos와 입력 color 를 그대로 PixelInput 형태로 반환
{
	PixelInput output;
    //백터와 행렬의 곱을 수행할것
    output.position = mul(input.position, _world);//world 공간으로 변환
    output.position = mul(output.position, _view);//view 공간에서 변화
    output.position = mul(output.position, _proj); //projection 공간을 변환
    
    //현재방식은 정점별 방식이 아닌 일반적으로 사용하는 방식
    output.uv = input.uv;
    
    return output;
}

Texture2D srcTex0 : register(t0);

SamplerState samp : register(s0);

float4 PS(PixelInput input) : SV_Target //현재 세팅한 타겟에 그려라
{
	float4 result = 0;
	
	if (_selection == 1)
	{
		result = srcTex0.Sample(samp, input.uv);
	}
	else if (_selection == 2)//좌우 거울
	{
		float4 l = srcTex0.Sample(samp, input.uv);
		float4 r = srcTex0.Sample(samp, float2(input.uv.x - 0.5f, input.uv.y));
		
		if (input.uv.x < 0.5f)
			result = l;
		if (input.uv.x > 0.5f)
			result = r;
		
		if (input.uv.x > 0.499f && input.uv.x < 0.501f)
		{
			result = float4(1, 1, 1, 1);
		}
	}
	else if (_selection == 3)//4분면 거울
	{
		float4 site1 = srcTex0.Sample(samp, 2 * float2(input.uv.x, input.uv.y));
		float4 site2 = srcTex0.Sample(samp, 2 * float2(input.uv.x - 0.5f, input.uv.y));
		float4 site3 = srcTex0.Sample(samp, 2 * float2(input.uv.x, input.uv.y - 0.5f));
		float4 site4 = srcTex0.Sample(samp, 2 * float2(input.uv.x - 0.5f, input.uv.y - 0.5f));
		
		if (input.uv.x < 0.5f && input.uv.y < 0.5f)
			result = site1;
		if (input.uv.x > 0.5f && input.uv.y < 0.5f)
			result = site2;
		if (input.uv.x < 0.5f && input.uv.y > 0.5f)
			result = site3;
		if (input.uv.x > 0.5f && input.uv.y > 0.5f)
			result = site4;
		
		if (input.uv.x > 0.499f && input.uv.x < 0.501f)
		{
			result = float4(1, 1, 1, 1);
		}
		if (input.uv.y > 0.499f && input.uv.y < 0.501f)
		{
			result = float4(1, 1, 1, 1);
		}
	}
	else if (_selection == 4)//4분면 반전 거울
	{
		float4 site1 = srcTex0.Sample(samp, 2 * float2(input.uv.x, input.uv.y));
		float4 site2 = srcTex0.Sample(samp, 2 * float2(input.uv.x - 0.5f, input.uv.y));
		float4 site3 = srcTex0.Sample(samp, 2 * float2(input.uv.x, input.uv.y - 0.5f));
		float4 site4 = srcTex0.Sample(samp, 2 * float2(input.uv.x - 0.5f, input.uv.y - 0.5f));
		
		if (input.uv.x < 0.5f && input.uv.y < 0.5f)
			result = site1;
		if (input.uv.x > 0.5f && input.uv.y < 0.5f)
			result = site2;
		if (input.uv.x < 0.5f && input.uv.y > 0.5f)
			result = site3;
		if (input.uv.x > 0.5f && input.uv.y > 0.5f)
			result = site4;
		
		if (input.uv.x > 0.499f && input.uv.x < 0.501f)
		{
			result = float4(1, 1, 1, 1);
		}
		if (input.uv.y > 0.499f && input.uv.y < 0.501f)
		{
			result = float4(1, 1, 1, 1);
		}
	}
	return result;
}
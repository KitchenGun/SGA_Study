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
	float2 _textureSize;
};

cbuffer BlurBuffer : register(b1)
{
	uint _count;
};

cbuffer BlurBuffer : register(b2)
{
	float4 _localRect;
};

PixelInput VS(VertexInput input)//입력 pos와 입력 color 를 그대로 PixelInput 형태로 반환
{
	PixelInput output;
    //백터와 행렬의 곱을 수행할것
	output.position = mul(input.position, _world); //world 공간으로 변환
	output.position = mul(output.position, _view); //view 공간에서 변화
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
	float4 color = srcTex0.Sample(samp, input.uv);
	
	float2 arr[8] =
	{
		float2(-1, -1), float2(0, -1), float2(1, -1),
		float2(-1, 0),				   float2(1, 0),
		float2(-1, 1), float2(0, 1),   float2(1, 1)
	};
	
	
	[flatten]
	if (input.uv.x > _localRect.x / _textureSize.x &&
		input.uv.x < _localRect.z / _textureSize.x &&
		input.uv.y > _localRect.y / _textureSize.y &&
		input.uv.y < _localRect.w / _textureSize.y)
	{
		for (int blur = 0; blur < _count; blur++)
		{
			for (int i = 0; i < 8; i++)
			{
				float x = arr[i].x * (float) blur / _textureSize.x;
				float y = arr[i].y * (float) blur / _textureSize.y;
				
				float2 uv = input.uv + float2(x, y);
				color += srcTex0.Sample(samp, uv);
			}
		}
		color /= _count * 8 + 1;
	}
	else
	{
		
	}
	return float4(color.rgb,1);
}

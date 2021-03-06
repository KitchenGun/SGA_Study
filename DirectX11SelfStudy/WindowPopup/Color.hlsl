struct VertexInput
{
	float4 position : POSITION0;//position == semantic(데이터의 출처와 역할에 대한 분명한 의미를 부여하기위한 키워드) 뒤의 숫자는 semantic의 인덱스
	float4 color : COLOR0;
};

struct PixelInput
{
	float4 position : SV_POSITION0;//SV = 시스템 value 더 중요한 값
	float4 color : COLOR0;
};

cbuffer TransformBuffer : register(b0)//->0~13  16byte의 배수가 되야함//4096*16이하만 가능함
{
    matrix world;//matrix == float4X4
    matrix view;
    matrix proj;
};

PixelInput VS(VertexInput input)
{
	//1*4		4*4 -->1*4//위치 벡터를 다른공간으로 이동하기 위해서는 벡터의 위치를 곱해주면된다.
	//1,2,3,1 * 0000
	//			0000
	//			0000
	//			0000
	PixelInput output;
    output.position = mul(input.position,world);
    output.position = mul(output.position,view);
    output.position = mul(output.position, proj);
	
	output.color = input.color;

	return output;
}

float4 PS(PixelInput input) : SV_Target//현재 세팅한 타겟에 그려라
{
    return input.color;
}
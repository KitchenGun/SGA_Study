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

PixelInput VS(VertexInput input)
{
	PixelInput output;
	output.position = input.position;
	output.color = input.color;

	return output;
}

float4 PS(PixelInput input) : SV_Target//현재 세팅한 타겟에 그려라
{
    return input.color;
}
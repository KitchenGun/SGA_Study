struct VertexInput//pos 색 들어있음
{
	float4 position : POSITIONT0;
	float4 color : COLOR0;
};

struct PixelInput
{
	float4 position : SV_POSITIONT0;
	float4 color : COLOR0;
};

PixelInput VS(VertexInput input)//입력 pos와 입력 color 를 그대로 PixelInput 형태로 반환
{
    PixelInput output;
    
    output.position = input.position;
    output.color = input.color;
    
    return output;
}


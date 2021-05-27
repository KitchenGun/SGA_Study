struct VertexInput//pos �� �������
{
	float4 position : POSITIONT0;
	float4 color : COLOR0;
};

struct PixelInput
{
	float4 position : SV_POSITIONT0;
	float4 color : COLOR0;
};

PixelInput VS(VertexInput input)//�Է� pos�� �Է� color �� �״�� PixelInput ���·� ��ȯ
{
    PixelInput output;
    
    output.position = input.position;
    output.color = input.color;
    
    return output;
}


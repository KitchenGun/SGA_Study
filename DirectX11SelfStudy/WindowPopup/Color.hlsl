struct VertexInput
{
	float4 position : POSITION0;//position == semantic(�������� ��ó�� ���ҿ� ���� �и��� �ǹ̸� �ο��ϱ����� Ű����) ���� ���ڴ� semantic�� �ε���
	float4 color : COLOR0;
};

struct PixelInput
{
	float4 position : SV_POSITION0;//SV = �ý��� value �� �߿��� ��
	float4 color : COLOR0;
};

PixelInput vs(VertexInput input)
{
	PixelInput output;
	output.position = input.position;
	output.color = input.color;

	return output;
}
#pragma once
class SelectBuffer : public ShaderBuffer
{
public:
	SelectBuffer()
		:ShaderBuffer(&data, sizeof(Struct))
	{

	}

	void SetSelection(int selection)
	{
		data.selection = selection;
	}

	struct Struct
	{//데이터 패딩
		int selection = 1;
		Vector3 dummy;
	};

private:
	Struct data;
};
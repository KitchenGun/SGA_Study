#include "stdafx.h"
#include "FileStream.h"
//stream �帧�̴� -> ������ �帣�� ������ �����ϴ� 
//buffer ���� ���� ��� -> ����� ������ �ִٰ� ������ �÷������� �ӽ������� �����Ͱ� �ӹ��ٰ� �Ҽ��ִ�.
//������ �帧�� ���� �����δ�.
//cin�� ���ϸ� "asd"�Է��ϰ� enter�� ���� Ǫ�� ����
FileStream::FileStream(string path, UINT flags)
{
	isOpen = false;
	this->flags = flags;

	int iosFlags = ios::binary;									//���� ���
	//FILE *pstWStream = fopen("Resources/E11_01.txt", "wt");
	iosFlags |= this->flags&FILE_STREAM_WRITE ? ios::out : 0;	//����
	iosFlags |= this->flags&FILE_STREAM_READ ? ios::in : 0;		//�б�
	
	if (this->flags & FILE_STREAM_WRITE)
	{
		out.open(path, iosFlags);
		if (out.fail())
		{
			ASSERT(false);
			return;
		}
	}
	else if (this->flags&FILE_STREAM_READ)
	{
		in.open(path, iosFlags);
		if (in.fail())
		{
			ASSERT(false);
			return;
		}
	}
	isOpen = true;
}

FileStream::~FileStream()
{
	Close();
}
void FileStream::Close()
{
	if (flags & FILE_STREAM_WRITE)
	{
		out.flush();
		out.close();
	}
	else if (flags & FILE_STREAM_READ)
	{
		in.clear();
		in.close();
	}
}
//endl�� �ۼ��ϸ� ���� ���๮�ڰ� �����ʴ´� ���� ȿ���� ��������
void FileStream::Skip(UINT n)
{
	if (flags & FILE_STREAM_WRITE)
	{
		//n = offset �󸶳� �ǳ� �۰ų� 
		out.seekp(n, ios::cur);
	}
}

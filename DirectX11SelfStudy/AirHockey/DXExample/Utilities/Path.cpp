#include "stdafx.h"
#include "Path.h"

bool Path::ExistFile(string path)
{
	return ExistFile(String::ToWString(path));
}

bool Path::ExistFile(wstring path)
{
	//unsigned short
	//word
	//unsigned long
	DWORD fileValue = GetFileAttributes(path.c_str());//���� ���� �Ӽ� Ȯ�� ���� ������ -1
	//�ּҰ����� ���� ���� ���� �� �ִ밪�� ������ ���� -> ��� �÷ο�
	return fileValue < 0xFFFFFFFF;//�ִ밪 = -1 = ������ ���»�Ȳ
}

bool Path::ExistDirectory(string path)//������ �����ϴ� �� ���ϴ��� Ȯ�ο�
{

	return ExistDirectory(String::ToWString(path));
}

bool Path::ExistDirectory(wstring path)//�̹� ��ΰ� �����ϴ��� �������� �ʴ��� Ȯ��
{
	DWORD attribute = GetFileAttributes(path.c_str());
	//INVALID_FILE_ATTRIBUTES�� (DWORD)-1				��Ʈ������ and�� ����Ͽ� �Ѵ� 1�� ��츦 ã�°��� 
	BOOL temp = (attribute != INVALID_FILE_ATTRIBUTES && (attribute & FILE_ATTRIBUTE_DIRECTORY));
	//���� ������ Ȯ���ϸ鼭 attribute�� ���� ���丮�ΰ��� Ȯ���ϰ� Ȯ�ΰ��� ��ȯ
	return temp == TRUE;
}

string Path::Combine(string path1, string path2)//string�� 2���� ��ġ��
{
	return path1+path2;
}

wstring Path::Combine(wstring path1, wstring path2)
{
	return path1 + path2;
}

string Path::Combine(vector<string> paths)
{//for���� ����ؼ� vector�ȿ� �и��Ǿ��ִ� ��Ʈ���� ��ġ�� ���� 
	string temp = "";
	for (string path : paths)
		temp += path;
	return temp;
}

wstring Path::Combine(vector<wstring> paths)
{
	wstring temp = L"";
	for (wstring path : paths)
		temp += path;
	return temp;
}

string Path::GetDirectoryName(string path)
{//���� ���� �� ��θ� ��� �Լ�
	String::Replace(&path, "\\", "/");
	size_t index = path.find_last_of('/');

	return path.substr(0, index + 1);
}

wstring Path::GetDirectoryName(wstring path)
{
	String::Replace(&path, L"\\", L"/");
	size_t index = path.find_last_of('/');

	return path.substr(0, index + 1);
}

string Path::GetExtension(string path)
{
	//Ȯ���ڸ� ����
	String::Replace(&path, "\\", "/");
	size_t index = path.find_last_of('.');

	return path.substr(index+1,path.length());
}

wstring Path::GetExtension(wstring path)
{
	String::Replace(&path, L"\\", L"/");
	size_t index = path.find_last_of('.');

	return path.substr(index + 1, path.length());
}

wstring Path::GetFileName(wstring path)
{
	String::Replace(&path, L"\\", L"/");
	size_t index = path.find_last_of('/');//��ü ��ο��� ���������� ������/�� ã�ƶ�
	//�̸��� Ȯ���ڸ� ��ȯ 
	return path.substr(index + 1, path.length());
}

string Path::GetFileName(string path)
{
	String::Replace(&path, "\\", "/");
	size_t index = path.find_last_of('/');

	return path.substr(index + 1, path.length());
}

string Path::GetFileNameWithoutExtension(string path)
{
	//Ȯ���ڸ� ������ �����̸�
	string fileName = GetFileName(path);
	size_t index = fileName.find_last_of('.');

	return fileName.substr(0,index);
}

wstring Path::GetFileNameWithoutExtension(wstring path)
{
	wstring fileName = GetFileName(path);
	size_t index = fileName.find_last_of('.');

	return fileName.substr(0, index);
}

//Ȯ���ڿ� ���������� Ȯ���ϱ� ���ؼ� �ۼ���
						//��	 =	  �׸�+�ƹ�����,Ȯ����
const WCHAR* Path::ImageFilter = L"Image\0*.png;*.bmp;*.jpg";
const WCHAR* Path::ShaderFilter = L"HLSL file\0*.hlsl";
const WCHAR* Path::TextFilter = L"Text file\0*.txt";
const WCHAR* Path::SoundFilter = L"Sound file\0*.wav;*.mp3;*.flac";

void Path::OpenFileDialog(wstring file, const WCHAR * filter, wstring folder, function<void(wstring)> func, HWND hwnd)
{
	WCHAR name[255];//������ �����̸�
	wcscpy_s(name, file.c_str());
	//�ʱ��η� ������ string����
	wstring tempFolder = folder;
	//������ ��η� ����
	String::Replace(&tempFolder, L"/", L"\\");

	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFilter = filter;
	ofn.lpstrFile = name;
	ofn.lpstrTitle = L"�ҷ�����";
	ofn.nMaxFile = 255;
	//���� ��� �ʱ�ȭ
	ofn.lpstrInitialDir = tempFolder.c_str();
	ofn.Flags = OFN_NOCHANGEDIR;

	if (GetOpenFileName(&ofn) == TRUE)//������ ����������
	{
		if (func != NULL)
		{
			wstring loadName = name;
			String::Replace(&loadName, L"\\", L"/");
			//��ȯ���� �Ű������� �Լ��� ����
			func(loadName);
		}
	}
}

void Path::SaveFileDialog(wstring file, const WCHAR * filter, wstring folder, function<void(wstring)> func, HWND hwnd)
{
	WCHAR name[255];
	wcscpy_s(name, file.c_str());

	wstring tempFolder = folder;
	
	String::Replace(&tempFolder, L"/", L"\\");
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFilter = filter;
	ofn.lpstrFile = name;
	ofn.lpstrTitle = L"�����ϱ�";
	ofn.nMaxFile = 255;
	ofn.lpstrInitialDir = tempFolder.c_str();
	ofn.Flags = OFN_NOCHANGEDIR;
	//
	if (filter == TextFilter)
		ofn.lpstrDefExt = L".txt";
	else if (filter == ShaderFilter)
		ofn.lpstrDefExt = L".hlsl";


	if (GetOpenFileName(&ofn) == TRUE)
	{
		if (func != NULL)
		{
			wstring saveName = name;
			String::Replace(&saveName, L"\\", L"/");

			func(saveName);
		}
	}
}

void Path::GetFiles(vector<string>* files, string path, string filter, bool bFindSubFolder)
{
	vector<wstring> wFiles;
	wstring wPath = String::ToWString(path);
	wstring wFilter = String::ToWString(filter);

	GetFiles(&wFiles, wPath, wFilter, bFindSubFolder);
	for (wstring str : wFiles)
	{
		files->push_back(String::ToString(str));
	}
}
//										���ϵ��� �ִ� ���
void Path::GetFiles(vector<wstring>* files, wstring path, wstring filter, bool bFindSubFolder)
{
	//������ ������ ��ȯ ��ο� �����鼭 ���Ϳ� �����ϴ� �ڷ���� �ҷ���
	wstring file = path + filter;

	WIN32_FIND_DATA findData;//���������� �Ѱ��ִ� �Լ��� ȣ���� �Ǵ� �ڷ���
	HANDLE handle = FindFirstFile(file.c_str(), &findData);
	if (handle != INVALID_HANDLE_VALUE)//�ڵ��� �ִ��� ������ Ȯ��
	{
		do
		{
			if (findData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)//�ҷ��� ���� �Ӽ��� ������ ���
			{
				//���������� Ž���Ұ��ΰ�?   .�� ������ ���� �����̱⶧���� �����Ѵ�
				if (bFindSubFolder == true && findData.cFileName[0] != '.')//���ο� ������ �ִ� ��� ������ �Ѱǰ� ���Ұǰ�?
				{
					wstring folder = path + wstring(findData.cFileName) + L"/";//�������� /�־��ְڴٴ� �ǹ�
					GetFiles(files, folder, filter, bFindSubFolder);//����Լ��� ����ؼ� ��� ������ �� ��� ���� ���� Ž��
				}
			}
			else//�Ӽ��� ������ �ƴ϶� �����϶� �̸��� ���Ϳ� ����
			{
				wstring fileName = path + wstring(findData.cFileName);
				files->push_back(fileName);
			}
		} while (FindNextFile(handle, &findData));//���������Ͱ� �����Ѵٸ� ��� �ݺ�
		//������ Ž�� ����
		FindClose(handle);
	}
}

void Path::CreateFolder(string path)//folder ����
{
	CreateFolder(String::ToWString(path));
}

void Path::CreateFolder(wstring path)
{
	//��ΰ� �������������� ���� ����
	if (ExistDirectory(path) == false)
		CreateDirectory(path.c_str(), NULL);//���� ������ �ɼ��� null ex)�б� ����, ����
}

void Path::CreateFolders(string path)
{
	CreateFolders(String::ToWString(path));
}

void Path::CreateFolders(wstring path)
{
	//���� ���� ����鼭 ������������ �ѹ��� ����� 
	String::Replace(&path, L"\\", L"/");

	vector<wstring> folders;
	// �ڸ��� ������ / �̴� �׸��� vector�� �־���
	String::SplitString(&folders, path, L"/");

	wstring temp = L"";
	for (wstring folder : folders)
	{
		temp += folder + L"/";
		CreateFolder(temp);
	}
}

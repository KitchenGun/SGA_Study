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
	DWORD fileValue = GetFileAttributes(path.c_str());//기존 파일 속성 확인
	return fileValue < 0xFFFFFFFF;//파일이 없으면 음수를 반환함 usigned long 최대값을 반환함 -> 언더 플로우
}

bool Path::ExistDirectory(string path)//파일이 존재하는 지 안하는지 확인용
{

	return ExistDirectory(String::ToWString(path));
}

bool Path::ExistDirectory(wstring path)
{
	DWORD attribute = GetFileAttributes(path.c_str());

	BOOL temp = (attribute != INVALID_FILE_ATTRIBUTES && (attribute & FILE_ATTRIBUTE_DIRECTORY));
	
	return temp = TRUE;
}

string Path::Combine(string path1, string path2)//string문 2개를 합치기
{
	return path1+path2;
}

wstring Path::Combine(wstring path1, wstring path2)
{
	return path1 + path2;
}

string Path::Combine(vector<string> paths)
{//for문을 사용해서 vector안에 분리되어있는 스트링을 합치는 역할 
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
{//주소를 얻는 함수
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
	//확장자를 얻음
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
	size_t index = path.find_last_of('/');//전체 경로에서 마지막으로 나오는/를 찾아라
	//이름과 확장자를 반환 
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
	//확장자를 제외한 파일이름
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

const WCHAR* Path::ImageFilter = L"Image\0*.png;*.bmp;*.jpg";
const WCHAR* Path::ShaderFilter = L"HLSL file\0*.hlsl";
const WCHAR* Path::TextFilter = L"Text file\0*.txt";

void Path::OpenFileDialog(wstring file, const WCHAR * filter, wstring folder, function<void(wstring)> func, HWND hwnd)
{
	WCHAR name[255];
	wcscpy_s(name, file.c_str());
	wstring tempFolder = folder;

	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFilter = filter;
	ofn.lpstrFile = name;
	ofn.lpstrFileTitle = L"불러오기";
	ofn.nMaxFile = 255;
	ofn.lpstrInitialDir = tempFolder.c_str();
	ofn.Flags = OFN_NOCHANGEDIR;

	if (GetOpenFileName(&ofn) == TRUE)//파일을 열수있으면
	{
		if (func != NULL)
		{
			wstring loadName = name;
			String::Replace(&loadName, L"\\", L"/");
			//변환값을 매개변수의 함수에 전달
			func(loadName);
		}
	}
}

void Path::SaveFileDialog(wstring file, const WCHAR * filter, wstring folder, function<void(wstring)> func, HWND hwnd)
{
	WCHAR name[255];
	wcscpy_s(name, file.c_str());
	wstring tempFolder = folder;

	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = hwnd;
	ofn.lpstrFilter = filter;
	ofn.lpstrFile = name;
	ofn.lpstrFileTitle = L"저장하기";
	ofn.nMaxFile = 255;
	ofn.lpstrInitialDir = tempFolder.c_str();
	ofn.Flags = OFN_NOCHANGEDIR;

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

void Path::GetFiles(vector<wstring>* files, wstring path, wstring filter, bool bFindSubFolder)
{
	wstring file = path + filter;

	WIN32_FIND_DATA findData;
	HANDLE handle = FindFirstFile(file.c_str(), &findData);
	if (handle != INVALID_HANDLE_VALUE)
	{
		do
		{
			if (findData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
			{
				if (bFindSubFolder == true && findData.cFileName[0] != '.')
				{
					wstring folder = path + wstring(findData.cFileName) + L"/";
					GetFiles(files, folder, filter, bFindSubFolder);
				}
			}
			else
			{
				wstring fileName = path + wstring(findData.cFileName);
				files->push_back(fileName);

			}
		} while (FindNextFile(handle, &findData));

		FindClose(handle);
	}
}

void Path::CreateFolder(string path)
{
	CreateFolder(String::ToWString(path));
}

void Path::CreateFolder(wstring path)
{
	if (ExistDirectory(path) == false)
		CreateDirectory(path.c_str(), NULL);
}

void Path::CreateFolders(string path)
{
	CreateFolders(String::ToWString(path));
}

void Path::CreateFolders(wstring path)
{
	String::Replace(&path, L"\\", L"/");

	vector<wstring> folders;
	String::SplitString(&folders, path, L"/");

	wstring temp = L"";
	for (wstring folder : folders)
	{
		temp += folder + L"/";
		CreateFolder(temp);
	}
}

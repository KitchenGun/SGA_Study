#include "stdafx.h"
#include "Path.h"

bool Path::ExistFile(string path)
{
	return ExistFile(String::ToWString(path));
}

bool Path::ExistFile(wstring path)
{
	DWORD fileValue = GetFileAttributes(path.c_str());
	return fileValue < 0xFFFFFFFF;
}

bool Path::ExistDirectory(string path)
{
	return false;
}

bool Path::ExistDirectory(wstring path)
{
	return false;
}

string Path::Combine(string path1, string path2)
{
	return string();
}

wstring Path::Combine(wstring path1, wstring path2)
{
	return wstring();
}

string Path::GetDirectory(string path)
{
	return string();
}

wstring Path::GetDirectory(wstring path)
{
	return wstring();
}

string Path::GetExtension(string path)
{
	return string();
}

wstring Path::GetExtension(wstring path)
{
	return wstring();
}

string Path::GetFileNameWithoutExtension(string path)
{
	return string();
}

wstring Path::GetFileNameWithoutExtension(wstring path)
{
	return wstring();
}

void Path::OpenFileDialog(wstring file, const WCHAR * filter, wstring folder, function<void(wstring)> func, HWND hwnd)
{
}

void Path::SaveFileDialog(wstring file, const WCHAR * filter, wstring folder, function<void(wstring)> func, HWND hwnd)
{
}

void Path::GetFile(vector<string>* files, string path, string filter, bool bFindSubFolder)
{
}

void Path::GetFile(vector<wstring>* files, wstring path, wstring filter, bool bFindSubFolder)
{
}

void Path::CreateFolder(string path)
{
}

void Path::CreateFolder(wstring path)
{
}

void Path::CreateFolders(string path)
{
}

void Path::CreateFolders(wstring path)
{
}

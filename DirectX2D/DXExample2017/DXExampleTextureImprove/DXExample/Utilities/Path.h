#pragma once

class Path
{
public:
	static bool ExistFile(string path);
	static bool ExistFile(wstring path);

	static bool ExistDirectory(string path);
	static bool ExistDirectory(wstring path);

	static string Combine(string path1, string path2);
	static wstring Combine(wstring path1, wstring path2);

	static string GetDirectory(string path);
	static wstring GetDirectory(wstring path);

	static string GetExtension(string path);
	static wstring GetExtension(wstring path);

	static string GetFileNameWithoutExtension(string path);
	static wstring GetFileNameWithoutExtension(wstring path);
	
	const static WCHAR* ImageFilter;
	const static WCHAR* ShaderFilter;
	const static WCHAR* TextFilter;

	static void OpenFileDialog(wstring file, const WCHAR* filter, wstring folder, function<void(wstring)> func, HWND hwnd = NULL);
	static void SaveFileDialog(wstring file, const WCHAR* filter, wstring folder, function<void(wstring)> func, HWND hwnd = NULL);

	static void GetFile(vector<string>* files,
		string path, string filter, bool bFindSubFolder);
	static void GetFile(vector<wstring>* files,
		wstring path, wstring filter, bool bFindSubFolder);

	static void CreateFolder(string path);
	static void CreateFolder(wstring path);

	static void CreateFolders(string path);
	static void CreateFolders(wstring path);
};
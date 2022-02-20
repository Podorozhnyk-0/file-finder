#include <iostream>
#include <vector>
#include <filesystem>
#include <string>
#include "data.h"

using namespace std;
namespace fs = std::filesystem;

vector<fs::path> FindFileRecursively(const wstring& fileName, const wstring& parentDirectory)
{
	vector<fs::path> results;
	fs::path startPath(parentDirectory + L'\\');

	if (!fs::is_directory(fs::path(parentDirectory)))
	{
		return vector<fs::path>(0);
	}
	for (auto file = fs::recursive_directory_iterator(startPath, fs::directory_options::skip_permission_denied | fs::directory_options::follow_directory_symlink);
		file != fs::recursive_directory_iterator(); file++)
	{
		wstring foundFileName = ToUpperWstring(file->path().filename().wstring());
		if (foundFileName.find(ToUpperWstring(fileName)) != wstring::npos)
		{
			results.push_back(file->path());
		}
	}

	return results;
}

vector<wstring> FirstDiskChoise(wchar_t firstDiskToSearch)
{
	vector<wstring> searchVector;
	searchVector.push_back(wstring(1, firstDiskToSearch) + L":");
	for (wchar_t wi = L'A'; wi <= 'Z'; wi++)
	{
		if (wi == firstDiskToSearch) continue;
		searchVector.push_back(wstring(1, wi) + L":"); //добавляем диск в вектор, если он соответствует требованиям (только буквы латиницы)
	}
	return searchVector;
}

bool CheckWrongCharacters(wstring wString)
{
	bool bResult = false;
	for (const auto& wi : wString)
	{
		if (wi == L' ') { continue; }
		else { bResult = true; } //если строка содержит только пробелы
	}
	return bResult;
}

wstring ToUpperWstring(const wstring& wString)
{
	wstring newString = wString;
	for (size_t wi = 0; wi < wString.length(); wi++)
	{
		newString[wi] = towupper(wString[wi]);
	}
	return newString;
}



#pragma once
#include <iostream>
#include <vector>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

vector<fs::path> FindFileRecursively(const wstring& fileName, const wstring& parentDirectory);
vector<wstring> FirstDiskChoise(wchar_t firstDiskToSearch = L'A');
bool CheckWrongCharacters(wstring wString);
wstring ToUpperWstring(const wstring& wString);
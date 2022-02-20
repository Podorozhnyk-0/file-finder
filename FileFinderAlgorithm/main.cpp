#include <iostream>
#include <filesystem>
#include <string>
#include "data.h"
namespace fs = std::filesystem;
using namespace std;

int main()
{
	_wsetlocale(LC_ALL, L"Russian"); //локаль
	wstring firstDisk, fileName;
	wcout << L"\033[38;5;50m" << L"File Search Algorithm | by Zero " << L"\033[0m" << endl << endl;
	wcout << L"\033[38;5;50m" << L"Enter first disk to start: " << L"\033[0m" << endl;
	wcout << L">> ";
	getline(wcin, firstDisk);
	wcout << L"\033[38;5;50m" << L"Enter file name: " << L"\033[0m" << endl;
	wcout << L">> ";
	getline(wcin, fileName);

	vector<wstring> disksList = FirstDiskChoise(firstDisk[0]); //выбираем диск, с которого хотим начать
	for (auto& disk : disksList)
	{
		if (exists(fs::path(disk)))
		{
			wcout << L"\033[38;5;150m" << L"Searching on " << disk << L"\033[0m" << endl;
			vector<fs::path> results = FindFileRecursively(fileName, disk); //ищем
			for(auto& file : results)
			{
				wcout << file << endl;
			}
		}
	}
	return 0;
}


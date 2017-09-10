#pragma once

#include <vector>
#include <iostream>
#include <fstream>

#define _WIN32_WINNT 0x0400
#include <windows.h>
#include <atlstr.h>

#include <fstream>
#include <cassert>
#include "picojson.h"
#include <Windows.h>


using namespace std;

class MusicManager
{
public:
	MusicManager();
	~MusicManager();

	typedef struct Item {
		string music_name;
		string artist;
		int level[3];
		int easy_color[7];
		int normal_color[7];
		int hard_color[7];
		float preview[2];
	};

	void DataLoding();

	const Item& getItem(int i);
	const int getItemNumber();
	const string& getFolderList(int i);

private:
	static vector<string> m_folder_list;//フォルダ名リスト（曲名）
	static vector<Item> item;//曲データ
};


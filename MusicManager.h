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

//楽曲の基本データを管理
//データはjson形式のファイルを読み込み(picojson使用)
//フォルダ名の読み込みは変更の余地有
class MusicManager
{
public:
	MusicManager();
	~MusicManager();

	//1曲分のデータ構造体
	typedef struct Item {
		string music_name;//曲名
		string artist;//アーティスト
		int level[3];//レベル
		int easy_color[7];//以下3行はプレイで使用する色の種類
		int normal_color[7];
		int hard_color[7];
		float preview[2];//曲試聴の際の開始と終了オフセット
	};

	void DataLoding();

	const Item& getItem(int i);//曲データ
	const int getItemNumber();//曲数
	const string& getFolderList(int i);//フォルダ名の一覧

private:
	static vector<string> m_folder_list;//フォルダ名リスト（曲名）
	static vector<Item> item;//曲データ
};


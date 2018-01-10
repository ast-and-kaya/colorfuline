#pragma once
#include "picojson.h"
#include "MusicManager.h"

using namespace std;

//ハイスコアデータの管理・読み書き等
//まだ未実装
class ScoreManager
{
public:
	ScoreManager();
	~ScoreManager();

	struct Data
	{//easy:normal:hard
		int score[3];
		int combo[3];
		int perfect[3];
		int count;
	};

	void DataLoad();
	int DataSave(int new_score,int music,int diff);
	Data getData(int num,int diff);

private:
	MusicManager musicManager;

	static vector<Data> m_data_array;

};


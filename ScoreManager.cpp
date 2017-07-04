#include "ScoreManager.h"

vector<ScoreManager::Data> ScoreManager::m_data_array;

ScoreManager::ScoreManager()
{
}

ScoreManager::~ScoreManager()
{
}

void ScoreManager::DataLoad()
{
	for (int i = 0; i < musicManager.getItemNumber(); i++)
	{
		string folder_name = musicManager.getFolderList(i);

		//ファイル読み込み
		ifstream fs;
		fs.open("data/music/" + folder_name + "/scoreData.json", std::ios::binary);
		assert(fs);
		picojson::value val;
		fs >> val;
		fs.close();

		//構造体収納
		Data s;
		//easy
		s.score[0] = val.get("_easy").get("score").get<double>();
		s.combo[0] = val.get("_easy").get("combo").get<double>();
		s.perfect[0] = val.get("_easy").get("perfect").get<double>();
		//normal
		s.score[1] = val.get("_normal").get("score").get<double>();
		s.combo[1] = val.get("_normal").get("combo").get<double>();
		s.perfect[1] = val.get("_normal").get("perfect").get<double>();
		//hard
		s.score[2] = val.get("_hard").get("score").get<double>();
		s.combo[2] = val.get("_hard").get("combo").get<double>();
		s.perfect[2] = val.get("_hard").get("perfect").get<double>();
		//play_count
		s.count = val.get("play_count").get<double>();

		m_data_array.push_back(s);
	}

}

int ScoreManager::DataSave(int new_score,int music,int diff) {
	if (new_score <= m_data_array[music].score[diff])
	{
		return 0;
	}
	else
	{
		//
		//ここにデータ書き込み処理
		//

		int difference = new_score - m_data_array[music].score[diff];
		return difference;
	}

}

ScoreManager::Data ScoreManager::getData(int num, int diff)
{
	return m_data_array[diff];
}
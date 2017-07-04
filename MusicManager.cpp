#include "MusicManager.h"

vector<string> MusicManager::m_folder_list;
vector<MusicManager::Item> MusicManager::item;

MusicManager::MusicManager()
{
}


MusicManager::~MusicManager()
{
}

void MusicManager::DataLoding() {
	//フォルダ名を取得
	WIN32_FIND_DATA find_dir_data;
	HANDLE hFind = FindFirstFile("data/music\\*", &find_dir_data);

	do {
		if (hFind != INVALID_HANDLE_VALUE) {
			if (strcmp(find_dir_data.cFileName, ".") && strcmp(find_dir_data.cFileName, "..")) {
				if (find_dir_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
					m_folder_list.push_back(find_dir_data.cFileName);
				}
			}
		}
	} while (FindNextFile(hFind, &find_dir_data));

	//data.json読み込み
	for (int i = 0; i < m_folder_list.size(); i++)
	{
		ifstream fs;
		fs.open("data/music/"+ m_folder_list[i] +"/data.json", std::ios::binary);
		assert(fs);
		picojson::value val;
		fs >> val;
		fs.close();

		Item s_item;
		//曲名
		s_item.music_name = val.get("music_name").get<string>();
		//アーティスト
		s_item.artist = val.get("artist").get<string>();
		//難易度
		s_item.level[0] = val.get("easy").get("level").get<double>();
		s_item.level[1] = val.get("normal").get("level").get<double>();
		s_item.level[2] = val.get("hard").get("level").get<double>();
		//使用色
		for (int i = 0; i < 7; i++) {
			s_item.easy_color[i] = val.get("easy").get("diff").get(i).get<double>();
			s_item.normal_color[i] = val.get("normal").get("diff").get(i).get<double>();
			s_item.hard_color[i] = val.get("hard").get("diff").get(i).get<double>();
		}
		
		item.push_back(s_item);
	}
}

const MusicManager::Item& MusicManager::getItem(int i) {
	return item[i];
}

const int MusicManager::getItemNumber() {
	return m_folder_list.size();
}

const string& MusicManager::getFolderList(int i) {
	return m_folder_list[i];
}
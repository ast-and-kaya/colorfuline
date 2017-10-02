#pragma once
#include "SFML\Graphics.hpp"
#include "ConfigManager.h"
#include "MusicManager.h"
#include <iostream>
#include <vector>

#include "picojson.h"

using namespace std;

class MusicScore
{
public:
	MusicScore();
	~MusicScore();

	struct Data
	{
		float time;
		sf::Color color;
	};

	void Loading();
	Data getData(int num);
	int getSize();

private:
	MusicManager musicManager;
	ConfigManager config;

	vector<Data> m_data;
	string m_path;

};


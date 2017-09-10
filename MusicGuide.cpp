#include "MusicGuide.h"

map<string, sf::Text> MusicGuide::m_guide_text;
sf::Sprite MusicGuide::m_use_color[7];

MusicGuide::MusicGuide()
{
}


MusicGuide::~MusicGuide()
{
}

void MusicGuide::initialize(sf::Vector2f pos)
{
	m_font.loadFromFile("data/font/851tegaki.ttf");

	m_guide_text.insert(map<string, sf::Text>::value_type("title", sf::Text()));
	m_guide_text["title"].setFont(m_font);
	m_guide_text["title"].setString(cv.from_bytes(musicManager.getItem(config.getNowMusic(config.Num)).music_name));
	m_guide_text["title"].setPosition(pos + sf::Vector2f(50,0));
	m_guide_text["title"].setCharacterSize(75);
	m_guide_text["title"].setColor(sf::Color(255, 255, 255, 255));

	m_guide_text.insert(map<string, sf::Text>::value_type("artist", sf::Text()));
	m_guide_text["artist"].setFont(m_font);
	m_guide_text["artist"].setString(cv.from_bytes(musicManager.getItem(config.getNowMusic(config.Num)).artist));
	m_guide_text["artist"].setPosition(pos + sf::Vector2f(50, 100));
	m_guide_text["artist"].setCharacterSize(60);
	m_guide_text["artist"].setColor(sf::Color(255, 255, 255, 255));

	m_guide_text.insert(map<string, sf::Text>::value_type("level", sf::Text()));
	m_guide_text["level"].setFont(m_font);
	m_guide_text["level"].setString(cv.from_bytes("Lv." + to_string(musicManager.getItem(config.getNowMusic(config.Num)).level[config.getNowMusic(config.Diff)])));
	m_guide_text["level"].setPosition(pos + sf::Vector2f(50, 180));
	m_guide_text["level"].setCharacterSize(85);
	m_guide_text["level"].setColor(sf::Color(255, 255, 255, 255));


	sf::Color c[7] = {
		sf::Color::Red,sf::Color::Green,sf::Color::Blue,
		sf::Color::Cyan,sf::Color::Magenta,sf::Color::Yellow,
		sf::Color::White
	};
	for (int i = 0; i < 7; i++)
	{
		m_use_color[i].setTexture(tex.get("select_use_color"));
		m_use_color[i].setColor(c[i]);
		m_use_color[i].setPosition(sf::Vector2f(0, 300) + sf::Vector2f( 0, 60 * i));
	}
	setColorBar(musicManager.getItem(config.getNowMusic(config.Num)).easy_color);
}

void MusicGuide::update()
{
	m_guide_text["title"].setString(cv.from_bytes(musicManager.getItem(config.getNowMusic(config.Num)).music_name));
	m_guide_text["artist"].setString(cv.from_bytes(musicManager.getItem(config.getNowMusic(config.Num)).artist));
	m_guide_text["level"].setString(cv.from_bytes("Lv." + to_string(musicManager.getItem(config.getNowMusic(config.Num)).level[config.getNowMusic(config.Diff)])));

	if (config.getNowMusic(config.Diff) == 0) setColorBar(musicManager.getItem(config.getNowMusic(config.Num)).easy_color);
	if (config.getNowMusic(config.Diff) == 1) setColorBar(musicManager.getItem(config.getNowMusic(config.Num)).normal_color);
	if (config.getNowMusic(config.Diff) == 2) setColorBar(musicManager.getItem(config.getNowMusic(config.Num)).hard_color);
}

void MusicGuide::render()
{
	windowManager.getWindow()->draw(m_guide_text["title"]);
	windowManager.getWindow()->draw(m_guide_text["artist"]);
	windowManager.getWindow()->draw(m_guide_text["level"]);

	for (int i = 0; i < 7; i++)
	{
		windowManager.getWindow()->draw(m_use_color[i]);
	}
}

void MusicGuide::setColorBar(const int* a) {
	for (int i = 0; i < 7; i++)
	{
		m_use_color[i].setColor(sf::Color(
			m_use_color[i].getColor().r,
			m_use_color[i].getColor().g,
			m_use_color[i].getColor().b,
			a[i] * 255
		));
	}
}
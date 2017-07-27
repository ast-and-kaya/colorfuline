#include "ResultScene.h"

int ResultScene::m_result_score;
int ResultScene::m_result_combo;
int ResultScene::m_result_perfect;

int ResultScene::m_result_note_number;

ResultScene::ResultScene()
{
}


ResultScene::~ResultScene()
{
}


void ResultScene::initialize()
{
	//スコア等の文字
	//フォント
	characterDisplay.setFont("Dosis", "data/font/Dosis-Light.ttf");
	characterDisplay.setFont("tegaki", "data/font/851tegaki.ttf");
	//文字
	//タイトル
	characterDisplay.setCharacter("title", "tegaki", musicManager.getItem(config.getNowMusic(config.Num)).music_name, sf::Vector2f(1050, 0), 75);//曲名
	characterDisplay.setCharacter("artist", "tegaki", musicManager.getItem(config.getNowMusic(config.Num)).artist, sf::Vector2f(1400, 100), 60);//アーティスト
	//スコア
	characterDisplay.setCharacter("Iscore", "Dosis", "score", sf::Vector2f(50, 200), 100);
	characterDisplay.setCharacter("Sscore", "Dosis", to_string(m_result_score), sf::Vector2f(50, 300), 100);
	//コンボ
	characterDisplay.setCharacter("Icombo", "Dosis", "combo", sf::Vector2f(50, 400), 100);
	characterDisplay.setCharacter("Scombo", "Dosis", to_string(m_result_combo), sf::Vector2f(50, 500), 100);
	//パーフェクト
	characterDisplay.setCharacter("Iperfect", "Dosis", "perfect", sf::Vector2f(50, 600), 100);
	characterDisplay.setCharacter("Sperfect", "Dosis", to_string(m_result_perfect), sf::Vector2f(50, 700), 100);
	//メニュー
	characterDisplay.setCharacter("retry", "Dosis", "Retry", sf::Vector2f(1200, 900), 100);
	characterDisplay.setCharacter("next", "Dosis", "Next", sf::Vector2f(1500, 900), 100);

}

Scene* ResultScene::update()
{
	Scene* next = this;

	if (keyManager.push_key(sf::Keyboard::Return))
	{
		next = new SelectScene;
	}

	return next;
}

void ResultScene::render()
{
	characterDisplay.render("title");
	characterDisplay.render("artist");
}


void ResultScene::setScereData(int score, int combo, int perfect, int note) {
	m_result_score = score;
	m_result_combo = combo;
	m_result_perfect = perfect;
	m_result_note_number = note;
}
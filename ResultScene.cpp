#include "ResultScene.h"

int ResultScene::m_result_score;
int ResultScene::m_result_combo;
int ResultScene::m_result_perfect;

ResultScene::ResultScene()
{
}


ResultScene::~ResultScene()
{
}


void ResultScene::initialize()
{
	cout << musicManager.getItem(config.getNowMusic(config.Num)).music_name << endl;
	cout << m_result_score << endl;
	cout << m_result_combo << endl;
	cout << m_result_perfect << endl;
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
}


void ResultScene::setScereData(int score, int combo, int perfect) {
	m_result_score = score;
	m_result_combo = combo;
	m_result_perfect = perfect;
}
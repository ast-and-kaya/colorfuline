#include "ScoreCalc.h"



ScoreCalc::ScoreCalc()
{
}


ScoreCalc::~ScoreCalc()
{
}

void ScoreCalc::setMaxScore(int combo, int great_score)
{
	for (int i = 1; i <= combo; i++)
	{
		m_max_score += great_score * (1 + i * 0.001);
	}

	m_score = 0;
}

float ScoreCalc::getMaxScore()
{
	return m_max_score;
}

void ScoreCalc::add(int combo, int raw_score)
{
	m_score += raw_score * (1 + combo * 0.001);
}

float ScoreCalc::getScore()
{
	//cout << m_score << ":" << m_max_score << endl;
	return m_score / m_max_score * 100.f;
}

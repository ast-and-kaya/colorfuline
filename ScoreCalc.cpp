#include "ScoreCalc.h"



ScoreCalc::ScoreCalc()
{
}


ScoreCalc::~ScoreCalc()
{
}

void ScoreCalc::setMaxScore(int combo, int great_score)
{
	for (int i = 0; i < combo; i++)
	{
		m_max_score += great_score * (1 + i * 0.001);
	}
}

float ScoreCalc::getMaxScore()
{
	return m_max_score;
}

float ScoreCalc::add(int combo, int raw_score)
{
	return raw_score * (1 + combo * 0.001);
}

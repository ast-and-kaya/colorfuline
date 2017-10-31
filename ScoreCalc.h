#pragma once
#include <iostream>

using namespace std;

class ScoreCalc
{
public:
	ScoreCalc();
	~ScoreCalc();

	void setMaxScore(int combo, int great_score);
	float getMaxScore();

	void add(int combo, int raw_score);

	float getScore();

private:
	float m_max_score;
	float m_score;
};


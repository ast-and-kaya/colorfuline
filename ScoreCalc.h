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

	float add(int combo, int raw_score);

private:
	int m_max_score;
};


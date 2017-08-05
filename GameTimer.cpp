#include "GameTimer.h"



GameTimer::GameTimer()
{
}


GameTimer::~GameTimer()
{
}

void GameTimer::initialize(float set)
{

	m_time = 0;

	m_now_time = 0;
	m_bf_time = 0;

	m_stopped = false;
}

void GameTimer::update()
{
	m_bf_time = m_now_time;
	m_now_time = timeGetTime();

	if (!m_stopped) {
		 m_time += ((m_now_time - m_bf_time)%1000)/1000.f;
	}

	//cout << m_time << endl;
}

float GameTimer::getTime()
{
	return m_time;
}

bool GameTimer::getState()
{
	return m_stopped;
}

void GameTimer::start()
{
	m_stopped = false;
}

void GameTimer::pouse()
{
	m_stopped = true;
}

void GameTimer::reset()
{
	m_time = 0;
}

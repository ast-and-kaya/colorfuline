#include "GameTimer.h"



GameTimer::GameTimer()
{
}


GameTimer::~GameTimer()
{
}

void GameTimer::initialize()
{

	m_time = 0;

	m_first_time = timeGetTime();

	m_stop_be = 0;

	m_stopped = false;
}

void GameTimer::update()
{
	m_time = (timeGetTime() - m_first_time) / 1000.f;

	cout << (m_stopped ? m_stop_be : m_time + m_stop_be) << endl;
}

float GameTimer::getTime()
{
	return m_stopped ? m_stop_be : m_time + m_stop_be;
}

bool GameTimer::getState()
{
	return m_stopped;
}

void GameTimer::start()
{
	m_stopped = false;
	m_first_time = timeGetTime();
}

void GameTimer::pouse()
{
	m_stop_be += m_time;
	m_stopped = true;
}

void GameTimer::reset()
{
	m_first_time = timeGetTime();
	m_stop_be = 0;
}

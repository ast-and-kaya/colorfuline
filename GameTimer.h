#pragma once
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment (lib, "winmm.lib")

using namespace std;

class GameTimer
{
public:
	GameTimer();
	~GameTimer();

	void initialize();
	void update();

	float getTime();
	bool getState();

	void start();
	void pouse();
	void reset();

private:
	float m_time;

	int m_first_time;

	float m_stop_be;

	bool m_stopped;
};


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

	void initialize(float set = 0);
	void update();

	float getTime();
	bool getState();

	void start();
	void pouse();
	void reset();

private:
	float m_time;

	int m_now_time;
	int m_bf_time;

	bool m_stopped;
};


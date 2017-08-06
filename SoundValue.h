#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <numeric>

#include <windows.h>
#pragma comment(lib, "winmm.lib")

using namespace std;

class SoundValue
{
public:
	SoundValue();
	~SoundValue();

	void setFilePass(string pass);
	int getValue(float timing,int rl); //ñﬂÇËílÇÕ0Å`256^2
private:

	vector<unsigned char> buff;

	float ms_data;

	vector<int> store_r;
	int sound_value_r;

	vector<int> store_l;
	int sound_value_l;
};


#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <complex>
#include <valarray>
#include <math.h>

#include <stdio.h>
#include <windows.h>

#include "WindowManager.h"

const double PI = 3.141592653589793238460 ;

using namespace std ;

typedef complex<double> Complex;
typedef valarray<Complex> CArray;

class FFT
{
public:
	FFT();
	~FFT();

	void init(string const& _path);

	void fft(CArray &x) ;
	void update(float is_time = 0);

	vector<int> getData();
	bool getLoadEnd();

	static void load();
	static sf::SoundBuffer buffer ;
	static string m_path;

private:
	WindowManager windowManger;

	vector<Complex> sample ;
	vector<float> window ;
	CArray bin ;
	
	int bufferSize ;
	int mark ;

	vector<int> data;

	static bool m_load_end;
};


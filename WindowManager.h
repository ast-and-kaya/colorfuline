#pragma once

#include <SFML/Graphics.hpp>

//SFML�ō����E�B���h�E��ێ�����
//���łɃA�N�e�B�u���ǂ���������
//���ɂ��ǉ��L��(�H)
class WindowManager
{
public:
	WindowManager();
	~WindowManager();

	static sf::RenderWindow* m_window;//�{��
	static bool m_window_active;//�A�N�e�B�u���ʗp

	void setWindow(sf::RenderWindow* window);
	sf::RenderWindow* getWindow();

	void setWindowActive(bool a);
	bool getWindowActive();

private:
};
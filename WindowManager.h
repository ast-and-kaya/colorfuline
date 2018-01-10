#pragma once

#include <SFML/Graphics.hpp>

//SFMLで作られるウィンドウを保持する
//ついでにアクティブがどうかも判別
//他にも追加有り(？)
class WindowManager
{
public:
	WindowManager();
	~WindowManager();

	static sf::RenderWindow* m_window;//本体
	static bool m_window_active;//アクティブ判別用

	void setWindow(sf::RenderWindow* window);
	sf::RenderWindow* getWindow();

	void setWindowActive(bool a);
	bool getWindowActive();

private:
};
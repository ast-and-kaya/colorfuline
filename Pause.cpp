#include "Pause.h"
#include "SelectScene.h"
#include "GameScene.h"

Pause::Pause()
{
}


Pause::~Pause()
{
}

void Pause::initialize()
{
	m_select_cursor = 0;

	//�w�i
	m_bg.setTexture(tex.get("black"));
	m_bg.setColor(sf::Color(255, 0, 0, 100));

	//����
	const string MenuString[3] = { "resume", "replay", "back"};
	const sf::Vector2f TextPostion(0,0);

	m_font.loadFromFile("data/font/Dosis-Light.ttf");
	for (int i = 0; i < 3; i++)
	{
		m_menu[i].setFont(m_font);
		m_menu[i].setColor(sf::Color::White);
		m_menu[i].setString(MenuString[i]);
		m_menu[i].setCharacterSize(130);
		m_menu[i].setPosition(sf::Vector2f(0,i*180) + TextPostion);
	}
}

int Pause::update(Scene*& n)
{
	//�J�[�\��
	if (keyManager.push_key(sf::Keyboard::Up)) m_select_cursor -= (m_select_cursor > 0) ? 1 : 0;
	if (keyManager.push_key(sf::Keyboard::Down)) m_select_cursor += (m_select_cursor < 2) ? 1 : 0;

	for (int i = 0; i < 3; i++) m_menu[i].setCharacterSize(130);
	m_menu[m_select_cursor].setCharacterSize(150);

	//cout << m_select_cursor << endl;

	//�I��
	if (keyManager.push_key(sf::Keyboard::Return))
	{
		switch (m_select_cursor)
		{
		case 0: //�ĊJ
			return 1;
			break;
		case 1: //���g���C
			n = new GameScene;
			break;
		case 2: //�Z���N�g
			n = new SelectScene;
			break;
		}
	}

	return 3;
}

void Pause::render()
{
	windowManager.getWindow()->draw(m_bg);
	for (int i = 0; i < 3; i++)
	{
		windowManager.getWindow()->draw(m_menu[i]);
	}
}

#include "TestRoom.h"


TestRoom::TestRoom()
{
}


TestRoom::~TestRoom()
{
}

void TestRoom::initialize()
{
	//îwåi
	m_tex.loadFromFile("data/image/test.png");
	m_tex.setSmooth(true);
	m_bg.setTexture(m_tex);

	decEffect.initialize();
}


Scene* TestRoom::update()
{

	Scene* next = this;
	sf::Clock c;
	//---------------------------------------------------

	if (keyManager.push_key(sf::Keyboard::Return))
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		decEffect.setJudge(0);
	}

	decEffect.update();

	//---------------------------------------------------
	//cout << c.getElapsedTime().asSeconds() << endl;
	return next;
}

void TestRoom::render()
{
	windowManager.getWindow()->draw(m_bg);
	decEffect.render();
}




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
	m_tex.loadFromFile("data/image/test0.png");
	m_tex.setSmooth(true);
	m_bg.setTexture(m_tex);

	m_shad.loadFromFile("data/shader/blur.frag",sf::Shader::Fragment);
	m_state.shader = &m_shad;
}


Scene* TestRoom::update()
{

	Scene* next = this;
	sf::Clock c;
	//---------------------------------------------------

	static float a = 10.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) a++;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) a--;

	m_shad.setParameter("r", abs(a));


	//---------------------------------------------------
	cout << c.getElapsedTime().asSeconds() << endl;
	return next;
}

void TestRoom::render()
{
	windowManager.getWindow()->draw(m_bg, m_state);
}




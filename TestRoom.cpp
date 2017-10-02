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
	
	m_shad.loadFromFile("data/shader/blur.frag",sf::Shader::Fragment);
	m_state.shader = &m_shad;

	hitEffect.initialize();


	for (int i = 0; i < 87; i++)
	{
		cout << rand() % 3 + 1 << endl;
	}
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

	if (keyManager.push_key(sf::Keyboard::Return)) hitEffect.action();
	hitEffect.update();
	//---------------------------------------------------
	//cout << c.getElapsedTime().asSeconds() << endl;
	return next;
}

void TestRoom::render()
{
	windowManager.getWindow()->draw(m_bg);
	hitEffect.render();
}




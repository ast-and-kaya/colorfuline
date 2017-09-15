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
	m_tex.loadFromFile("data/image/a.png");
	m_tex.setSmooth(true);
	m_bg.setTexture(m_tex);
	m_shad.loadFromFile("data/shader/blur.frag", sf::Shader::Fragment);
	m_shad.setParameter("texture", m_tex);
	m_shad.setParameter("r", 1.0f / 512.0f);
	m_state.shader = &m_shad;
}


Scene* TestRoom::update()
{
	Scene* next = this;
	static sf::Clock c;
	//---------------------------------------------------

	m_shad.loadFromFile("data/shader/blur.frag", sf::Shader::Fragment);

	//---------------------------------------------------
	//cout << c.getElapsedTime().asSeconds() << endl;
	return next;
}

void TestRoom::render()
{
	windowManager.getWindow()->draw(m_bg, m_state);
}




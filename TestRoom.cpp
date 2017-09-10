#include "TestRoom.h"

TestRoom::TestRoom()
{
}


TestRoom::~TestRoom()
{
}

void TestRoom::initialize()
{
	s.setTexture(tex.get("black"));

	m_shad.loadFromFile("data/shader/result_bg.frag", sf::Shader::Fragment);
	m_shad.setParameter("r", sf::Vector2f(windowManager.getWindow()->getSize().x, windowManager.getWindow()->getSize().y));
	m_state.shader = &m_shad;
}


Scene* TestRoom::update()
{
	Scene* next = this;

	sf::Clock c;

	m_shad.loadFromFile("data/shader/result_bg.frag", sf::Shader::Fragment);
	m_shad.setParameter("r", sf::Vector2f(windowManager.getWindow()->getSize().x, windowManager.getWindow()->getSize().y));
	m_state.shader = &m_shad;

	cout << c.getElapsedTime().asSeconds() << endl;

	return next;
}

void TestRoom::render()
{
	windowManager.getWindow()->draw( s, m_state);
}




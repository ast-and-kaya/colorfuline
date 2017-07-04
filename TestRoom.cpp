#include "TestRoom.h"

TestRoom::TestRoom()
{
}


TestRoom::~TestRoom()
{
}

void TestRoom::initialize()
{
	t.loadFromFile("data/image/a.png");
	s.setTexture(t);
	s.setPosition(100,100);
}


Scene* TestRoom::update()
{
	Scene* next = this;


	return next;
}

void TestRoom::render()
{
	windowManager.getWindow()->draw(s);
}




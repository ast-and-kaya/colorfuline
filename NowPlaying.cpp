#include "NowPlaying.h"


NowPlaying::NowPlaying()
{
}


NowPlaying::~NowPlaying()
{
}

void NowPlaying::initialize(sf::Vector2f pos, float size, sf::Color color)
{
	sprite2.setTexture(tex.get("select_loading0"));
	sprite2.setOrigin(tex.get("select_loading0").getSize().x / 2.0, tex.get("select_loading0").getSize().y / 2.0);
	sprite2.setPosition(pos);
	sprite2.setScale(size, size);
	sprite2.setColor(color);

	for (int i = 0; i < 5; i++)
	{
		sprite[i].setTexture(tex.get("select_loading1"));
		sprite[i].setOrigin(tex.get("select_loading1").getSize().x / 2.0, tex.get("select_loading1").getSize().y / 2.0);
		sprite[i].setPosition(pos);
		sprite[i].setScale(size, size);
		sprite[i].setColor(color);
	}
}

void NowPlaying::update(float speed)
{
	for (int i = 0; i < 5; i++)
	{
		sprite[i].setRotation(sprite[i].getRotation() + (i+1)*speed);
	}
}

void NowPlaying::render()
{
	for (int i = 0; i < 5; i++) windowManager.getWindow()->draw(sprite[i]);
	windowManager.getWindow()->draw(sprite2);
}

void NowPlaying::reset()
{
	for (int i = 0; i < 5; i++)
	{
		sprite[i].setRotation(0);
	}
}

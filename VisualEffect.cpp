#include "VisualEffect.h"



VisualEffect::VisualEffect()
{
}


VisualEffect::~VisualEffect()
{
}

void VisualEffect::initialize(string path)
{
	//fft
	fft.init(path);
	VA2.setPrimitiveType(sf::Lines);

	//value
	soundValue.setFilePass(path);
	m_sprite.setTexture(tex.get("black"));

	shader.loadFromFile("data/shader/game_ring.frag", sf::Shader::Fragment);
	shader.setParameter("r", sf::Vector2f(config.m_window_size.x, config.m_window_size.y));
	state.shader = &shader;
}

void VisualEffect::updata(float time)
{
	time = (time < 0) ? 0 : time;

	//fft
	fft.update(time);

	data = fft.getData();

	VA2.clear();
	sf::Vector2f position(0, 470);
	for (int i = 0; i < data.size(); i++)
	{
		VA2.append(sf::Vertex(position + sf::Vector2f(i * 10, -data[i] / 150000), sf::Color(255,255,255,0)));
		VA2.append(sf::Vertex(position + sf::Vector2f(i * 10, 0), sf::Color::White));
		VA2.append(sf::Vertex(position + sf::Vector2f(i * 10, 0), sf::Color::White));
		VA2.append(sf::Vertex(position + sf::Vector2f(i * 10, data[i] / 150000), sf::Color(255, 255, 255, 0)));
	}

	//value
	sf::Vector2f value(soundValue.getValue(time, 0), soundValue.getValue(time, 1));
	shader.setParameter("v", sf::Vector2f(value.x / 32768.f, value.y / 32768.f));
}

void VisualEffect::render()
{
	windowManager.getWindow()->draw(m_sprite, state);
	windowManager.getWindow()->draw(VA2);
}

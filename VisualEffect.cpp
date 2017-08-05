#include "VisualEffect.h"



VisualEffect::VisualEffect()
{
}


VisualEffect::~VisualEffect()
{
}

void VisualEffect::initialize(string path)
{
	fft.init(path);

	VA2.setPrimitiveType(sf::Lines);
}

void VisualEffect::updata(float time)
{
	time = (time < 0) ? 0 : time;
	fft.update(time);

	data = fft.getData();

	VA2.clear();
	sf::Vector2f position(0, 470);
	for (int i = 0; i < data.size(); i++)
	{
		VA2.append(sf::Vertex(position + sf::Vector2f(i * 10, -data[i] / 150000), sf::Color::Black));
		VA2.append(sf::Vertex(position + sf::Vector2f(i * 10, 0), sf::Color::White));
		VA2.append(sf::Vertex(position + sf::Vector2f(i * 10, 0), sf::Color::White));
		VA2.append(sf::Vertex(position + sf::Vector2f(i * 10, data[i] / 150000), sf::Color::Black));
	}
}

void VisualEffect::render()
{
	windowManager.getWindow()->draw(VA2);
}

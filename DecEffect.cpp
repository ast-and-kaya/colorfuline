#include "DecEffect.h"



DecEffect::DecEffect()
{
}


DecEffect::~DecEffect()
{
}

void DecEffect::initialize()
{
}

void DecEffect::update()
{
	cout << m_ring.size() << endl;

	int c = 0;
	for (auto &it : m_ring)
	{
		it.s_scale += (it.s_scale <= 1.f) ? 0.05 : 0;
		it.s_sprite.setScale(it.s_scale, it.s_scale);
		it.s_alpha = 255 - (it.s_scale * 255);
		it.s_sprite.setColor(sf::Color(255, 255, 255, it.s_alpha));
	}

	if (!m_ring.empty())
	{
		if (m_ring[0].s_alpha <= 0) m_ring.erase(m_ring.begin());
	}
}

void DecEffect::render()
{
	for (auto &it:m_ring)
	{
		windowManager.getWindow()->draw(it.s_sprite);
	}
}

void DecEffect::setJudge(int j)
{
	Ring r;
	r.s_sprite.setTexture(tex.get("game_judge_ring"));
	r.s_sprite.setOrigin(tex.get("game_judge_ring").getSize().x/2, tex.get("game_judge_ring").getSize().y/2);
	r.s_sprite.setPosition(randPos());
	r.s_sprite.setScale(0, 0);
	r.s_scale = 0;
	r.s_alpha = 255;
	m_ring.push_back(r);

	//-----------------------------------
	switch (j)
	{
	case 1: cout << "great" << endl;
		break;
	case 2: cout << "good" << endl;
		break;
	case 3: cout << "bad" << endl;
		break;
	}
}

sf::Vector2f DecEffect::randPos()
{
	sf::Vector2f vec;

	vec.x = 250 + rand() % (1920 - 500);
	vec.y = 250 + rand() % (1080 - 500);

	return vec;
}

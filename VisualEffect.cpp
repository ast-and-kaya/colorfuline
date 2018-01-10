#include "VisualEffect.h"



VisualEffect::VisualEffect()
{
}


VisualEffect::~VisualEffect()
{
}

void VisualEffect::initialize()
{
	//fft
	fft.init("data/music/" + musicManager.getFolderList(config.getNowMusic(config.Num)) + "/music.ogg");
	m_va.setPrimitiveType(sf::Lines);

	//value
	m_sprite.setTexture(tex.get("black"));

	shader.loadFromFile("data/shader/game_ring.frag", sf::Shader::Fragment);
	shader.setParameter("r", sf::Vector2f(config.m_window_size.x, config.m_window_size.y));
	state.shader = &shader;
}

void VisualEffect::updata(float time)
{
	time = (time < 0) ? 0 : time;

	m_sound_value = 0;

	//キー入力時のカラー
	m_sub_color[0] = (keyJudge.getKeyColor().r != 0) ? 255 : m_sub_color[0];
	m_sub_color[1] = (keyJudge.getKeyColor().g != 0) ? 255 : m_sub_color[1];
	m_sub_color[2] = (keyJudge.getKeyColor().b != 0) ? 255 : m_sub_color[2];

	//fft
	fft.update(time);

	data = fft.getData();

	m_va.clear();
	sf::Vector2f position(0, 470);
	for (int i = 0; i < data.size(); i++)
	{
		m_va.append(sf::Vertex(position + sf::Vector2f(i * 10, -data[i] / 150000), sf::Color(m_sub_color[0],m_sub_color[1],m_sub_color[2],0)));
		m_va.append(sf::Vertex(position + sf::Vector2f(i * 10, 0), sf::Color::White));
		m_va.append(sf::Vertex(position + sf::Vector2f(i * 10, 0), sf::Color::White));
		m_va.append(sf::Vertex(position + sf::Vector2f(i * 10, data[i] / 150000), sf::Color(m_sub_color[0], m_sub_color[1], m_sub_color[2], 0)));

		m_sound_value += data[i] / (data.size() - i);
	}

	//cout << m_sound_value << endl;

	//value
	float a = m_sound_value / 20000000.f;
	shader.setParameter("v", sf::Vector2f(a, a));

	//下部フォグ
	for (int i = 0; i < 3; i++)
	{
		m_sub_color[i] -= (m_sub_color[i] > 0) ? 10 : 0;
		m_sub_color[i] = (m_sub_color[i] < 0) ? 0 : m_sub_color[i];
	}

	int alpha = 0;
	for (int i = 0; i < 3; i++)
	{
		alpha = (alpha < m_sub_color[i]) ? m_sub_color[i] : alpha;
	}
	m_sprite.setColor(sf::Color(m_sub_color[0], m_sub_color[1], m_sub_color[2], 255));
}

void VisualEffect::render()
{
	windowManager.getWindow()->draw(m_sprite, state);
	//windowManager.getWindow()->draw(m_sprite);
	windowManager.getWindow()->draw(m_va);
}

void VisualEffect::setColor(sf::Color c)
{
}

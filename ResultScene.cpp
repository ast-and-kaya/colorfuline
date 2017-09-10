#include "ResultScene.h"

int ResultScene::m_result_score;
int ResultScene::m_result_combo;
int ResultScene::m_result_perfect;

int ResultScene::m_result_note_number;

ResultScene::ResultScene()
{
}


ResultScene::~ResultScene()
{
}


void ResultScene::initialize()
{
	//�w�i
	m_bg.setTexture(tex.get("black"));

	m_shad.loadFromFile("data/shader/result_bg.frag", sf::Shader::Fragment);
	m_shad.setParameter("r", sf::Vector2f(windowManager.getWindow()->getSize().x, windowManager.getWindow()->getSize().y));
	m_state.shader = &m_shad;
	
	//�t�H���g
	characterDisplay.setFont("Dosis", "data/font/Dosis-Light.ttf");
	//�X�R�A���̕���
	//�X�R�A
	characterDisplay.setCharacter("Iscore", "Dosis", "SCORE", sf::Vector2f(900, 158), 176, sf::Color( 0, 0, 0, 30));
	characterDisplay.setCharacter("Sscore", "Dosis", to_string(m_result_score), sf::Vector2f(50, 300), 100);
	//�R���{
	characterDisplay.setCharacter("Icombo", "Dosis", "COMBO", sf::Vector2f(900, 430), 176, sf::Color(0, 0, 0, 30));
	characterDisplay.setCharacter("Scombo", "Dosis", to_string(m_result_combo), sf::Vector2f(50, 500), 100);
	//�p�[�t�F�N�g
	characterDisplay.setCharacter("Iperfect", "Dosis", "PERFECT", sf::Vector2f(900, 698), 176, sf::Color(0, 0, 0, 30));
	characterDisplay.setCharacter("Sperfect", "Dosis", to_string(m_result_perfect), sf::Vector2f(50, 700), 100);
	//���j���[
	characterDisplay.setCharacter("retry", "Dosis", "Retry", sf::Vector2f(120, 850), 120);
	characterDisplay.setCharacter("next", "Dosis", "Next", sf::Vector2f(520, 850), 120);

	//�Z���N�g�o�[
	m_select.setTexture(tex.get("result_select"));
	m_select.setOrigin(350, 0);
	m_select_tf = true;
	m_select_posx[0] = 330;//retry
	m_select_posx[1] = 730;//next
	m_select.setPosition(m_select_posx[m_select_tf], 968);

	//�u���b�N
	sceneMovement.initialize();
	sceneMovement.Out();
}

Scene* ResultScene::update()
{
	Scene* next = this;
	sceneMovement.update();

	//�Z���N�g�o�[
	if (sceneMovement.getAlpha() == 0)
	{
		if (keyManager.push_key(sf::Keyboard::Right) || keyManager.push_key(sf::Keyboard::Left)) {
			m_select_tf = !m_select_tf;
			m_select.setScale(0, 1);
		}
	}
	m_select.setPosition(m_select_posx[m_select_tf], 968);//�ʒu�ύX
	if (m_select.getScale().x < 1) m_select.setScale(m_select.getScale().x + 0.15, 1);//�Z���N�g�o�[�X�P�[������

	if (keyManager.push_key(sf::Keyboard::Return))
	{
		sceneMovement.In();
	}
	if (sceneMovement.getAlpha() >= 255)
	{
		if (m_select_tf)
		{
			SelectScene s;
			s.setBlackZindex(true);
			next = new SelectScene;
		}
		else {
			next = new GameScene;
		}
	}

	return next;
}

void ResultScene::render()
{

	windowManager.getWindow()->draw( m_bg, m_state);

	characterDisplay.render("Iscore");
	characterDisplay.render("Icombo");
	characterDisplay.render("Iperfect");

	characterDisplay.render("next");
	characterDisplay.render("retry");
	windowManager.getWindow()->draw(m_select);

	sceneMovement.render();

	musicGuide.render();
}


void ResultScene::setScereData(int score, int combo, int perfect, int note) {
	m_result_score = score;
	m_result_combo = combo;
	m_result_perfect = perfect;
	m_result_note_number = note;
}
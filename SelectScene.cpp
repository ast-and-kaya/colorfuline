#include "SelectScene.h"


SelectScene::SelectScene()
{
}


SelectScene::~SelectScene()
{
}

void SelectScene::initialize()
{
	//��Փx�J���[
	m_diff_color[0] = sf::Color::Cyan;
	m_diff_color[1] = sf::Color::Yellow;
	m_diff_color[2] = sf::Color::Magenta;

	//�ȑI��
	sf::Texture t;
	t.create(1000, 1080);
	m_list_bg.setTexture(t);
	//�I��w�i
	m_shad_list_bg.loadFromFile("data/shader/select_bar.frag",sf::Shader::Fragment);
	m_shad_list_bg.setParameter("r", sf::Vector2f(config.m_window_size.x,config.m_window_size.y));
	m_shad_list_bg.setParameter("pos", (config.m_window_size.y/1080.f) * 83.f * 7.f);
	m_state_list_bg.shader = &m_shad_list_bg;

	//�Ȗ����X�g
	m_font_list.loadFromFile("data/font/851tegaki.ttf");
	m_s_move = 0;
	m_list_pos = sf::Vector2f(500, -config.getNowMusic(config.Num)*77);
	for (int i = 0; i < musicManager.getItemNumber(); i++)
	{
		sf::Text t;

		t.setString(cv.from_bytes(musicManager.getItem(i).music_name));
		t.setFont(m_font_list);
		t.setCharacterSize(60);
		t.setPosition(m_list_pos + sf::Vector2f( -t.getGlobalBounds().width/2, (i+6)*77));
		
		m_list.push_back(t);
	}

	//�ȏ��
	//�g�p�F
	sf::Color c[7] = {
		sf::Color::Red,sf::Color::Green,sf::Color::Blue,
		sf::Color::Cyan,sf::Color::Magenta,sf::Color::Yellow,
		sf::Color::White
	};
	for (int i = 0; i < 7; i++)
	{
		m_use_color[i].setTexture(tex.get("select_use_color"));
		m_use_color[i].setColor(c[i]);
		m_use_color[i].setPosition(sf::Vector2f(1250,190) + sf::Vector2f(60*i,0));
	}
	setColorBar(musicManager.getItem(config.getNowMusic(config.Num)).easy_color);
	//����
	characterDisplay.setFont("tegaki", "data/font/851tegaki.ttf");
	characterDisplay.setCharacter("title", "tegaki", musicManager.getItem(config.getNowMusic(config.Num)).music_name, sf::Vector2f(1050, 0), 75);//�Ȗ�
	characterDisplay.setCharacter("artist", "tegaki", musicManager.getItem(config.getNowMusic(config.Num)).artist, sf::Vector2f(1400, 100), 60);//�A�[�e�B�X�g
	characterDisplay.setCharacter("level", "tegaki", "Lv.", sf::Vector2f(1050, 180), 85);//���x��
	//�T���l�C��
	m_tex_jacket.loadFromFile("data/image/select/no_jacket.png");//�{��
	m_jacket.setTexture(m_tex_jacket);
	m_jacket.setPosition(1000, 0);
	m_shad_jacket.loadFromFile("data/shader/select_jacket.frag", sf::Shader::Fragment);//�V�F�[�_
	m_shad_jacket.setParameter("texture", m_tex_jacket);
	m_shad_jacket.setParameter("texture2", tex.get("select_jacket_cover"));
	m_shad_jacket.setParameter("t_color", m_diff_color[config.getNowMusic(config.Diff)]);
	m_state_jacket.shader = &m_shad_jacket;

	m_bf_music = -1;

	sceneMovement.initialize();
	sceneMovement.Out();
}


Scene* SelectScene::update()
{
	Scene* next = this;

	//�u���b�N
	sceneMovement.update();

	//�ȑI��
	if (keyManager.push_key(sf::Keyboard::Up) && config.getNowMusic(config.Num) > 0) {
		m_s_move += 77;
		config.setNowMusicNum(config.getNowMusic(config.Num) - 1);
	}
	if (keyManager.push_key(sf::Keyboard::Down) && config.getNowMusic(config.Num) < musicManager.getItemNumber()-1) {
		m_s_move -= 77;
		config.setNowMusicNum(config.getNowMusic(config.Num) + 1);
	}
	//�Z���N�g�ړ�
	if (m_s_move != 0) {
		m_list_pos.y += m_s_move / 3;
		m_s_move -= m_s_move / 3;
		for (int i = 0; i < musicManager.getItemNumber(); i++)
		{
			m_list[i].setPosition(m_list_pos + sf::Vector2f(-m_list[i].getGlobalBounds().width / 2, (i+6) * 77));
		}
	}
	for (int i = 0; i < m_list.size(); i++) {
		int alpha = 255 - (abs(i - config.getNowMusic(config.Num))-0.5) *(255 / 7);
		alpha = (alpha < 0) ? 0:alpha;
		m_list[i].setColor(sf::Color(255,255,255,alpha));
	}
	m_list[config.getNowMusic(config.Num)].setColor(sf::Color::Black);

	//�I��w�i
	static sf::Clock t;
	m_shad_list_bg.setParameter("t", t.getElapsedTime().asMilliseconds());
	m_list_bg.setColor(m_diff_color[config.getNowMusic(config.Diff)]);


	//��Փx�I��
	if (keyManager.push_key(sf::Keyboard::Right) && config.getNowMusic(config.Diff) < 2) {
		config.setNowMusicDiff(config.getNowMusic(config.Diff) + 1);
	}
	if (keyManager.push_key(sf::Keyboard::Left) && config.getNowMusic(config.Diff) > 0) {
		config.setNowMusicDiff(config.getNowMusic(config.Diff) - 1);
	}

	//�ȏ��X�V
	if (m_bf_music != config.getNowMusic(config.Num))
	{
		//�g�p�F
		if (config.getNowMusic(config.Diff) == 0) setColorBar(musicManager.getItem(config.getNowMusic(config.Num)).easy_color);
		if (config.getNowMusic(config.Diff) == 1) setColorBar(musicManager.getItem(config.getNowMusic(config.Num)).normal_color);
		if (config.getNowMusic(config.Diff) == 2) setColorBar(musicManager.getItem(config.getNowMusic(config.Num)).hard_color);
		//����
		characterDisplay.changeString("title", musicManager.getItem(config.getNowMusic(config.Num)).music_name);//�Ȗ�
		characterDisplay.changeString("artist", musicManager.getItem(config.getNowMusic(config.Num)).artist);//�A�[�e�B�X�g
		characterDisplay.changeString("level", "Lv." + to_string(musicManager.getItem(config.getNowMusic(config.Num)).level[config.getNowMusic(config.Diff)]));//���x��
		//�T���l�C��
		string s = musicManager.getFolderList(config.getNowMusic(config.Num));
		if (!m_tex_jacket.loadFromFile("data/music/" + s + "/jacket.png")) {
			m_tex_jacket.loadFromFile("data/image/select/no_jacket.png");
		}
		m_shad_jacket.setParameter("texture", m_tex_jacket);
		m_bf_music = config.getNowMusic(config.Num);
	}
	m_shad_jacket.setParameter("t_color", m_diff_color[config.getNowMusic(config.Diff)]);

	//�V�[���ړ�
	static bool scene;
	if (keyManager.push_key(sf::Keyboard::Return)) {
		sceneMovement.In();
		scene = true;
	}
	if (keyManager.push_key(sf::Keyboard::Escape)) {
		sceneMovement.In();
		scene = false;
	}

	if (sceneMovement.getAlpha() == 255) {
		if (scene) next = new GameScene;
		if (!scene) next = new TitleScene;
	}

	return next;
}

void SelectScene::render()
{
	//�I��w�i
	windowManager.getWindow()->draw(m_list_bg, m_state_list_bg);
	//�Ȗ����X�g
	for (int i = 0; i < musicManager.getItemNumber(); i++)
	{
		windowManager.getWindow()->draw(m_list[i]);
	}
	//�W���P�b�g
	windowManager.getWindow()->draw(m_jacket,m_state_jacket);//�T���l�C��
	//�g�p�F
	for (int i = 0; i < 7; i++)
	{
		windowManager.getWindow()->draw(m_use_color[i]);
	}
	//����
	characterDisplay.render("title");
	characterDisplay.render("artist");
	characterDisplay.render("level");
	
	sceneMovement.render();
}

void SelectScene::setColorBar(const int* a) {
	for (int i = 0; i < 7; i++)
	{
		m_use_color[i].setColor(sf::Color(
			m_use_color[i].getColor().r,
			m_use_color[i].getColor().g,
			m_use_color[i].getColor().b,
			a[i] * 255
		));
	}
}
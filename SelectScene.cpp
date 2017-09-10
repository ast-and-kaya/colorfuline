#include "SelectScene.h"

bool SelectScene::m_black_zindex;

SelectScene::SelectScene()
{
}

SelectScene::~SelectScene()
{
}

void SelectScene::initialize()
{
	//難易度カラー
	m_diff_color[0] = sf::Color::Cyan;
	m_diff_color[1] = sf::Color::Yellow;
	m_diff_color[2] = sf::Color::Magenta;

	//曲選択
	sf::Texture t;
	t.create(1000, 1080);
	m_list_bg.setTexture(t);
	m_list_bg.setPosition(920, 0);
	//選択背景
	m_shad_list_bg.loadFromFile("data/shader/select_bar.frag",sf::Shader::Fragment);
	m_shad_list_bg.setParameter("r", sf::Vector2f(config.m_window_size.x,config.m_window_size.y));
	m_shad_list_bg.setParameter("pos", (config.m_window_size.y/1080.f) * 83.f * 7.f);
	m_state_list_bg.shader = &m_shad_list_bg;

	//曲名リスト
	m_font_list.loadFromFile("data/font/851tegaki.ttf");
	m_s_move = 0;
	m_list_pos = sf::Vector2f(920 + 500, -config.getNowMusic(config.Num)*77);
	for (int i = 0; i < musicManager.getItemNumber(); i++)
	{
		sf::Text t;

		t.setString(cv.from_bytes(musicManager.getItem(i).music_name));
		t.setFont(m_font_list);
		t.setCharacterSize(60);
		t.setPosition(m_list_pos + sf::Vector2f( -t.getGlobalBounds().width/2, (i+6)*77));
		
		m_list.push_back(t);
	}

	//曲情報
	musicGuide.initialize();

	//サムネイル
	m_tex_jacket.loadFromFile("data/image/select/no_jacket.png");//本体
	m_jacket.setTexture(m_tex_jacket);
	m_shad_jacket.loadFromFile("data/shader/select_jacket.frag", sf::Shader::Fragment);//シェーダ
	m_shad_jacket.setParameter("texture", m_tex_jacket);
	m_shad_jacket.setParameter("t_color", m_diff_color[config.getNowMusic(config.Diff)]);
	m_state_jacket.shader = &m_shad_jacket;

	m_bf_music = -1;

	sceneMovement.initialize();
	sceneMovement.Out();

	preview.initialize();
}


Scene* SelectScene::update()
{
	Scene* next = this;

	//ブラック
	sceneMovement.update();
	if (sceneMovement.getAlpha() == 0) m_black_zindex = true;
	//cout << m_black_zindex << endl;

	//曲選択
	if (keyManager.push_key(sf::Keyboard::Up) && config.getNowMusic(config.Num) > 0) {
		m_s_move += 77;
		config.setNowMusicNum(config.getNowMusic(config.Num) - 1);
	}
	if (keyManager.push_key(sf::Keyboard::Down) && config.getNowMusic(config.Num) < musicManager.getItemNumber()-1) {
		m_s_move -= 77;
		config.setNowMusicNum(config.getNowMusic(config.Num) + 1);
	}
	//セレクト移動
	if (m_s_move != 0) {
		m_list_pos.y += m_s_move / 3;
		m_s_move -= m_s_move / 3;
		for (int i = 0; i < musicManager.getItemNumber(); i++)
		{
			m_list[i].setPosition(m_list_pos + sf::Vector2f(-m_list[i].getGlobalBounds().width / 2, (i+6) * 77));
		}
	}
	for (int i = 0; i < m_list.size(); i++) {
		int alpha = 255 - abs(i - config.getNowMusic(config.Num)) * 255 / 8 ;
		m_list[i].setColor(sf::Color(255,255,255,alpha));
	}
	m_list[config.getNowMusic(config.Num)].setColor(sf::Color::Black);

	//選択背景
	static sf::Clock t;
	m_shad_list_bg.setParameter("t", t.getElapsedTime().asMilliseconds());
	m_list_bg.setColor(m_diff_color[config.getNowMusic(config.Diff)]);


	//難易度選択
	if (keyManager.push_key(sf::Keyboard::Right) && config.getNowMusic(config.Diff) < 2) {
		config.setNowMusicDiff(config.getNowMusic(config.Diff) + 1);
	}
	if (keyManager.push_key(sf::Keyboard::Left) && config.getNowMusic(config.Diff) > 0) {
		config.setNowMusicDiff(config.getNowMusic(config.Diff) - 1);
	}

	//使用色
	//文字
	musicGuide.update();

	//曲情報更新
	if (m_bf_music != config.getNowMusic(config.Num))
	{
		//サムネイル
		string s = musicManager.getFolderList(config.getNowMusic(config.Num));
		if (!m_tex_jacket.loadFromFile("data/music/" + s + "/jacket.png")) {
			m_tex_jacket.loadFromFile("data/image/select/no_jacket.png");
		}
		m_shad_jacket.setParameter("texture", m_tex_jacket);
		m_bf_music = config.getNowMusic(config.Num);
	}
	m_shad_jacket.setParameter("t_color", m_diff_color[config.getNowMusic(config.Diff)]);

	//曲プレビュー
	preview.update();

	//シーン移動
	static bool scene;
	if (keyManager.push_key(sf::Keyboard::Return)) {
		preview.getMusic().stop();
		sceneMovement.In();
		scene = true;
	}
	if (keyManager.push_key(sf::Keyboard::Escape)) {
		sceneMovement.In();
		m_black_zindex = false;
		scene = false;
	}

	if (sceneMovement.getAlpha() == 255) {
		preview.getMusic().stop();
		if (scene) next = new GameScene;
		if (!scene) next = new TitleScene;
	}

	return next;
}

void SelectScene::render()
{
	//選択背景
	windowManager.getWindow()->draw(m_list_bg, m_state_list_bg);
	//曲名リスト
	for (int i = 0; i < musicManager.getItemNumber(); i++)
	{
		windowManager.getWindow()->draw(m_list[i]);
	}
	//ジャケット
	windowManager.getWindow()->draw(m_jacket,m_state_jacket);//サムネイル
	//曲pre
	preview.render();

	if (m_black_zindex) sceneMovement.render();

	//文字
	musicGuide.render();
	
	if (!m_black_zindex) sceneMovement.render();
}

void SelectScene::setBlackZindex(bool b)
{
	m_black_zindex = b;
}

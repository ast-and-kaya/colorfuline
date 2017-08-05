#include "GameScene.h"

#include "SelectScene.h"
#include "ResultScene.h"

GameScene::GameScene()
{
}


GameScene::~GameScene()
{
}

void GameScene::initialize()
{
	m_game_state = 0;

	m_score = 0;
	m_perfect = 0;
	m_maxcombo = 0;

	m_note_number = 0;

	m_combo = 0;

	m_black_zindex = false;

	//音楽ファイル読み込み
	string folder_name = musicManager.getFolderList(config.getNowMusic(config.Num));
	m_music.Load(folder_name, "data/music/" + folder_name + "/music.wav");

	visualEffect.initialize("data/music/" + folder_name + "/music.wav");

	//cout << config.getNowMusic(config.Num) << endl;

	//ノート追加
	//ファイルの仕様と拡張子を決めておく
	sf::Color c[3] = {sf::Color::Red,sf::Color::Green,sf::Color::Blue};
	for (int i = 0; i < 300; i++) {
		m_note.push_back(Note());
		m_note[i].setNote(i*(60.f/185.f) + 0.1, c[i%3]);

		m_note_number++;
	}

	//判定ライン
	judgeLine.initialize();

	//スコア等の文字
	//フォント
	characterDisplay.setFont("Dosis", "data/font/Dosis-Light.ttf");
	characterDisplay.setFont("tegaki", "data/font/851tegaki.ttf");
	//文字
	characterDisplay.setCharacter("score", "Dosis", to_string((int)m_score), sf::Vector2f(100, 780),160);
	characterDisplay.setCharacter("combo", "Dosis", "x" + to_string((int)m_combo), sf::Vector2f(1600, 780),160);
	characterDisplay.setCharacter("title", "tegaki", musicManager.getItem(config.getNowMusic(config.Num)).music_name, sf::Vector2f(50, 0),75);
	characterDisplay.setCharacter("artist", "tegaki", musicManager.getItem(config.getNowMusic(config.Num)).artist, sf::Vector2f(50, 100),60);

	pause.initialize();
	supportLine.initialize();
	sceneMovement.initialize();
	sceneMovement.In();
}


Scene* GameScene::update()
{
	Scene* next = this;

	keyJudge.update();
	timer.update();
	sceneMovement.update();
	judgeLine.update();
	visualEffect.updata(timer.getTime() - config.getStartMargin());

	switch (m_game_state)
	{
	case 0://before
		playBefore();
		break;
	case 1://now
		playNow();
		break;
	case 2://after
		playAfter(next);
		break;
	case 3://stop
		m_game_state = pause.update(next);
		if (m_game_state == 1) {
			m_music.start();
			timer.start();
		}
		break;
	}

	return next;
}

void GameScene::render()
{
	//背景
	visualEffect.render();

	//supportLine.render();

	//文字
	characterDisplay.render("score");
	characterDisplay.render("combo");
	characterDisplay.render("title");
	characterDisplay.render("artist");

	if (!m_black_zindex)sceneMovement.render();

	//判定ライン
	judgeLine.render();

	//ノート
	for (auto& it: m_note)
	{
		it.render();
	}

	if (m_black_zindex)sceneMovement.render();

	//ポーズ画面
	if(m_game_state == 3) pause.render();

}

void GameScene::playBefore() {
	if (judgeLine.pre())
	{
		sceneMovement.Out();
		timer.initialize();
		m_game_state = 1;
	}
}

void GameScene::playNow() {

	//曲スタート
	if (config.getStartMargin() <= timer.getTime()) {
		m_music.start();//再生中は無効
	}

	int judge = m_note[0].judge(timer.getTime() - config.getStartMargin(), keyJudge.getKeyColor());

	//成功判定
	if (judge != 0)
	{
		//cout << judge << endl;
		m_combo++;

		switch (judge)
		{
		case 1://perfect
			m_score += 100;
			m_perfect++;
			break;
		case 2://great
			m_score += 10;
			break;
		case 3://good
			m_score += 1;
			break;
		}
		m_note.erase(m_note.begin());
	}

	//画面外(ミス)判定
	if (m_note[0].rangeOut(timer.getTime() - config.getStartMargin()))
	{
		//コンボ中断と更新
		m_maxcombo = (m_maxcombo < m_combo) ? m_combo : m_maxcombo;
		m_combo = 0;
		m_note.erase(m_note.begin());
	}

	for (auto& it : m_note)
	{
		it.update(timer.getTime() - config.getStartMargin());
	}

	supportLine.update();

	//音ズレ
	float f = (timer.getTime() - config.getStartMargin()) - m_music.getOffset();
	//cout << f << endl;

	//スコア表示更新
	characterDisplay.changeString("score", to_string((int)m_score));
	characterDisplay.changeString("combo", "x" + to_string((int)m_combo));

	//アフター移動
	if (m_note.size() == 0 || keyManager.push_key(sf::Keyboard::Return)){
		m_music.stop();
		sceneMovement.In();
		m_black_zindex = true;
		m_game_state = 2;//暫定
	}

	//途中停止
	if (keyManager.push_key(sf::Keyboard::Escape)) {
		timer.pouse();
		m_music.pause();
		m_game_state = 3;
	}
}

void GameScene::playAfter(Scene*& n) {

	//リザルト
	if (sceneMovement.getAlpha() == 255)
	{
		m_maxcombo = (m_maxcombo < m_combo) ? m_combo : m_maxcombo;
		ResultScene result;
		result.setScereData(m_score, m_maxcombo, m_perfect, m_note_number);
		n = new ResultScene;
	}
}
#include "DxLib.h"
#include "BackGround.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Easing.h"
#include "Particle.h"
#include "RainbowEngine.h"
#include "Navi.h"
#include "Goal.h"
#include "Shake.h"
#include "Opening.h"


const char TITLE[] = "クラスでできました～";

const float WIN_WIDTH = 800.0f; //ウィンドウ横幅
const float WIN_HEIGHT = 450.0f;//ウィンドウ縦幅

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	ChangeWindowMode(1);						//フルスクリーンモードに設定
	//ウィンドウサイズを手動では変更できず、かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetMainWindowText(TITLE);					// タイトルを変更
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);	//画面サイズの最大サイズ、カラービット数を設定（モニターの解像度に合わせる）
	SetWindowSizeExtendRate(1.0);				//画面サイズを設定（解像度との比率で設定）
	SetBackgroundColor(200, 200, 200);		// 画面の背景色を設定する

	//Dxライブラリの初期化
	if (DxLib_Init() == -1) { return -1; }

	//（ダブルバッファ）描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	//画像などのリソースデータの変数宣言と読み込み



	//ゲームループで使う変数の宣言
	XINPUT_STATE input;
	char keys[256] = { 0 }; //最新のキーボード情報用
	char oldkeys[256] = { 0 };//1ループ（フレーム）前のキーボード情報
	int Color = GetColor(0, 0, 0);
	int Scene = 0;
	Opening* opening = new Opening();
	enum Scene {
		Title,
		Option,
		End,
		StageSelect,
		Play,
		result
	};
	int Stage = 0;
	enum Stage {
		one = 1,    //0000_0000_0001
		two = 2,    //0000_0000_0010
		three = 4,    //0000_0000_0100
		four = 8,    //0000_0000_1000
		five = 16,  //0000_0001_0000
		six = 32,  //0000_0010_0000
		seven = 64,  //0000_0100_0000
		eight = 128, //0000_1000_0000
		nine = 256,//0001_0000_0000
		//ten = 512//0010_0000_0000
	};
	Background* background = new Background();
	Player* player = new Player(8, 4);
	const int ENEMY_MAX = 10;
	Enemy* enemy[ENEMY_MAX];
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i] = new Enemy(8, 2, 1);
	}
	Easing* easing = new Easing();

	const int PARTI_MAX = 70;
	Particle* particle[ENEMY_MAX][PARTI_MAX];
	for (int i = 0; i < ENEMY_MAX; i++) {
		for (int j = 0; j < PARTI_MAX; j++) {
			particle[i][j] = new Particle();
		}
	}

	RainbowEngine* rainbow_engine = new RainbowEngine;
	Navi* navi = new Navi();
	Goal* goal = new Goal();
	Shake* shake = new Shake();

	int resetFlag = 0;

	// ゲームループ
	while (1) {
		//最新のキーボード情報だったものは１フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; i++) {
			oldkeys[i] = keys[i];
		}
		//最新のキーボード情報を取得
		GetHitKeyStateAll(keys);
		// 入力状態を取得
		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		SetJoypadDeadZone(DX_INPUT_PAD1, 0.20);
		//画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//
		switch (Scene) {

		case Title:
			if (opening->getIsNextstage() == 1) {
				Scene = StageSelect;
			}
			if (opening->getIsNextstage() == 2) {
				Scene = Option;
			}
			if (opening->getIsNextstage() == 3) {
				Scene = End;
			}
			break;
		case Option:
			break;

		case End:
			break;

		case StageSelect:
			if (keys[KEY_INPUT_1] == 1 && oldkeys[KEY_INPUT_1] == 0) {
				for (int i = 0; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				enemy[0] = new Enemy(8, 4, 1);
				enemy[1] = new Enemy(8, 4, 1);
				Stage = one;
				Scene = 2;
			}
			if (keys[KEY_INPUT_2] == 1 && oldkeys[KEY_INPUT_2] == 0) {
				for (int i = 0; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				enemy[0] = new Enemy(8, 4, 1);
				enemy[1] = new Enemy(8, 4, 1);
				enemy[2] = new Enemy(8, 4, 1);
				Stage = two;
				Scene = 2;
			}
			if (keys[KEY_INPUT_3] == 1 && oldkeys[KEY_INPUT_3] == 0) {
				for (int i = 0; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				enemy[0] = new Enemy(8, 2, 0);
				enemy[1] = new Enemy(8, 2, 0);
				enemy[2] = new Enemy(8, 2, 0);
				enemy[3] = new Enemy(8, 2, 0);
				Stage = three;
				Scene = 2;
			}
			if (keys[KEY_INPUT_4] == 1 && oldkeys[KEY_INPUT_4] == 0) {
				for (int i = 0; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				enemy[0] = new Enemy(16, 3, 1);
				enemy[1] = new Enemy(8, 4, 1);
				Stage = four;
				Scene = 2;
			}
			if (keys[KEY_INPUT_5] == 1 && oldkeys[KEY_INPUT_5] == 0) {
				for (int i = 0; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				enemy[0] = new Enemy(8, 4, 1);
				enemy[1] = new Enemy(16, 3, 1);
				enemy[2] = new Enemy(16, 3, 1);
				enemy[3] = new Enemy(16, 3, 1);
				Stage = five;
				Scene = 2;
			}
			if (keys[KEY_INPUT_6] == 1 && oldkeys[KEY_INPUT_6] == 0) {
				for (int i = 0; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				enemy[0] = new Enemy(8, 4, 1);
				enemy[1] = new Enemy(8, 4, 1);
				enemy[2] = new Enemy(8, 4, 1);
				enemy[3] = new Enemy(16, 3, 1);
				enemy[4] = new Enemy(16, 3, 1);
				enemy[5] = new Enemy(16, 3, 1);
				Stage = six;
				Scene = 2;
			}if (keys[KEY_INPUT_7] == 1 && oldkeys[KEY_INPUT_7] == 0) {
				for (int i = 0; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				enemy[0] = new Enemy(8, 4, 1);
				enemy[1] = new Enemy(16, 3, 1);
				enemy[2] = new Enemy(24, 2, 1);
				Stage = seven;
				Scene = 2;
			}if (keys[KEY_INPUT_8] == 1 && oldkeys[KEY_INPUT_8] == 0) {
				for (int i = 0; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				enemy[0] = new Enemy(8, 4, 1);
				enemy[1] = new Enemy(8, 4, 1);
				enemy[2] = new Enemy(16, 3, 1);
				enemy[3] = new Enemy(24, 2, 1);
				enemy[4] = new Enemy(24, 2, 1);
				Stage = eight;
				Scene = 2;
			}if (keys[KEY_INPUT_9] == 1 && oldkeys[KEY_INPUT_9] == 0) {
				for (int i = 0; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				enemy[0] = new Enemy(8, 3, 1);
				enemy[1] = new Enemy(8, 3, 1);
				enemy[2] = new Enemy(16, 2, 1);
				enemy[3] = new Enemy(16, 2, 1);
				enemy[4] = new Enemy(24, 1, 1);
				enemy[5] = new Enemy(24, 1, 1);
				enemy[6] = new Enemy(24, 1, 1);
				Stage = nine;
				Scene = 2;
			}
			break;
		case Play:
			break;
		case result:
			break;
		default:
			break;
		}
		//更新処理
		switch (Scene) {
		case Title:
			player->update(*enemy, background, easing, keys, oldkeys, WIN_WIDTH);
			background->update(keys, oldkeys, &input, player, easing);
			enemy[0]->update(*enemy, player, shake, background, keys, oldkeys);
			opening->collide(player);
			opening->update(keys, oldkeys);
			break;
		case StageSelect:
			break;
		case Play:
			switch (Stage) {
			case one:
				player->update(*enemy, background, easing, keys, oldkeys, WIN_WIDTH);
				background->update(keys, oldkeys, &input, player, easing);
				navi->update(WIN_HEIGHT, WIN_WIDTH, player, goal, background);
				goal->update(WIN_WIDTH, WIN_HEIGHT, background, player);
				shake->shaking();
				for (int i = 0; i < 2; i++) {
					enemy[i]->update(*enemy, player, shake, background, keys, oldkeys);
				}
				break;
			case two:
				player->update(*enemy, background, easing, keys, oldkeys, WIN_WIDTH);
				background->update(keys, oldkeys, &input, player, easing);
				navi->update(WIN_HEIGHT, WIN_WIDTH, player, goal, background);
				goal->update(WIN_WIDTH, WIN_HEIGHT, background, player);
				shake->shaking();
				break;
			case three:

				break;
			case four:

				break;
			case five:

				break;
			case six:

				break;
			case seven:

				break;
			case eight:

				break;
			case nine:
				break;
			default:
				Stage = one;
				break;
			}
			if (resetFlag == 1) {
				delete player;
				delete background;
				delete navi;
				delete goal;
				for (int i = 0; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				background = new Background();
				player = new Player(8, 4);
				navi = new Navi();
				goal = new Goal();
				resetFlag = 0;
			}
			break;
		case result:
			break;
		default:
			break;
		}
		//描画処理
		switch (Scene) {
		case Title:
			background->draw(shake);
			enemy[0]->draw(shake);
			opening->draw();
			player->draw(*enemy, shake);
			player->drawEffect();
			break;
			break;
		case StageSelect:
			DrawFormatString(0, 0, GetColor(0, 0, 0), "1:(1)");
			DrawFormatString(0, 15, GetColor(0, 0, 0), "2:(2)");
			DrawFormatString(0, 30, GetColor(0, 0, 0), "3:(3)");
			DrawFormatString(0, 45, GetColor(0, 0, 0), "4:(4)");
			DrawFormatString(0, 60, GetColor(0, 0, 0), "5:(5)");
			DrawFormatString(0, 75, GetColor(0, 0, 0), "6:(6)");
			DrawFormatString(0, 90, GetColor(0, 0, 0), "7:(7)");
			DrawFormatString(0, 105, GetColor(0, 0, 0), "8:(8)");
			DrawFormatString(0, 120, GetColor(0, 0, 0), "9:(9)");
			//DrawFormatString(0, 135, GetColor(0, 0, 0), "10:(10)");
			break;
		case Play:
			background->draw(shake);
			navi->draw();
			goal->draw(shake);
			player->draw(*enemy, shake);
			player->drawEffect();
			for (int i = 0; i < ENEMY_MAX; i++) {
				enemy[i]->draw(shake);
			}
			DrawFormatString(0, 0, Color, "LeftTrigger:%d RightTrigger:%d",
				input.LeftTrigger, input.RightTrigger);
			DrawFormatString(0, 16, Color, "ThumbLX:%d ThumbLY:%d",
				input.ThumbLX, input.ThumbLY);
			DrawFormatString(0, 32, Color, "ThumbRX:%d ThumbRY:%d",
				input.ThumbRX, input.ThumbRY);
			for (int i = 0; i < ENEMY_MAX; i++) {
				for (int j = 0; j < PARTI_MAX; j++) {
					particle[i][j]->draw(rainbow_engine, shake);
				}
			}
			//DrawFormatString(0,0, GetColor(0,0,0), "GoalX: %f", goal->getInitX());
			//DrawFormatString(0,20, GetColor(0,0,0), "GoalY: %f", goal->getInitY());
			//DrawFormatString(0,40, GetColor(0,0,0), "PlayerX: %f", player->getPosX() + background->getScrollX());
			//DrawFormatString(0,60, GetColor(0,0,0), "PlayerY: %f", player->getPosY() + background->getScrollY());
			//// float per = abs((WIN_HEIGHT - player->getPosY())/ player2goalY);
			//DrawFormatString(0,80, GetColor(0,0,0), "player2goalX: %f", goal->getInitX()- (player->getPosX() + background->getScrollX()));
			//DrawFormatString(0,100, GetColor(0,0,0), "player2goalY: %f",goal->getInitY()- (player->getPosY() + background->getScrollY()));
			//DrawFormatString(0,120, GetColor(0,0,0), "length: %f",  player->getPosY());
			//DrawFormatString(0,140, GetColor(0,0,0), "per: %f", abs((WIN_HEIGHT - player->getPosY())/ (goal->getInitY()- (player->getPosY() + background->getScrollY()))));
			DrawFormatString(0, 0, Color, "LeftTrigger:%d RightTrigger:%d",
				input.LeftTrigger, input.RightTrigger);
			DrawFormatString(0, 16, Color, "ThumbLX:%d ThumbLY:%d",
				input.ThumbLX, input.ThumbLY);
			DrawFormatString(0, 32, Color, "ThumbRX:%d ThumbRY:%d",
				input.ThumbRX, input.ThumbRY);

			break;
		case result:
			break;
		default:
			break;
		}
		//---------  ここまでにプログラムを記述  ---------//
		ScreenFlip();//（ダブルバッファ）裏面
		// 20ミリ秒待機（疑似60FPS）
		WaitTimer(20);
		// Windows システムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}
		// ＥＳＣキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	//Dxライブラリ終了処理
	DxLib_End();
	return 0;
}
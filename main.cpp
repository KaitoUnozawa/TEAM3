#include "DxLib.h"
#include "BackGraoud.h"
#include "Foot.h"
#include"GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Navi.h"
#include "Goal.h"

const char TITLE[] = "クラスでできました～";

const int WIN_WIDTH = 800; //ウィンドウ横幅
const int WIN_HEIGHT = 450;//ウィンドウ縦幅

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
	char keys[256] = { 0 }; //最新のキーボード情報用
	char oldkeys[256] = { 0 };//1ループ（フレーム）前のキーボード情報
	int Scene = 0;
	enum Scene{
		Title,
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
		ten = 512//0010_0000_0000
	};
	BackGraoud* backgraoud = new BackGraoud();
	Player* player = new Player(0, 0, 8, 4);
	const int FOOT_MAX = 4;
	Foot* foot = new Foot();

	const int ENEMY_MAX = 10;
	Enemy* enemy[ENEMY_MAX];
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i] = new Enemy(8, 2, 1);
	}

	Navi* navi = new Navi();
	Goal* goal = new Goal( );

	// ゲームループ
	while (1) {
		//最新のキーボード情報だったものは１フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; i++) {
			oldkeys[i] = keys[i];
		}
		//最新のキーボード情報を取得
		GetHitKeyStateAll(keys);
		//画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//
		switch (Scene) {
		case Title:
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
				Scene = 1;
			}
			break;
		case StageSelect:
			if (keys[KEY_INPUT_1] == 1 && oldkeys[KEY_INPUT_1] == 0) {
				player = new Player(0, 0, 8, 4);
				enemy[0] = new Enemy(8, 4, 1);
				enemy[1] = new Enemy(8, 4, 1);
				for (int i = 2; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				Scene = 2;
			}
			if (keys[KEY_INPUT_2] == 1 && oldkeys[KEY_INPUT_2] == 0) {
				player = new Player(0, 0, 8, 4);
				enemy[0] = new Enemy(8, 4, 1);
				enemy[1] = new Enemy(8, 4, 1);
				enemy[2] = new Enemy(8, 4, 1);
				for (int i = 3; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				Scene = 2;
			}
			if (keys[KEY_INPUT_3] == 1 && oldkeys[KEY_INPUT_3] == 0) {
				player = new Player(0, 0, 8, 4);
				enemy[0] = new Enemy(8, 4, 1);
				enemy[1] = new Enemy(8, 4, 1);
				enemy[2] = new Enemy(8, 4, 1);
				enemy[3] = new Enemy(8, 4, 1);
				for (int i = 4; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				Scene = 2;
			}
			if (keys[KEY_INPUT_4] == 1 && oldkeys[KEY_INPUT_4] == 0) {
				player = new Player(0, 0, 8, 4);
				enemy[0] = new Enemy(16, 3, 1);
				enemy[1] = new Enemy(8, 4, 1);
				for (int i = 2; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				Scene = 2;
			}
			if (keys[KEY_INPUT_5] == 1 && oldkeys[KEY_INPUT_5] == 0) {
				player = new Player(0, 0, 8, 4);
				enemy[0] = new Enemy(8, 4, 1);
				enemy[1] = new Enemy(16, 3, 1);
				enemy[2] = new Enemy(16, 3, 1);
				enemy[3] = new Enemy(16, 3, 1);
				for (int i = 4; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				Scene = 2;
			}
			if (keys[KEY_INPUT_6] == 1 && oldkeys[KEY_INPUT_6] == 0) {
				player = new Player(0, 0, 8, 4);
				enemy[0] = new Enemy(8, 4, 1);
				enemy[1] = new Enemy(8, 4, 1);
				enemy[2] = new Enemy(8, 4, 1);
				enemy[3] = new Enemy(16, 3, 1);
				enemy[4] = new Enemy(16, 3, 1);
				enemy[5] = new Enemy(16, 3, 1);
				for (int i = 6; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				Scene = 2;
			}if (keys[KEY_INPUT_7] == 1 && oldkeys[KEY_INPUT_7] == 0) {
				player = new Player(0, 0, 8, 4);
				enemy[0] = new Enemy(8, 4, 1);
				enemy[1] = new Enemy(16, 3, 1);
				enemy[2] = new Enemy(24, 2, 1);
				for (int i = 3; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				Scene = 2;
			}if (keys[KEY_INPUT_8] == 1 && oldkeys[KEY_INPUT_8] == 0) {
				player = new Player(0, 0, 8, 4);
				enemy[0] = new Enemy(8, 4, 1);
				enemy[1] = new Enemy(8, 4, 1);
				enemy[2] = new Enemy(16, 3, 1);
				enemy[3] = new Enemy(24, 2, 1);
				enemy[4] = new Enemy(24, 2, 1);
				for (int i = 5; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				Scene = 2;
			}if (keys[KEY_INPUT_9] == 1 && oldkeys[KEY_INPUT_9] == 0) {
				player = new Player(0, 0, 8, 4);
				enemy[0] = new Enemy(8, 3, 1);
				enemy[1] = new Enemy(8, 3, 1);
				enemy[2] = new Enemy(16, 2, 1);
				enemy[3] = new Enemy(16, 2, 1);
				enemy[4] = new Enemy(24, 1, 1);
				enemy[5] = new Enemy(24, 1, 1);
				enemy[6] = new Enemy(24, 1, 1);
				for (int i = 7; i < ENEMY_MAX; i++) {
					delete enemy[i];
				}
				Scene = 2;
			}
			break;
		case Play:
			if (keys[KEY_INPUT_R] == 1 && oldkeys[KEY_INPUT_R] == 0) {
				Scene = 1;
			}
			break;
		case result:
			break;
		default:
			break;
		}
		//更新処理
		switch (Scene) {
		case Title:
			break;
		case StageSelect:
			break;
		case Play:
			
			player->update(backgraoud, keys, oldkeys, WIN_WIDTH);
			backgraoud->update(keys, oldkeys, player);
			navi->update(WIN_HEIGHT, WIN_WIDTH, player, goal);
			goal->update(WIN_WIDTH, WIN_HEIGHT, backgraoud, player);
			for (int i = 0; i < ENEMY_MAX; i++) {
				enemy[i]->update(player, backgraoud, keys, oldkeys);
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
			DrawFormatString(0, 0, GetColor(0, 0, 0), "Title");

			break;
		case StageSelect:
			DrawFormatString(0,0,GetColor(0,0,0),"1:(1)");
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
			DrawFormatString(0, 0, GetColor(0, 0, 0), "R ");
			backgraoud->draw();
			//foot->draw();
			navi->draw();
			goal->draw();
			player->draw();
			for (int i = 0; i < ENEMY_MAX; i++) {
				enemy[i]->draw(backgraoud);
			}
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

	delete backgraoud;
	delete player;
	delete foot;
	

	//Dxライブラリ終了処理
	DxLib_End();
	return 0;
}
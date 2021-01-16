#include "DxLib.h"
#include "BackGraoud.h"
#include "Foot.h"
#include"GameObject.h"
#include "Player.h"
#include "Enemy.h"

const char TITLE[] = "クラスでできました〜";

const int WIN_WIDTH = 800; //ウィンドウ横幅
const int WIN_HEIGHT = 450;//ウィンドウ縦幅

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	ChangeWindowMode(TRUE);						//フルスクリーンモードに設定
	//ウィンドウサイズを手動では変更できず、かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetMainWindowText(TITLE);					// タイトルを変更
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);	//画面サイズの最大サイズ、カラービット数を設定（モニターの解像度に合わせる）
	SetWindowSizeExtendRate(1.0);				//画面サイズを設定（解像度との比率で設定）
	SetBackgroundColor(0xf1, 0xf1, 0xf1);		// 画面の背景色を設定する

	//Dxライブラリの初期化
	if (DxLib_Init() == -1) { return -1; }

	//（ダブルバッファ）描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	//画像などのリソースデータの変数宣言と読み込み



	//ゲームループで使う変数の宣言
	char keys[256] = { 0 }; //最新のキーボード情報用
	char oldkeys[256] = { 0 };//1ループ（フレーム）前のキーボード情報
	BackGraoud* backgraoud = new BackGraoud();
	Player* player = new Player(300, 300, 8, 4);
	const int FOOT_MAX = 4;
	Foot* foot = new Foot();
	const int ENEMY_MAX = 3;
	Enemy* enemy[ENEMY_MAX];
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i] = new Enemy(8, 2, 1);
	}
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

		//更新処理
		player->update(keys, oldkeys, WIN_WIDTH);
		backgraoud->update(player);
		for (int i = 0; i < ENEMY_MAX; i++) {
			enemy[i]->update(player,backgraoud, keys, oldkeys);
		}
		foot->visible();
		if (foot->getIsVisible() == 0) {
			foot->prepare(player);
		}
		//描画処理
		backgraoud->draw();
		foot->draw();
		player->draw();
		for (int i = 0; i < ENEMY_MAX; i++) {
			enemy[i]->draw();
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
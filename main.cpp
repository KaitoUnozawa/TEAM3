#include "DxLib.h"
#include "Background.h"
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
#include "Select.h"
#include "Option.h"
#include "SceneTransition.h"
#include "Color.h"


const char TITLE[] = "�~�N���[�Y";

const float WIN_WIDTH = 800.0f; //�E�B���h�E����
const float WIN_HEIGHT = 450.0f;//�E�B���h�E�c��

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	ChangeWindowMode(0);						//�t���X�N���[�����[�h�ɐݒ�
	//�E�B���h�E�T�C�Y���蓮�ł͕ύX�ł����A���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetMainWindowText(TITLE);					// �^�C�g����ύX
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);	//��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�i���j�^�[�̉𑜓x�ɍ��킹��j
	SetWindowSizeExtendRate(1.0);				//��ʃT�C�Y��ݒ�i�𑜓x�Ƃ̔䗦�Őݒ�j
	SetBackgroundColor(200, 200, 200);		// ��ʂ̔w�i�F��ݒ肷��

	//Dx���C�u�����̏�����
	if (DxLib_Init() == -1) { return -1; }

	//�i�_�u���o�b�t�@�j�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	//�摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���



	//�Q�[�����[�v�Ŏg���ϐ��̐錾
	char keys[256] = { 0 }; //�ŐV�̃L�[�{�[�h���p
	char oldkeys[256] = { 0 };//1���[�v�i�t���[���j�O�̃L�[�{�[�h���
	int Scene = 0;
	Opening* opening = new Opening();
	Option* option = new Option();
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
		enemy[i] = new Enemy(8, 2, 1,0);
	}
	enemy[0]->setActivate(1);
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

	Select* select[10];
	for (int i = 0; i < 10; i++) {
		select[i] = new Select();
	}

	SceneTransition* scene_transition = new SceneTransition;
	Color* color = new Color;

	int resetFlag = 0;

	// �Q�[�����[�v
	while (1) {
		//�ŐV�̃L�[�{�[�h��񂾂������̂͂P�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; i++) {
			oldkeys[i] = keys[i];
		}
		//�ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);
		//��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//
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
			if (keys[KEY_INPUT_T] == 1){
				background = new Background();
				Scene = Title;
				opening->setIsNextstage(0);
			}
			break;
		case End:
			break;

		case StageSelect:
			if (keys[KEY_INPUT_1] == 1 && oldkeys[KEY_INPUT_1] == 0) {
				background = new Background();
				player = new Player(8, 4);
				navi = new Navi();
				goal = new Goal();
				enemy[0] = new Enemy(8, 2, 1, 1);
				enemy[1] = new Enemy(8, 2, 1, 1);
				Scene = Play;
			}
			
			break;
		case Play:
			if (CheckHitKey(KEY_INPUT_C) == 1) {
				Scene = StageSelect;
			}

			break;
		case result:
			break;
		default:
			break;
		}
		//�X�V����
		switch (Scene) {
		case Title:
			shake->shaking();
			player->update(*enemy, background, easing, keys, oldkeys, WIN_WIDTH,option);
			background->update(keys, oldkeys, player, easing);
			enemy[0]->update(*enemy, player, shake, background, keys, oldkeys,option);
			opening->collide(player);
			opening->update(keys, oldkeys);
			for (int i = 0; i < ENEMY_MAX; i++) {
				for (int j = 0; j < PARTI_MAX; j++) {
					particle[i][j]->activate(player, enemy[i]);
				}
			}
			for (int i = 0; i < ENEMY_MAX; i++) {
				for (int j = 0; j < PARTI_MAX; j++) {
					particle[i][j]->update(player, easing);
				}
			}
			break;
		case Option:
			option->update(keys, oldkeys, player);
			break;
		case End:
			break;
		case StageSelect:
			scene_transition->decrease(player, easing);
			for (int i = 0; i < 1; i++) {
				select[i]->update(scene_transition, easing, color, i);
			}
			break;
		case Play:
			player->update(*enemy, background, easing, keys, oldkeys, WIN_WIDTH, option);
			background->update(keys, oldkeys, player, easing);
			navi->update(WIN_HEIGHT, WIN_WIDTH, player, goal, background);
			goal->update(WIN_WIDTH, WIN_HEIGHT, background, player, *enemy);
			shake->shaking();
			for (int i = 0; i < ENEMY_MAX; i++) {
				enemy[i]->update(*enemy, player, shake, background, keys, oldkeys, option);
			}
			for (int i = 0; i < ENEMY_MAX; i++) {
				for (int j = 0; j < PARTI_MAX; j++) {
					particle[i][j]->activate(player, *enemy);
				}
			}
			for (int i = 0; i < ENEMY_MAX; i++) {
				for (int j = 0; j < PARTI_MAX; j++) {
					particle[i][j]->update(player, easing);
				}
			}
			if (goal->getIsClear() == 1) {
				//if (Stage&one) {
				background = new Background();
				player = new Player(8, 4);
				navi = new Navi();
				goal = new Goal();
				enemy[0] = new Enemy(8, 3, 1, 1);
				enemy[1] = new Enemy(8, 3, 1, 1);
				enemy[2]->setActivate(1);
				goal->setIsClear(0);
				//}
			}
			break;
		case result:
			break;
		default:
			break;
		}
		//�`�揈��
		switch (Scene) {
		case Title:
			background->draw(shake, color);
			enemy[0]->draw(shake, color);
			opening->draw(shake, color);
			player->draw(*enemy, shake, color);
			player->drawEffect();
			for (int i = 0; i < ENEMY_MAX; i++) {
				for (int j = 0; j < PARTI_MAX; j++) {
					particle[i][j]->draw(color, shake);
				}
			}
			break;
		case Option:
			option->draw();
			background->draw(shake, color);
			break;
		case End:
			ChangeFontType(DX_FONTTYPE_ANTIALIASING);
			SetFontSize(25);
			DrawString(
				0,
				0,
				"PUSH Esc", GetColor(0, 0, 0));
			break;
		case StageSelect:
			for (int i = 0; i < 10; i++) {
				select[i]->draw();
			}
			scene_transition->draw(color);
			break;

		case Play:
			background->draw(shake, color);
			navi->draw();
			goal->draw(shake, color);
			player->draw(*enemy, shake, color);
			player->drawEffect();
			for (int i = 0; i < ENEMY_MAX; i++) {
				enemy[i]->draw(shake, color);
			}

			for (int i = 0; i < ENEMY_MAX; i++) {
				for (int j = 0; j < PARTI_MAX; j++) {
					particle[i][j]->draw(color, shake);
				}
			}

			break;

		case result:
			break;

		default:
			break;
		}

		//---------  �����܂łɃv���O�������L�q  ---------//
		ScreenFlip();//�i�_�u���o�b�t�@�j����
		// 20�~���b�ҋ@�i�^��60FPS�j
		WaitTimer(20);
		// Windows �V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}
		// �d�r�b�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	//Dx���C�u�����I������
	DxLib_End();
	return 0;
}
#include "DxLib.h"
#include "BackGraoud.h"
#include "Foot.h"
#include"GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Navi.h"
#include "Goal.h"

const char TITLE[] = "�N���X�łł��܂����`";

const int WIN_WIDTH = 800; //�E�B���h�E����
const int WIN_HEIGHT = 450;//�E�B���h�E�c��

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	ChangeWindowMode(1);						//�t���X�N���[�����[�h�ɐݒ�
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
		//�X�V����
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
		//�`�揈��
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

	delete backgraoud;
	delete player;
	delete foot;
	

	//Dx���C�u�����I������
	DxLib_End();
	return 0;
}
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
	BackGraoud* backgraoud = new BackGraoud();
	Player* player = new Player(300, 300, 8, 4);
	const int FOOT_MAX = 4;
	Foot* foot = new Foot();

	const int ENEMY_MAX = 10;
	Enemy* enemy[ENEMY_MAX];
	for (int i = 0; i < ENEMY_MAX; i++) {
		enemy[i] = new Enemy(8, 2, 1);
	}

	Navi* navi = new Navi();
	Goal* goal = new Goal();
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


		//�X�V����
		player->update(backgraoud, keys, oldkeys, WIN_WIDTH);
		backgraoud->update(keys, oldkeys, player);
		navi->update(WIN_HEIGHT, WIN_WIDTH, player,goal);
		goal->update(WIN_WIDTH,WIN_HEIGHT,backgraoud, player);
		for (int i = 0; i < ENEMY_MAX; i++) {
			enemy[i]->update(player,backgraoud, keys, oldkeys);
		}
		foot->visible();
		if (foot->getIsVisible() == 0) {
			foot->prepare(backgraoud);
		}
		//�`�揈��
		backgraoud->draw();
		foot->draw();
		navi->draw();
		goal->draw();
		player->draw();
		for (int i = 0; i < ENEMY_MAX; i++) {
			enemy[i]->draw();
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
	delete enemy;

	//Dx���C�u�����I������
	DxLib_End();
	return 0;
}
#include "BackGraoud.h"
#include "DxLib.h"
int BackGraoud::getMoveFlag() { return moveFlag; }
void BackGraoud::update(Player* player) {
    BackGraoud::move(player);
}
void BackGraoud::move(Player* player) {
    if (player->getPosX()>600&&moveX>-1600) {
        moveFlag = -1;
        player->setPosX(600);
        moveX-=4;
    } else {
        moveFlag = 0;
    }
    if (player->getPosX() < 200&&moveX<=0) {
        moveFlag = -1;
        player->setPosX(200);
        moveX+=4;
    } else {
        moveFlag = 0;
    }
    if (player->getPosY() > 290&&moveY>-900) {
        moveFlag = 1;
        player->setPosY(290);
        moveY-=4;
    }else {
        moveFlag = 0;
    }
    if (player->getPosY() < 110&& moveY <= 0) {
        moveFlag = 1;
        player->setPosY(110);
        moveY += 4;
    } else {
        moveFlag = 0;
    }
}

void BackGraoud::draw() {
    const int BLACK = GetColor(150, 150, 150);
    const int BACK_LENGTH = 32;
    //DrawFormatString(0, 0, GetColor(0, 0, 0), "%d", moveFlag);
    // îwåi
    // èc
    for (posX = BACK_LENGTH; posX < 2400; posX += BACK_LENGTH) {
        DrawLine(posX+moveX, 0, posX+moveX, 2400, BLACK);
    }
    // â°
    for (posY = BACK_LENGTH; posY < 1350; posY += BACK_LENGTH) {
        DrawLine(0, posY+moveY, 1350, posY+moveY, BLACK);
    }
}
#include "BackGraoud.h"
#include "DxLib.h"
int BackGraoud::getMoveFlag() { return moveFlag; }
BackGraoud::BackGraoud() {
    worldX=0, worldY=200;
    scrollX=0, scrollY=0;
    //moveX, moveY;
    startX=400, startY=300;
}
void BackGraoud::update(char keys[255], char oldkeys[255], Player* player) {
    BackGraoud::move(keys,oldkeys,player);
}
void BackGraoud::move(char keys[255], char oldkeys[255],Player* player) {
    player->setPosX(worldX-scrollX);
    player->setPosY(worldY - scrollY);
    if (keys[KEY_INPUT_RIGHT] == 1) {
        worldX += 4;
        if (worldX >= startX) {
            scrollX += 4;
        }
    }
    if (keys[KEY_INPUT_LEFT] == 1) {
        worldX -= 4;
        if (scrollY<0) {
            scrollX -= 4;
        }
    }
    if (keys[KEY_INPUT_UP] == 1) {
        if (worldY > 0) {
            worldY -= 4;
        }
        if (scrollY < 0) {
            scrollY = 0;
        } else {
            scrollY -= 4;
        }
    }
    if (keys[KEY_INPUT_DOWN] == 1) {
        if (worldY < 1350) {
            worldY += 4;
        }
        if (worldY >= startY&&scrollY<900) {
            scrollY += 4;
        }
    }
}

void BackGraoud::draw() {
    const int BLACK = GetColor(150, 150, 150);
    const int BACK_LENGTH = 32;
    //DrawFormatString(0, 0, GetColor(0, 0, 0), "%d", moveFlag);
    // ”wŒi
    // c
    for (int i = 0; i < 75;i++) {
        DrawLine(-scrollX+(i*32), 0, -scrollX + (i * 32), 1350, BLACK);
    }
    for (int i = 0; i < 43; i++) {
        DrawLine(0,-scrollY + (i * 32),2400, -scrollY + (i * 32), BLACK);
    }
}
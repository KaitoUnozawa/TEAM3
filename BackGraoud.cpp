#include "BackGraoud.h"
#include "DxLib.h"
int BackGraoud::getMoveFlag() { return moveFlag; }
float BackGraoud::getWorldX() { return worldX; }
float BackGraoud::getWorldY() { return worldY; }
float BackGraoud::getScrollX() { return scrollX; }
float BackGraoud::getScrollY() { return scrollY; }
BackGraoud::BackGraoud() {
    worldX=800, worldY=425;
    scrollX=400, scrollY=225;
    startX=600, startY=400;
    moveFlag = 0;
}
void BackGraoud::update(char keys[255], char oldkeys[255], Player* player) {
    BackGraoud::move(keys,oldkeys,player);
}
void BackGraoud::move(char keys[255], char oldkeys[255],Player* player) {
    player->setPosX(worldX - scrollX);
    player->setPosY(worldY - scrollY);
    if (keys[KEY_INPUT_RIGHT] == 1) {
        if (worldX < 2392) {
            if (worldX-scrollX > startX && scrollX < 1600) {
                moveFlag = -1;
                scrollX += 4;
            }
            worldX += 4;
        }
    } else {
        moveFlag = 0;
    }
    if (keys[KEY_INPUT_LEFT] == 1) {
        if (worldX > 8) {
            if (worldX - scrollX < startX-500 && scrollX > 0) {
                moveFlag = -1;
                scrollX -= 4;
            }
            worldX -= 4;
        }
    } else {
        moveFlag = 0;
    }
    if (keys[KEY_INPUT_UP] == 1) {
        if (worldY > 8) {
            if (worldY - scrollY < startY-350 && scrollY > 0) {
                moveFlag = 1;
                scrollY -= 4;
            }
            worldY -= 4;
        }
 } else {
        moveFlag = 0;
    }
    if (keys[KEY_INPUT_DOWN] == 1) {
        if (worldY < 1342) {
            if (worldY - scrollY > startY && scrollY < 900) {
                moveFlag = 1;
                scrollY += 4;
            }
            worldY += 4;
        }
    } else {
        moveFlag = 0;
    }
}

void BackGraoud::draw() {
    const int BLACK = GetColor(150, 150, 150);
    const int BACK_LENGTH = 32;
    // �w�i
    // �c
    for (int i = 0; i < 75;i++) {
        DrawLine(-scrollX+(i*32), 0, -scrollX + (i * 32), 1350, BLACK);
    }
    for (int i = 0; i < 43; i++) {
        DrawLine(0,-scrollY + (i * 32),2400, -scrollY + (i * 32), BLACK);
    }
}
#pragma once
#include "InputHandler.h"
#include "Player.h"
#include "Command.h"

class StageScene {
private:
    // 資料に基づいたメンバ変数
    InputHandler *inputHandler_ = nullptr;
    ICommand *iCommand_ = nullptr;
    Player *player_ = nullptr;

public:
    void Init ();
    void Update ();
    void Draw ();
};


#include "StageScene.h"

StageScene::~StageScene () {
	delete inputHandler_;
	delete player_;
}

void StageScene::Init () {
	// 1. 各クラスのインスタンスを生成
	inputHandler_ = new InputHandler ();
	player_ = new Player ();

	// 2. キーに対してコマンドを割り当てる
	inputHandler_->AssignMoveRightCommand2PressKeyD ();
	inputHandler_->AssignMoveLeftCommand2PressKeyA ();
}

void StageScene::Update () {
	// 3. 入力からコマンドを取得
	// ※InputHandler側の関数名が「HandlerInput」なら名前に注意！
	iCommand_ = inputHandler_->HandlerInput ();

	// 4. コマンドがあれば実行する
	if (iCommand_) {
		iCommand_->Exec (*player_); // 前回の「Exce」を「Exec」に直しておきましょう
	}

	// 5. プレイヤー自身の更新処理
	player_->Update ();
}

void StageScene::Draw () {
	player_->Draw ();
}

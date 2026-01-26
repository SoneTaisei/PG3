#include "InputHandle.h"
#include "Novice.h"

ICommand *InputHandle::HandleInput () {
	if (Novice::CheckHitKey (DIK_D)) {
		return pressKeyD_;
	}
	return nullptr;
}

void InputHandle::AssignMoveLeftCommand2PressKeyA () {
	ICommand *command = new MoveLeftCommand ();
	this->pressKeyA_ = command;
}

void InputHandle::AssignMoveRightCommand2PressKeyD () {
	ICommand *command = new MoveRightCommand ();
	this->pressKeyD_ = command;
}

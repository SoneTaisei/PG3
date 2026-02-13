#include "InputHandler.h"
#include "Novice.h"

InputHandler::~InputHandler () {
	delete pressKeyD_;
	delete pressKeyA_;
}

void InputHandler::AssignMoveLeftCommand2PressKeyA () {
	ICommand *command = new MoveLeftCommand ();
	this->pressKeyA_ = command;
}

void InputHandler::AssignMoveRightCommand2PressKeyD () {
	ICommand *command = new MoveRightCommand ();
	this->pressKeyD_ = command;
}

ICommand *InputHandler::HandlerInput () {
	if (Novice::CheckHitKey (DIK_D)) {
		return pressKeyD_;
	}

	if (Novice::CheckHitKey (DIK_A)) {
		return pressKeyA_;
	}

	return nullptr;
}

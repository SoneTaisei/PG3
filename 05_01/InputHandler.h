#pragma once
#include "Command.h"
class InputHandler {
public:
	ICommand *HandlerInput ();
	~InputHandler ();

	void AssignMoveLeftCommand2PressKeyA ();
	void AssignMoveRightCommand2PressKeyD ();

private:
	ICommand *pressKeyD_ = nullptr;
	ICommand *pressKeyA_ = nullptr;
};


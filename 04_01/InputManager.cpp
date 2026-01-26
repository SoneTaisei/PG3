#include "InputManager.h"
#include <cstring> // memcpy用

InputManager* InputManager::GetInstance() {
	static InputManager instance;
	return &instance;
}

void InputManager::Update() {
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);
}

bool InputManager::IsKeyPressed(int key) const {
	return keys_[key];
}

bool InputManager::IsKeyTriggered(int key) const {
	return keys_[key] && !preKeys_[key];
}
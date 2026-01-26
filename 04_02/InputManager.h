#pragma once
#include <Novice.h>

class InputManager {
public:
	// シングルトンインスタンスを取得
	static InputManager* GetInstance();

	void Update();
	bool IsKeyPressed(int key) const; // キーが押されているか
	bool IsKeyTriggered(int key) const; // キーが押された瞬間か

private:
	InputManager() = default;
	~InputManager() = default;
	InputManager(const InputManager&) = delete;
	InputManager& operator=(const InputManager&) = delete;

	char keys_[256] = {0};
	char preKeys_[256] = {0};
};
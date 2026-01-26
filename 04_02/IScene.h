#pragma once

// シーンを識別するためのenum
enum class Scene {
	TITLE,
	STAGE,
	CLEAR
};

class IScene {
protected:
	// 次に遷移するシーンを保持する静的メンバ変数
	// これにより、どのシーンからでも次のシーンを指定できる
	static Scene nextScene_;

public:
	virtual ~IScene() = default;
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	// 次のシーン番号を返す
	Scene GetNextScene() const { return nextScene_; }
};
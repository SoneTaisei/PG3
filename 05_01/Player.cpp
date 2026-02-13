#include "Player.h"
#include "Novice.h"

Player::Player () {
	pos_ = { 640.0f, 360.0f }; // 画面中央など
	speed_ = 5.0f;
}

void Player::Update () {

}

void Player::Draw () {
	Novice::DrawBox (int(pos_.x), int (pos_.y), 50,50, 0.0f, WHITE, kFillModeSolid);
}

void Player::MoveRight () {
	this->pos_.x += this->speed_;
}

void Player::MoveLeft () {
	this->pos_.x -= this->speed_;
}

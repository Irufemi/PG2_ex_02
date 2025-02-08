#include "Player.h"
#include <Novice.h>
#include <math.h>
#include "Enemy.h"

//コンストラクタ
Player::Player() {
	pos_.x = 640.0f;
	pos_.y = 500.0f;
	speed_ = 5.0f;
	velocity_ = { 0 };
	width_ = 30.0f;
	height_ = 30.0f;
	radius_ = 15.0f;
	texture_ = Novice::LoadTexture("white1x1.png");
	bullet_ = new Bullet;
}

//デストラクタ
Player::~Player() {
	Novice::UnloadTexture(texture_);
	delete bullet_;
}

//更新
void Player::Update(char* keys) {

	//キー入力による移動
	KeyMove(keys);

	//弾の発射
	Shot(keys);

	//弾の更新
	bullet_->Update();

}

//描画
void Player::Draw() {

	//弾の描画
	bullet_->Draw();

	//自機の描画
	if (isAlive_) {
		Novice::DrawQuad(
			static_cast<int>(pos_.x - width_ / 2.0f), static_cast<int>(pos_.y - height_ / 2.0f),
			static_cast<int>(pos_.x + width_ / 2.0f), static_cast<int>(pos_.y - height_ / 2.0f),
			static_cast<int>(pos_.x - width_ / 2.0f), static_cast<int>(pos_.y + height_ / 2.0f),
			static_cast<int>(pos_.x + width_ / 2.0f), static_cast<int>(pos_.y + height_ / 2.0f),
			0, 0,
			static_cast<int>(width_), static_cast<int>(height_),
			texture_,
			0xFFFFFFFF
		);
	}

}

//弾の発射
void Player::Shot(char* keys) {
	//SPACEキーが押されたら弾を生成する
	if (keys[DIK_SPACE]) {
		bullet_->Create();
	}

	//生成されている弾の更新
	bullet_->Update();
}

//キー入力による移動
void Player::KeyMove(char* keys) {
	if (keys[DIK_W]) {
		vector_.x = 0.0f;
		vector_.y = -1.0f;
		if (keys[DIK_A]) {
			vector_.x = -1.0f / sqrtf(2.0f);
			vector_.y = -1.0f / sqrtf(2.0f);
		}
		else if (keys[DIK_D]) {
			vector_.x = 1.0f / sqrtf(2.0f);
			vector_.y = -1.0f / sqrtf(2.0f);
		}
	}
	else if (keys[DIK_S]) {
		vector_.x = 0.0f;
		vector_.y = 1.0f;
		if (keys[DIK_A]) {
			vector_.x = -1.0f / sqrtf(2.0f);
			vector_.y = 1.0f / sqrtf(2.0f);
		}
		else if (keys[DIK_D]) {
			vector_.x = 1.0f / sqrtf(2.0f);
			vector_.y = 1.0f / sqrtf(2.0f);
		}
	}
	else if (keys[DIK_A]) {
		vector_.x = -1.0f;
		vector_.y = 0.0f;
	}
	else if (keys[DIK_D]) {
		vector_.x = 1.0f;
		vector_.y = 0.0f;
	}
	else {
		vector_.x = 0.0f;
		vector_.y = 0.0f;
	}

	velocity_.x = speed_ * vector_.x;
	velocity_.y = speed_ * vector_.y;

	pos_.x += velocity_.x;
	pos_.y += velocity_.y;

}

//衝突処理
void Player::isHit(Enemy* enemy) {
	
	//敵に当たったら死亡する
	if (isAlive_) {
		for (int j = 0; j < 10; j++) {
			if (enemy->GetIsAlive(j) == true) {
				if (sqrtf(powf(enemy->GetPos(j).x - pos_.x, 2.0f) + powf(enemy->GetPos(j).y - pos_.y, 2.0f)) <= radius_ + enemy->GetRadius()) {
					//生存フラグをfalseにする
					isAlive_ = false;
					//当たった弾も消去する
					enemy->SetIsDead(j);
				}
			}
		}
	}

	bullet_->isHit(enemy);

}
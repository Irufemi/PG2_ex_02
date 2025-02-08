#include "Enemy.h"

#include <Novice.h>

//コンストラクタ
Enemy::Enemy() {
	for (int i = 0; i < 5; i++) {

		//中心の位置。座標。
		pos_[i].x = 640.0f;

		pos_[i].y = 25.0f + 50.0f * i;

		//向き
		vector_[i] = { 0 };

		//速度
		velocity_[i] = { 0 };

		//生きているか
		isAlive_[i] = { 0 };
	}

	//自速
	speed_ = 5.0f;

	//半径
	radius_ = 20.0f;

	respawnTime_ = 120;
}

//デストラクタ
Enemy::~Enemy() {


}
//更新
void Enemy::Update() {

	Respawn();

	AutoMove();
}

//描画
void Enemy::Draw() {

	for (int i = 0; i < 5; i++) {
		if (isAlive_[i]) {
			Novice::DrawEllipse(
				static_cast<int>(pos_[i].x), static_cast<int>(pos_[i].y),
				static_cast<int>(radius_), static_cast<int>(radius_), 0.0f,
				0xFFFFFFFF, kFillModeSolid
			);
		}
	}

}

//自動移動
void Enemy::AutoMove() {
	for (int i = 0; i < 5; i++) {
		if (isAlive_[i]) {
			//速度を計算
			velocity_[i].x = vector_[i].x * speed_;
			velocity_[i].y = vector_[i].y * speed_;
			//座標に速度を反映
			pos_[i].x += velocity_[i].x;
			pos_[i].y += velocity_[i].y;
			//画面外に行きそうになった時に反転する
			if (pos_[i].x - radius_ <= 0.0f) {
				vector_[i].x *= -1;
			}
			else if (pos_[i].x + radius_ >= 1280.0f) {
				vector_[i].x *= -1;
			}
		}
	}

}

//リスポーン処理
void Enemy::Respawn() {
	respawnTime_--;

	if (respawnTime_ <= 0) {
		for (int i = 0; i < 5; i++) {
			if (isAlive_[i] == false) {
				pos_[i].x = 640.0f;

				vector_[i].x = 1.0f;
				vector_[i].y = 0.0f;

				isAlive_[i] = true;

				respawnTime_ = 120;

				break;
			}
		}
	}

}
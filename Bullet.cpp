#include "Bullet.h"

#include <Novice.h>
#include <math.h>
#include "Enemy.h"

//コンストラクタ
Bullet::Bullet() {
	for (int i = 0; i < 20; i++) {
		pos_[i] = { 0 };
		vector_[i] = { 0 };
		velocity_[i] = { 0 };
		isShoot_[i] = { 0 };
	}
	speed_ = 5.0f;
	radius_ = 10.0f;
	shotCoolTime_ = 30;
}

//デストラクタ
Bullet::~Bullet() {

}

//更新
void Bullet::Update() {

	//移動処理
	Move();

	//画面範囲外に行ったら消滅
	for (int i = 0; i < 20; i++) {
		if (isShoot_[i]) {
			if (pos_[i].y + radius_ <= 0) {
				isShoot_[i] = false;
			}
		}
	}

}

//描画
void Bullet::Draw() {
	for (int i = 0; i < 20; i++) {
		if (isShoot_[i]) {
			Novice::DrawEllipse(
				static_cast<int>(pos_[i].x), static_cast<int>(pos_[i].y),
				static_cast<int>(radius_), static_cast<int>(radius_), 0.0f,
				0xFFFFFFFF, kFillModeSolid
			);
		}
	}
}

//生成
void Bullet::Create(Vector2<float> pos, char* keys) {
	shotCoolTime_--;

	//クールタイムがなくなった時
	if (shotCoolTime_ <= 0) {
		//SPACEキーが押されたら弾を生成する
		if (keys[DIK_SPACE]) {
			for (int i = 0; i < 20; i++) {
				//発射されていない弾を１つ発射する
				if (isShoot_[i] == false) {

					//発射される位置は参照の座標を用いる
					pos_[i].x = pos.x;
					pos_[i].y = pos.y;

					//発射されている状態にする
					isShoot_[i] = true;

					//クールタイムをリセットする
					shotCoolTime_ = 30;

					//１発だけなのでbreakで抜ける
					break;
				}
			}
		}
	}

}

//移動
void Bullet::Move() {
	for (int i = 0; i < 20; i++) {
		if (isShoot_[i] == true) {
			//向きを設定
			vector_[i].x = 0.0f;
			vector_[i].y = -1.0f;
			//速度を計算
			velocity_[i].x = speed_ * vector_[i].x;
			velocity_[i].y = speed_ * vector_[i].y;
			//座標に速度を反映
			pos_[i].x += velocity_[i].x;
			pos_[i].y += velocity_[i].y;
		}
	}
}

//衝突処理
void Bullet::isHit(Enemy* enemy) {
	for (int i = 0; i < 20; i++) {
		if (isShoot_[i] == true) {
			for (int j = 0; j < 5; j++) {
				if (enemy->GetIsAlive(j) == true) {
					if (sqrtf(powf(enemy->GetPos(j).x - pos_[i].x, 2.0f) + powf(enemy->GetPos(j).y - pos_[i].y, 2.0f)) <= radius_ + enemy->GetRadius()) {
						isShoot_[i] = false;
						enemy->SetIsDead(j);
					}
				}
			}
		}
	}
}
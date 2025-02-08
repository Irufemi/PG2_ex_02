#include "Bullet.h"

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
	shotCoolTime_ = 30;
}

//デストラクタ
Bullet::~Bullet() {

}

//更新
void Bullet::Update() {

}

//描画
void Bullet::Draw() {

}

//生成
void Bullet::Create() {

}

//移動
void Bullet::Move() {

}

//衝突処理
void Bullet::isHit(Enemy* enemy) {
	for (int i = 0; i < 20; i++) {
		if(isShoot_[i] == true) {
			for (int j = 0; j < 10; j++) {
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
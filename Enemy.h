#pragma once

#include "Vector2.h"

class Enemy {
protected: //メンバ変数
	//中心の位置。座標。
	Vector2 <float> pos_[10];

	//自速
	float speed_;

	//向き
	Vector2<float> vector_[10];

	//速度
	Vector2<float> velocity_[10];

	//半径
	float radius_;

	//生きているか
	bool isAlive_[10];

public: //メンバ関数

	//コンストラクタ
	Enemy();

	//デストラクタ
	~Enemy();

	//セッター
	void SetIsDead(int index) { this->isAlive_[index] = false; }

	//ゲッター
	Vector2 <float> GetPos(int index) { return pos_[index]; }
	float GetRadius() { return radius_; }
	bool GetIsAlive(int index) { return isAlive_[index]; }

	//更新
	void Update();

	//描画
	void Draw();

	//自動移動
	void AutoMove();

	//リスポーン処理
	void Respawn();
};
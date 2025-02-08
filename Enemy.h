#pragma once

#include "Vector2.h"

class Enemy {
protected: //メンバ変数
	//中心の位置。座標。
	Vector2 <float> pos_[5];

	//自速
	float speed_;

	//向き
	Vector2<float> vector_[5];

	//速度
	Vector2<float> velocity_[5];

	//半径
	float radius_;

	//生きているか
	bool isAlive_[5];

	//リスポーンまでの時間
	int respawnTime_;

	//倒された数
	int breakCount_;

public: //メンバ関数

	//コンストラクタ
	Enemy();

	//デストラクタ
	~Enemy();

	//セッター
	void SetIsDead(int index) { this->isAlive_[index] = false; }

	//倒された回数を１増やす
	void AddBreakCount() { this->breakCount_ += 1; }

	//ゲッター
	Vector2 <float> GetPos(int index) { return pos_[index]; }
	float GetRadius() { return radius_; }
	bool GetIsAlive(int index) { return isAlive_[index]; }
	int GetBreakCount() { return breakCount_; }

	//更新
	void Update();

	//描画
	void Draw();

	//自動移動
	void AutoMove();

	//リスポーン処理
	void Respawn();
};
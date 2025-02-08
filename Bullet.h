#pragma once
#include "Vector2.h"

//多重定義を防ぐために前方宣言

class Enemy;

class Bullet {
protected: //メンバ変数

	//弾は最大20発撃てるように配列を用意する
	//時間があればvectorでの情報保存での任意消去が楽かも？

	//中心の位置。座標。
	Vector2 <float> pos_[20];
	//自速
	float speed_;
	//向き
	Vector2 <float> vector_[20];
	//速度
	Vector2<float> velocity_[20];
	//半径
	float radius_;
	//発射されているか
	bool isShoot_[20];
	//次弾が発射されるまでのクールタイム
	int shotCoolTime_;

public: //メンバ関数
	//コンストラクタ
	Bullet();
	//デストラクタ
	~Bullet();
	//セッター

	//ゲッター
	Vector2<float> GetPos(int index) { return pos_[index]; }
	//更新
	void Update();
	//描画
	void Draw();
	//生成
	void Create();
	//移動
	void Move();
	//衝突処理
	void isHit(Enemy* enemy);
};


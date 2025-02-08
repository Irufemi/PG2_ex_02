#pragma once
#include "Vector2.h"
#include "Bullet.h"

//多重定義を防ぐために前方宣言

class Enemy;

class Player{
protected: //メンバ変数
	//中心の位置。座標。
	Vector2<float> pos_;
	//自速
	float speed_;
	//向き
	Vector2<float> vector_;
	//速度
	Vector2<float> velocity_;
	//横幅
	float width_;
	//高さ
	float height_;
	//当たり判定の半径
	float radius_;
	//画像
	int texture_;
	//生きているか
	bool isAlive_;
	//弾
	Bullet *bullet_;
public: //メンバ関数
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();
	//セッター
	
	//ゲッター
	Vector2 <float> GetBulletPos(int index) { return bullet_->GetPos(index); }
	//更新
	void Update(char* keys);
	//描画
	void Draw();
	//弾の発射
	void Shot(char* keys);
	//キー入力による移動
	void KeyMove(char *keys);
	//衝突処理
	void isHit(Enemy *enemy);
};


#pragma once

class Player{
protected: //メンバ変数
	Vector2
public: //メンバ関数
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();
	//更新
	void Update();
	//描画
	void Draw();
	//弾の発射
	void Shot();
	//キー入力による移動
	void KeyMove(char *keys);
};


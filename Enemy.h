#pragma once
class Enemy{
protected: //メンバ変数

public: //メンバ関数
	//コンストラクタ
	Enemy();
	//デストラクタ
	~Enemy();
	//更新
	void Update();
	//描画
	void Draw();
	//自動移動
	void AutoMove();
	//リスポーン処理
	void Respawn();
};


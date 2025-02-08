#include "InGameScene.h"

#include "Scene.h"

#include "Player.h"
#include "Enemy.h"

#include <Novice.h>




InGameScene::InGameScene() {

	player_ = new Player();

	enemy_ = new Enemy();

	// シーン変更フラグの初期化
	flag_ = false;
}

InGameScene::~InGameScene() {

	delete player_;

	delete enemy_;

}

// ゲームシーンの更新
void InGameScene::Update(SceneManager& sceneManager) {

	//自機と弾の更新
	player_->Update(keys_);

	//敵の更新
	enemy_->Update();

	//弾と自機と敵の当たり判定
	player_->isHit(enemy_);

	// 何らかの条件でシーンを切り替える
	if (flag_) {
		sceneManager.SetChangeFlag(SceneName::TITLE);
	}

}

// ゲームシーンの描画
void InGameScene::Render() {

	//敵の描画
	enemy_->Draw();

	//自機と弾の描画
	player_->Draw();

}

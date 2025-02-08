#include "InGameScene.h"

#include "Scene.h"

#include "Player.h"
#include "Enemy.h"

#include <Novice.h>




InGameScene::InGameScene() {

	player_ = new Player();

	enemy_ = new Enemy();

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

	//敵を目標数倒したときにClearSceneに切り替える
	if (enemy_->GetBreakCount() >= 10) {
		sceneManager.SetChangeFlag(SceneName::CLEAR);
	}

	// 自機が死亡したときにGameOverSceneに切り替える
	if (player_->GetIsAlive() == false) {
		sceneManager.SetChangeFlag(SceneName::GAMEOVER);
	}

}

// ゲームシーンの描画
void InGameScene::Render() {

	//敵の描画
	enemy_->Draw();

	//自機と弾の描画
	player_->Draw();

	//敵を撃破した数と目標数を / で仕切って表示する
	Novice::ScreenPrintf(5, 5, "Enemy Break Count : %d / 10", enemy_->GetBreakCount());

}

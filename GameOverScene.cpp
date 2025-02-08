#include "GameOverScene.h"
#include "Scene.h"
#include <iostream>

#include <Novice.h>



GameOverScene::GameOverScene() {

}
GameOverScene::~GameOverScene() {

}


// タイトルシーンの更新メソッドの実装
void GameOverScene::Update(SceneManager& sceneManager) {


	// 何らかの条件でシーンを切り替える
	if (preKeys_[DIK_SPACE] == 0 && keys_[DIK_SPACE] != 0) {
		sceneManager.SetChangeFlag(SceneName::TITLE);
	}
}

// タイトルシーンの描画メソッドの実装
void GameOverScene::Render() {
	Novice::ScreenPrintf(620, 300, "GAME OVER...");
	Novice::ScreenPrintf(600, 500, "Push to SPACE");
}
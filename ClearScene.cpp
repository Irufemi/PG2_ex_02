#include "ClearScene.h"
#include "Scene.h"
#include <iostream>

#include <Novice.h>



ClearScene::ClearScene() {

}
ClearScene::~ClearScene() {

}


// タイトルシーンの更新メソッドの実装
void ClearScene::Update(SceneManager& sceneManager) {


	// 何らかの条件でシーンを切り替える
	if (preKeys_[DIK_SPACE] == 0 && keys_[DIK_SPACE] != 0) {
		sceneManager.SetChangeFlag(SceneName::TITLE);
	}
}

// タイトルシーンの描画メソッドの実装
void ClearScene::Render() {
	Novice::ScreenPrintf(620, 300, "GAME CLEAR!!");
	Novice::ScreenPrintf(600, 500, "Push to SPACE");
}
#include "TitleScene.h"
#include "Scene.h"
#include <iostream>

#include <Novice.h>



TitleScene::TitleScene() {

}
TitleScene::~TitleScene() {

}


// タイトルシーンの更新メソッドの実装
void TitleScene::Update(SceneManager& sceneManager) {
	

	// 何らかの条件でシーンを切り替える
	if (preKeys_[DIK_SPACE] == 0 && keys_[DIK_SPACE] != 0) {
		sceneManager.SetChangeFlag(SceneName::INGAME);
	}
}

// タイトルシーンの描画メソッドの実装
void TitleScene::Render() {
	Novice::ScreenPrintf(620, 300, "AL2_ex_02");
	Novice::ScreenPrintf(600, 500, "Push to SPACE");
}
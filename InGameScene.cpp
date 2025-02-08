#include "InGameScene.h"
#include "Scene.h"

#include <Novice.h>




InGameScene::InGameScene() {


	// シーン変更フラグの初期化
	flag_ = false;
}

InGameScene::~InGameScene() {
	
}

// ゲームシーンの更新
void InGameScene::Update(SceneManager& sceneManager) {


	// 何らかの条件でシーンを切り替える
	if (flag_) {
		sceneManager.SetChangeFlag(SceneName::TITLE);
	}

}

// ゲームシーンの描画
void InGameScene::Render() {

	

}

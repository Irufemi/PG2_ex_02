#include "Scene.h"
#include "TitleScene.h"
#include "InGameScene.h"

// コンストラクタの実装
SceneManager::SceneManager() : changeFlag(false), nextScene(SceneName::TITLE) {
    // 初期シーンを設定
    ChangeScene(SceneName::TITLE);

}

// シーンを変更するメソッドの実装
void SceneManager::ChangeScene(SceneName sceneName) {
    // 現在のシーンを保存
    currentScene = sceneName;

    // シーンのインスタンスを作成
    switch (sceneName) {
    case SceneName::TITLE:
        currentSceneInstance = std::make_unique<TitleScene>();
        break;
    case SceneName::INGAME:
        currentSceneInstance = std::make_unique<InGameScene>();
        break;
    }
}

// 現在のシーンを更新するメソッドの実装
void SceneManager::Update() {
    if (currentSceneInstance) {
        currentSceneInstance->Update(*this);  // SceneManagerへの参照を渡す
    }

    // フラグが立っている場合、指定されたシーンに切り替える
    if (changeFlag) {
        ChangeScene(nextScene);
        changeFlag = false;  // フラグをリセット
    }
}

// 現在のシーンを描画するメソッドの実装
void SceneManager::Render() {
    if (currentSceneInstance) {
        currentSceneInstance->Render();
    }
}

// シーン変更フラグを設定するメソッドの実装
void SceneManager::SetChangeFlag(SceneName sceneName) {
    nextScene = sceneName;
    changeFlag = true;
}
#pragma once

#include <memory>

class SceneManager;  // 前方宣言

class Scene {
public: //メンバ変数
    static char keys_[256];  // キー入力の状態を保持する配列
    static char preKeys_[256];  // 前のフレームのキー入力の状態を保持する配列
public: //メンバ関数
    virtual ~Scene() = default;
    virtual void Update(SceneManager& sceneManager) = 0;  // SceneManagerへの参照を受け取る
    virtual void Render() = 0;
};

enum class SceneName {
    TITLE, 
    INGAME,
    CLEAR,
    GAMEOVER
};

class SceneManager {
public:
    SceneManager();  // コンストラクタ
    void ChangeScene(SceneName sceneName);  // シーンを変更するメソッド
    void Update();  // 現在のシーンを更新するメソッド
    void Render();  // 現在のシーンを描画するメソッド
    void SetChangeFlag(SceneName sceneName);  // シーン変更フラグを設定するメソッド

private:
    SceneName currentScene;  // 現在のシーン名
    std::unique_ptr<Scene> currentSceneInstance;  // 現在のシーンのインスタンス
    bool changeFlag;  // シーン変更フラグ
    SceneName nextScene;  // 次のシーン名
};
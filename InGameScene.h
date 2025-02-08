#pragma once
#include "Scene.h"

//多重定義を防ぐために前方宣言

class Player;

class Enemy;

// ゲームシーンのクラス
class InGameScene : public Scene {
protected: //メンバ変数
    Player* player_;
    Enemy* enemy_;
public:
    InGameScene();
    ~InGameScene();
    void Update(SceneManager& sceneManager) override;  // SceneManagerへの参照を受け取る
    void Render() override;
};


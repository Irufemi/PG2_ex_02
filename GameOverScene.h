#pragma once
#include "Scene.h"


// クリアシーンのクラス
class GameOverScene : public Scene {
protected:
public:
    GameOverScene();
    ~GameOverScene();
    void Update(SceneManager& sceneManager) override;  // SceneManagerへの参照を受け取る
    void Render() override;
};

#pragma once
#include "Scene.h"


// タイトルシーンのクラス
class TitleScene : public Scene {
protected:
public:
    TitleScene();
    ~TitleScene();
    void Update(SceneManager& sceneManager) override;  // SceneManagerへの参照を受け取る
    void Render() override;
};
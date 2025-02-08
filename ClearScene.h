#pragma once
#include "Scene.h"


// クリアシーンのクラス
class ClearScene : public Scene {
protected:
public:
    ClearScene();
    ~ClearScene();
    void Update(SceneManager& sceneManager) override;  // SceneManagerへの参照を受け取る
    void Render() override;
};

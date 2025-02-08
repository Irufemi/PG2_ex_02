#include <Novice.h>
#include <memory>
#include "Scene.h"

const char kWindowTitle[] = "LC1A_11_スエヒロ_コウイチ_PG2評価課題";
const int kWindowWidth = 1280;
const int kWindowHeight = 720;

char Scene::keys_[256];
char Scene::preKeys_[256];

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	//// キー入力結果を受け取る箱
	//char keys[256] = {0};
	//char preKeys[256] = {0};

	// シーンマネージャーのインスタンスを作成
	SceneManager sceneManager; 

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(Scene::preKeys_, Scene::keys_, 256);
		Novice::GetHitKeyStateAll(Scene::keys_);

		sceneManager.Update();
		sceneManager.Render();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (Scene::preKeys_[DIK_ESCAPE] == 0 && Scene::keys_[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}

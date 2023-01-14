#pragma once

#include "Object3D.h"
#include "AABBCollider.h"

class Item : public Object3D
{
public:
	// コンストラクタ
	Item(std::string name, std::string tag) : Object3D(name, tag) {
		// プレイヤーのモデルをロードする（仮でキューブのオブジェクト）
		GetComponent<MeshRenderer>()->LoadModel("Assets/Model/DemoCube/DemoCube.fbx", 1.0f);
		// コンポーネントを追加
		AddComponent<AABBCollider>();
		// 当たり判定の辺の長さをセット
		GetComponent<AABBCollider>()->SetLen({ 0.5f,0.5f,0.5f });
	}

	// デストラクタ
	~Item() {}
};
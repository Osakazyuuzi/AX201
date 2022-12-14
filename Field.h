#ifndef ___FIELD_H___
#define ___FIELD_H___
#include "Object3D.h"
#include "AABBCollider.h"

class Field : public Object3D
{
public:
	// コンストラクタ
	Field(std::string name, std::string tag) : Object3D(name, tag) {
		// プレイヤーのモデルをロードする（仮でキューブのオブジェクト）
		GetComponent<MeshRenderer>()->LoadModel("Assets/Model/Stage/Stage.fbx", 0.05f);
	}
	// デストラクタ
	~Field() {}
};

#endif //!___FIELD_H___

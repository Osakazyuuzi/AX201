#ifndef ___ARROW_H___
#define ___ARROW_H___
#include "Object3D.h"
#include "MeshRenderer.h"
#include "Rigidbody.h"
#include "AABBCollider.h"
#include "ArrowController.h"

class Arrow : public Object3D
{
public:
	// �R���X�g���N�^
	Arrow(std::string name, std::string tag) : Object3D(name, tag) {
		// ��̃��f�������[�h����
		GetComponent<MeshRenderer>()->LoadModel("Assets/Model/arrow.fbx", 0.5f);
		// �R���|�[�l���g��ǉ�
		AddComponent<Rigidbody>();
		AddComponent<ArrowController>();
		AddComponent<AABBCollider>();
		// �����蔻��̑傫���𒲐�
		GetComponent<AABBCollider>()->SetLen({ 0.6f, 0.6f, 3.0f });
	}
	// �f�X�g���N�^
	~Arrow() {}
};

#endif //!___ARROW_H___
#pragma once
#include "Object3D.h"
#include "MeshRenderer.h"
#include "Rigidbody.h"
#include "AABBCollider.h"
#include "ArrowController.h"

class ShockWave : public Object3D
{
public:
	// �R���X�g���N�^
	ShockWave(std::string name, std::string tag) : Object3D(name, tag) {
		// ��̃��f�������[�h����
		GetComponent<MeshRenderer>()->LoadModel("Assets/Model/DemoCube/DemoCube.fbx", 1.0f);
		// �R���|�[�l���g��ǉ�
		AddComponent<Rigidbody>();
		AddComponent<ArrowController>();
		AddComponent<AABBCollider>();
		// �����蔻��̑傫���𒲐�
		GetComponent<AABBCollider>()->SetLen({ 0.6f, 0.6f, 3.0f });
	}
	// �f�X�g���N�^
	~ShockWave() {}
};

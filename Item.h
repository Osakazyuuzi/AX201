#pragma once

#include "Object3D.h"
#include "AABBCollider.h"
#include "ItemController.h"

class Item : public Object3D
{
public:
	// �R���X�g���N�^
	Item(std::string name, std::string tag) : Object3D(name, tag) {
		// �v���C���[�̃��f�������[�h����i���ŃL���[�u�̃I�u�W�F�N�g�j
		GetComponent<MeshRenderer>()->LoadModel("Assets/Model/DemoCube/DemoCube.fbx", 0.5f);
		// �R���|�[�l���g��ǉ�
		AddComponent<AABBCollider>();
		AddComponent<ItemController>();
		// �����蔻��̕ӂ̒������Z�b�g
		GetComponent<AABBCollider>()->SetLen({ 0.5f,0.5f,0.5f });
	}

	// �f�X�g���N�^
	~Item() {}
};
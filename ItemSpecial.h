#pragma once

#include "Object3D.h"
#include "AABBCollider.h"
#include "ItemController.h"

class ItemSpecial : public Object3D
{
public:
	// �R���X�g���N�^
	ItemSpecial(std::string name, std::string tag) : Object3D(name, tag) {
		//�A�C�e���̃��f�������[�h����i���ŃL���[�u�̃I�u�W�F�N�g�j
		GetComponent<MeshRenderer>()->LoadModel("Assets/Model/Item/specialheart/ItemSpecial.fbx", 0.5f);
		// �R���|�[�l���g��ǉ�
		AddComponent<AABBCollider>();
		AddComponent<ItemController>();
		// �����蔻��̕ӂ̒������Z�b�g
		GetComponent<AABBCollider>()->SetLen({ 0.5f,0.5f,0.5f });
	}

	// �f�X�g���N�^
	~ItemSpecial() {}
};
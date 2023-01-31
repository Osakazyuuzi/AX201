#ifndef ___BOSSENEMY_H___
#define ___BOSSENEMY_H___
#include"Enemy.h"
//
//#include "Object3D.h"
//#include "MeshRenderer.h"
//#include "Rigidbody.h"
//#include "AABBCollider.h"
//#include "EnemyController.h"

class BossEnemy : public Object3D
{
public:
	// �R���X�g���N�^
	BossEnemy(std::string name, std::string tag) : Object3D(name, tag) {
		// �v���C���[�̃��f�������[�h����i���ŃL���[�u�̃I�u�W�F�N�g�j
		GetComponent<MeshRenderer>()->LoadModel("Assets/Model/shinikougeki.fbx", 0.3f);
		// �R���|�[�l���g��ǉ�
		AddComponent<EnemyController>();
		AddComponent<Rigidbody>();
		AddComponent<AABBCollider>();
		// �����蔻��̕ӂ̒������Z�b�g
		GetComponent<AABBCollider>()->SetLen({ 1.0f,1.0f,1.0f });
	}
	// �f�X�g���N�^
	~BossEnemy() {}
};

#endif //!___BOSSENEMY_H___

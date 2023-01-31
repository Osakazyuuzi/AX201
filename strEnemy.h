#ifndef ___STRENEMY_H___
#define ___SYRENEMY_H___
#include "Enemy.h"
//
//#include "Object3D.h"
//#include "MeshRenderer.h"
//#include "Rigidbody.h"
//#include "AABBCollider.h"
//#include "EnemyController.h"
//
class StrEnemy : public Object3D
{
public:
	// �R���X�g���N�^
	StrEnemy(std::string name, std::string tag) : Object3D(name, tag) {
		// �v���C���[�̃��f�������[�h����i���ŃL���[�u�̃I�u�W�F�N�g�j
		GetComponent<MeshRenderer>()->LoadModel("Assets/Model/enemy2.fbx", 0.1f);
		//MeshRenderer::AnimeNo no = GetComponent<MeshRenderer>()->AddAnimation("Assets/Model/The_dead_Walkbone.fbx");
		//if (no == MeshRenderer::ANIME_NONE)
		//{
		//	MessageBox(nullptr, "animeerror", "ERROR", MB_OK);
		//
		//}
		//GetComponent<MeshRenderer>()->Play(no, true);
		// �R���|�[�l���g��ǉ�
		AddComponent<EnemyController>();
		AddComponent<Rigidbody>();
		AddComponent<AABBCollider>();
		// �����蔻��̕ӂ̒������Z�b�g
		GetComponent<AABBCollider>()->SetLen({ 1.0f,1.0f,1.0f });
	}
	// �f�X�g���N�^
	~StrEnemy() {}
};

#endif //!___STRENEMY_H___

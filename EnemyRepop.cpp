#include "EnemyRepop.h"
#include"ObjectManager.h"
#include"ObjectBase.h"
#include"Transform.h"
#include"Enemy.h"
#include<DirectXMath.h>
//EnemeyRepop::EnemeyRepop()
//{
//	
//}

void EnemeyRepop::SetEnemyRepop(float PosX, float PosY, float PosZ)
{
	//Enemy�̐���


		//--- �I�u�W�F�N�g�쐬
		//   �^�@�FEnemy
		//  ���O �FEnemy
		// �^�O���FEnemy
	std::shared_ptr<ObjectBase> pEObj = ObjectManager::CreateObject<Enemy>("Enemy", TagName::Enemy);
	// Transform�̃|�C���^���擾����
	std::shared_ptr<Transform> pTransform = pEObj->GetComponent<Transform>();
	// ���W��ݒ肷��
	pTransform->SetPosition({ PosX, PosY, PosZ });
}

#include "Stage.h"
#include "ObjectBase.h"
#include "ObjectManager.h"
#include <memory>
#include "Transform.h"
#include "AABBCollider.h"

#include "Field.h"
#include "Cube.h"

Stage::Stage()
{
	// �ύX�p�|�C���^
	std::shared_ptr<ObjectBase> pObj;
	std::shared_ptr<Transform> pTrans;
	std::shared_ptr<AABBCollider> pCol;

	//--- Field�̃��f���𐶐�
	// ���O : Field
	// �^�O : ���ݒ� (Untagged)
	pObj = ObjectManager::CreateObject<Field>("Field");
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetScale({ 20.0f, 20.0f, 20.0f });
	pTrans->SetAngle({ 0.0f, 180.0f, 0.0f });

	//--- �����蔻��p���f���𐶐�
	//--- ��
	// ���O : Ground
	// �^�O : Ground
	pObj = ObjectManager::CreateObject<Cube>("Ground", TagName::Ground);
	pCol = pObj->AddComponent<AABBCollider>();
	pTrans = pObj->GetComponent<Transform>();
	pTrans->SetPosition({ -8.0f, -6.4f, -0.0f });
	pTrans->SetScale({ 88.0f,1.0f,41.5f });
	pCol->SetLen({ 88.0f,1.0f,41.5f });
}

Stage::~Stage()
{

}
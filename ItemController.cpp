#include "ItemController.h"
#include "Transform.h"
#include "ObjectBase.h"
#include "Primitive.h"
#include "Vector3.h"
#include "Float3.h"
#include "ObjectManager.h"
#include "Arrow.h"
#include "PlayerController.h"
#include"EnemyRepop.h"
#include "AABBCollider.h"



//============
//  �������H
//============
void ItemController::Start()
{
	GetOwner()->GetComponent<AABBCollider>()->SetTouchOBB(TagName::Arrow);
}


//==========
// �X�V
//==========
void ItemController::Update()
{
	//�A�C�e���̉�]

	//�A�C�e����y���W��sin�g

}



//==================================
// �I�u�W�F�N�g�Ƃ̓����蔻��
//==================================
void ItemController::OnCollisionEnter(ObjectBase* object)
{
	//��Ƃ̓����蔻��
	if (object->GetTag() == TagName::Arrow)
	{
		//�v���C���[�������Ă����łȂ��Ƃ��ɏ�������
		if (ObjectManager::FindObjectWithTag(TagName::Player)->GetComponent<PlayerController>()->GetHaveArrow()
			!= object->GetThisPtr())
		{
			m_bExist = false;

			//�v���C���[�̗͉̑񕜁A�X�y�V�����Q�[�W�̉񕜂̏���
			ObjectManager::FindObjectWithTag(TagName::Player)->GetComponent<PlayerController>()->AddZanki(1);
			ObjectManager::RemoveObject(GetOwner()->GetThisPtr());
		}
	}
}

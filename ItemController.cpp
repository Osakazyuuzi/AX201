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
		std::shared_ptr<ObjectBase> pObj = ObjectManager::FindObjectWithTag(TagName::Player);

		//�v���C���[�������Ă����łȂ��Ƃ��ɏ�������
		if (pObj->GetComponent<PlayerController>()->GetHaveArrow()
			!= object->GetThisPtr())
		{
			//�A�C�e���̎�ނɂ���Č��ʂ�ς���
			switch (m_eItemKind)
			{
				//�̗͉�
			case ItemController::E_LIFE_UP: pObj->GetComponent<PlayerController>()->AddLife(1);
				break;

				//�X�y�V�����A�b�v
			case ItemController::E_SPECIAL_UP: pObj->GetComponent<PlayerController>()->SetEnableSpecial();
				break;
			
			default:
				break;
			}

			//���g�̍폜
			ObjectManager::RemoveObject(GetOwner()->GetThisPtr());
		}
	}
}



//=======================
//�A�C�e���̎�ނ����߂�
//=======================
void ItemController::SetItemKind(int kind)
{
	//�̗͉�
	if (kind == 0) m_eItemKind = E_LIFE_UP;
	//�X�y�V����
	if (kind == 1) m_eItemKind = E_SPECIAL_UP;
}

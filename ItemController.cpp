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
	m_rotY += 0.5f;
	GetOwner()->GetComponent<Transform>()->SetAngle(DirectX::XMFLOAT3(0.0f, m_rotY, 0.0f));

	//�A�C�e����y���W��sin�g
	m_pos = GetOwner()->GetComponent<Transform>()->GetPosition();
	m_pos.y = sin(m_sinFram * 360 / 60 * 3.14f / 180) * 0.03f + m_pos.y;
	GetOwner()->GetComponent<Transform>()->SetPosition(m_pos);

	m_sinFram++;
	m_collCount++;
}



//==================================
// �I�u�W�F�N�g�Ƃ̓����蔻��
//==================================
void ItemController::OnCollisionEnter(ObjectBase* object)
{
	//��Ƃ̓����蔻��
	if (object->GetTag() == TagName::Arrow && m_collCount > 30)
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
			case ItemController::E_LIFE_UP: pObj->GetComponent<PlayerController>()->AddLife(MAX_LIFE);
				break;

				//�X�y�V�����A�b�v
			case ItemController::E_SPECIAL_UP: pObj->GetComponent<PlayerController>()->SetEnableSpecial(true);
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

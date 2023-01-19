#pragma once

#include "ComponentBase.h"
#include "ObjectBase.h"
#include <DirectXMath.h>


class ItemController :
	public ComponentBase
{
public:
	//�A�C�e���̎��
	enum ITEMKIND
	{
		E_LIFE_UP = 0, //�̗͉�

		E_SPECIAL_UP,  //�X�y�V������

		MAX_KIND
	};

public:
	ItemController()
		:m_rotSpeed(DirectX::XMConvertToRadians(10.0f))
	{}
	~ItemController()
	{}

	void Start() override final;
	void Update() override final;

	// �����蔻��
	void OnCollisionEnter(ObjectBase* object) override final;

	//�Z�b�g�֐�
	void SetItemKind(int kind);

private:
	//�A�C�e���̉�]���x
	float m_rotSpeed;
	//�A�C�e���̎��
	ITEMKIND m_eItemKind;
};


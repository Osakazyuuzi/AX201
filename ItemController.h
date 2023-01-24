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
		:m_pos(0.0f, 0.0f, 0.0f),
		m_sinFram(0.0f),
		m_rotY(0.0f),
		m_collCount(0)
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
	//�A�C�e���̉�]
	float m_rotY;
	//�A�C�e���̎��
	ITEMKIND m_eItemKind;
	//�A�C�e���̍��W
	DirectX::XMFLOAT3 m_pos;
	float m_sinFram;
	//�����蔻��p�̃J�E���g
	int m_collCount;
};


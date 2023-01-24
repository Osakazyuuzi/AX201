#include "light.h"
#include "CameraPlayer.h"
#include "Input.h"
#include "ObjectManager.h"
#include "Transform.h"


//=====================
//   �R���X�g���N�^
//=====================
light::light()
{
	//�R���X�^���g�o�b�t�@
	m_pWVP = new ConstantBuffer();
	m_pWVP->Create(sizeof(Light)); //����\���̂̌^

	//******************************************************
	//*****************�f�B���N�V�������C�g*****************
	//******************************************************
	//�f�B���N�V�������C�g�̌������x�N�g���ɕϊ�
	m_Light.dirDirection = XMFLOAT3(0.0f, -1.0f, 1.0f);

	//�f�B���N�V�������C�g�̐F
	m_Light.dirColor = XMFLOAT3(1.0f, 1.0f, 1.0f);

	//******************************************************
	//********************�|�C���g���C�g********************
	//******************************************************
	//�|�C���g���C�g�̈ʒu
	m_Light.ptPosition = XMFLOAT3(0.0f, 0.0f, 0.0f);

	//�|�C���g���C�g�̐F
	m_Light.ptColor = XMFLOAT3(0.0f, 0.0f, 0.0f);

	//�|�C���g���C�g�̉e���͈�
	m_Light.ptRange = 0.0f;

	//******************************************************
	//********************�X�|�b�g���C�g********************
	//******************************************************
	//�X�|�b�g���C�g�̈ʒu
	m_Light.spPosition = XMFLOAT3(0.0f, 0.0f, 0.0f);

	//�X�|�b�g���C�g�̐F
	m_Light.spColor = XMFLOAT3(0.0f, 0.0f, 0.0f);

	//�X�|�b�g���C�g�̉e���͈�
	m_Light.spRange = 0.0f;

	//�X�|�b�g���C�g�̌���
	m_Light.spDirection = XMFLOAT3(0.0f, 0.0f, 0.0f);

	//�X�|�b�g���C�g�̊p�x
	m_Light.spAngle = XMConvertToRadians(0.0f);

	//*****************************************************
	//**********************�������C�g*********************
	//*****************************************************
	//�n�ʂ̐F ���{���̓v���C���[�ƒn�ʂ̓����蔻����Ƃ��ăv���C���[�������Ă���u���b�N��X�e�[�W�̐F�������Ă���
	m_Light.groundColor = XMFLOAT3(0.0f, 0.0f, 0.0f);

	//��̐F  ���Ȃ񂩃X�e�[�W�F�Ƃ����������� �V��Ƃ�
	m_Light.skyColor = XMFLOAT3(0.0f, 0.0f, 0.0f);

	//�n�ʂ̖@���@���������v���C���[�������Ă���u���b�N�̖@������������Ă���
	m_Light.groundNormal = XMFLOAT3(0.0f, 1.0f, 0.0f);

	//******************************************************
	//************************���̑�************************
	//******************************************************

	//����
	m_Light.ambientLIght = XMFLOAT3(0.3f, 0.3f, 0.3f);
}

//
//
//
light::~light()
{
	delete m_pWVP;
}


//========================
//     ���C�g�̍X�V
//========================
void light::Update()
{
	//���_�̈ʒu�̍X�V
	m_Light.eyePos = ObjectManager::FindObjectWithTag(TagName::MainCamera)->GetComponent<Transform>()->GetPosition();

	//�|�C���g���C�g�̈ʒu���X�V
	if (IsKeyPress(VK_SHIFT))
	{
		if (IsKeyPress('I')) m_Light.ptPosition.z += 1.0f;
		if (IsKeyPress('K')) m_Light.ptPosition.z -= 1.0f;
		if (IsKeyPress('L')) m_Light.ptPosition.x += 1.0f;
		if (IsKeyPress('J')) m_Light.ptPosition.x -= 1.0f;
	}

	
}


//======================================
//���C�g�̏����s�N�Z���V�F�[�_�ɑ���
//======================================
void light::SetLight()
{
	//���C�g�̏��������݃s�N�Z���V�F�[�_�ɑ���
	m_pWVP->Write(&m_Light);
	m_pWVP->BindPS(1);
}
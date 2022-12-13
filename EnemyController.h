#ifndef ___ENEMY_CONTROLLER_H___
#define ___ENEMY_CONTROLLER_H__

#include "ComponentBase.h"
#include "ObjectBase.h"
#include <DirectXMath.h>

class EnemyController : public ComponentBase
{
private:

	//--- �ړ��p
	// �ړ��X�s�[�h�i�P�t���[���ɐi�ދ����j
	float m_MoveSpeed;
	// �^�[�Q�b�g�܂ł̃x�N�g��
	DirectX::XMFLOAT3 m_TargetVector;
	// �^�[�Q�b�g�̏ꏊ�������_���ŕς��鎞��(�~���b)
	float m_ChangeTargetTime;
	float m_tic; // �t���[���J�E���g
	float m_TargetRotY;	// �^�[�Q�b�g�܂ł̃x�N�g����Y�p�x
	float m_lateRotY;	// �x��Ă��Ă���Y�p�x
public:
	// �R���X�g���N�^
	EnemyController()
		: m_MoveSpeed(0.05f)
		, m_ChangeTargetTime(50.0f)
		, m_tic(m_ChangeTargetTime)
		, m_TargetRotY(0.0f)
		, m_lateRotY(0.0f)
	{}
	// �f�X�g���N�^
	~EnemyController() {}

	// �X�V
	void Update()override;

	// �����蔻��
	void OnCollisionEnter(ObjectBase* object);
	void OnCollisionStay(ObjectBase* object);
	void OnCollisionExit(ObjectBase* object);

	//--- �Z�b�g�֐�
	void SetMoveSpeed(float speed) { m_MoveSpeed = speed; }
};

#endif //!___ENEMY_CONTROLLER_H___
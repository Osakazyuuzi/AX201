#ifndef ___PLAYER_CONTROLLER_H___
#define ___PLAYER_CONTROLLER_H__

#include "ComponentBase.h"
#include "ObjectBase.h"
#include <memory>

class PlayerController : public ComponentBase
{
private:
	//--- �ˌ��p
	// �������ɂ�闭�ߍU�����g�p�\�ɂȂ鎞��
	float m_ChargeTime;
	float m_tic; // �t���[���J�E���g
	std::shared_ptr<ObjectBase> m_haveArrow; // ���݃v���C���[�������Ă����̃|�C���^
public:
	// �R���X�g���N�^
	PlayerController()
		: m_ChargeTime(30.0f) // 60 fps �̏ꍇ 0.5 �b
	{}
	// �f�X�g���N�^
	~PlayerController() {}

	// �X�V
	void Update()override;


	// �����蔻��
	void OnCollisionEnter(ObjectBase* object);
	void OnCollisionStay(ObjectBase* object);
	void OnCollisionExit(ObjectBase* object);
};

#endif //!___PLAYER_CONTROLLER_H___
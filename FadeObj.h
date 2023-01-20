#ifndef ___FADE_OBJ_H___
#define ___FADE_OBJ_H___

#include "UI.h"
#include "FadeController.h"
#include "Transform.h"

class FadeObj : public UI
{
public:
	// �R���X�g���N�^
	FadeObj(std::string name, std::string tag) : UI(name, tag) {
		// �R���|�[�l���g��ǉ�
		AddComponent<FadeController>();
		// ���W�����_��
		GetComponent<Transform>()->SetPosition({ 0.0f, 0.0f, 0.0f });
		// �e�N�X�`�����Z�b�g
		GetComponent<SpriteRenderer>()->LoadTexture("Assets/Texture/WHITE.png");
		// �S��ʂ̃T�C�Y�ɕύX
		GetComponent<SpriteRenderer>()->SetSize(1280, 720);
		// ��Ԏ�O�ɕ`�悷�邽�߁A���C���[��傫�Ȑ�����
		SetLayerNum(999);
	}
	// �f�X�g���N�^
	~FadeObj(){}

	// �`��
	void Draw() override final {
		this->GetComponent<SpriteRenderer>()->SetColor(
			this->GetComponent<FadeController>()->GetColor()
		);
		this->GetComponent<SpriteRenderer>()->Draw();
	}
};

#endif //!___FADE_OBJ_H___
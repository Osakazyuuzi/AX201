#ifndef ___UI_H___
#define ___UI_H___

#include "ObjectBase.h"
#include "SpriteRenderer.h"
#include "DirectX.h"
#include "UIController.h"

class UI : public ObjectBase
{
public:
	// �R���X�g���N�^
	UI(std::string name, std::string tag) : ObjectBase(name, tag) {
		// �f�t�H���g�R���|�[�l���g��ǉ�
		this->AddComponent<SpriteRenderer>();	// 2D�p�\�ʏ��
		//----1/14 �|�� UIController��ǉ�
		AddComponent<UIController>();
	
		// �S�Ă̐ݒ肪�I�������Ăяo��
		this->Start();
	}
	// �f�X�g���N�^
	~UI(){}

	// �`��
	void Draw() override {
		this->GetComponent<SpriteRenderer>()->Draw();
	}
};
// 12/16 �v�����N�G�X�g�̃e�X�g �|��
#endif //!___UI_H___
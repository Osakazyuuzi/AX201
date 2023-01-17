#ifndef ___Game01_H___
#define ___Game01_H___
//--------------------------------------------------------------------------------
// 1/17 �|��
// �Q�[��01�w�b�_(�^�C�g��)���쐬(UIController�����ׂẴV�[���ɓK�����ꂿ�Ⴄ����)
//
//--------------------------------------------------------------------------------

#include "ObjectBase.h"
#include "SpriteRenderer.h"
#include "DirectX.h"
#include "01Controller.h"
class Game01 : public ObjectBase
{
public:
	// �R���X�g���N�^
	Game01(std::string name, std::string tag) : ObjectBase(name, tag) {
		// �f�t�H���g�R���|�[�l���g��ǉ�
		this->AddComponent<SpriteRenderer>();	// 2D�p�\�ʏ��
		//----1/14 �|�� UIController��ǉ�
		AddComponent<Game01Controller>();

		// �S�Ă̐ݒ肪�I�������Ăяo��
		this->Start();
	}
	// �f�X�g���N�^
	~Game01() {}

	// �`��
	void Draw() override {
		this->GetComponent<SpriteRenderer>()->Draw();
	}
};
#endif //!___Game01_H___
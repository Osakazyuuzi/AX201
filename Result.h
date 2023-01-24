#pragma once
#ifndef ___Result_H___
#define ___Result_H___
//--------------------------------------------------------------------------------
// 1/17 �|��
// ���U���g�w�b�_���쐬
//
//--------------------------------------------------------------------------------
#include "ObjectBase.h"
#include "SpriteRenderer.h"
#include "DirectX.h"
#include "ResultController.h"
class Result : public ObjectBase
{
public:
	// �R���X�g���N�^
	Result(std::string name, std::string tag) : ObjectBase(name, tag) {
		// �f�t�H���g�R���|�[�l���g��ǉ�
		this->AddComponent<SpriteRenderer>();	// 2D�p�\�ʏ��
		//----1/14 �|�� UIController��ǉ�
		AddComponent<ResultController>();

		// �S�Ă̐ݒ肪�I�������Ăяo��
		this->Start();
	}
	// �f�X�g���N�^
	~Result() {}

	// �`��
	void Draw() override {
		this->GetComponent<SpriteRenderer>()->Draw();
	}
};
#endif //!___Game01_H___

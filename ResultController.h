#pragma once
#ifndef ___RESULT_CONTROLLER_H___
#define ___RESULT_CONTROLLER_H__

#include "ComponentBase.h"
#include "ObjectBase.h"
#include <memory>
#include <DirectXMath.h>

class ResultController : public ComponentBase
{
private:
	bool m_NextScene; // UI�؂�ւ��p�t���O
public:
	// �R���X�g���N�^
	ResultController() {};
	// �f�X�g���N�^
	~ResultController() {};

	// ������
	void Start() override;
	// �X�V
	void Update()override;
};

#endif //!___RESULT_CONTROLLER_H___
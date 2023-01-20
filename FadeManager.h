#ifndef ___FADEMANAGER_H___
#define ___FADEMANAGER_H___

#include "FadeController.h"
#include "SceneName.h"

class FadeManager {
public:
	// �R���X�g���N�^
	FadeManager(){}
	// �f�X�g���N�^
	~FadeManager(){}

	/**
	@brief �t�F�[�h�C�����쐬����B

	@note �t�F�[�h�C���͓����x�������Ȃ��Ă����t�F�[�h�ł��B
	@note ���ɐ����ς݂̏ꍇ�A�쐬���܂���B
	*/
	static void CreateFadeIn();
	
	/**
	@brief �t�F�[�h�A�E�g���쐬����B

	@note �t�F�[�h�A�E�g�͓����x���Ⴍ�Ȃ��Ă����t�F�[�h�ł��B
	@note ���ɐ����ς݂̏ꍇ�B�쐬���܂���B
	*/
	static void CreateFadeOut(SceneName::SceneName name);
};

#endif //!___FADEMANAGER_H___
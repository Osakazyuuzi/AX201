//------------------------------
//1/17 �|��
//     �^�C�g����ʃ{�^���̐F�ύX�p
//     (�������獕���Ȃ�)
//------------------------------
#include "SBotton.h"

SBtton::SBtton()
{
	m_isPlay = true;
	// ���[�v����
	m_isLoop = true;

	KeyFrame SBtton;

	SBtton.time = 60;
	SBtton.uv.uvWidth = 1.0f / 3;
	SBtton.uv.uvHeight = 1.0f;
	SBtton.uv.uvTopLeftU = 0.0f;
	SBtton.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(SBtton);

	SBtton.uv.uvTopLeftU = 1.0f / 3;
	SBtton.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(SBtton);

	SBtton.uv.uvTopLeftU = 1.0f / 3 * 2;
	SBtton.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(SBtton);
}

SBtton::~SBtton()
{
}
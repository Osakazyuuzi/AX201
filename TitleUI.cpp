//--------------------------------------
// 2022/12/20 �|���Y���Y
// �n�[�g���A�j���[�V�������쐬
//
//--------------------------------------
#include "TitleUI.h"
#include "Input.h"

TitleUI::TitleUI()
{
	m_isPlay = true;
	// ���[�v����
	m_isLoop = true;

	KeyFrame TitleUI;

	TitleUI.time = 60;
	TitleUI.uv.uvWidth = 1.0f;
	TitleUI.uv.uvHeight = 1.0f;
	TitleUI.uv.uvTopLeftU = 0.0f;
	TitleUI.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(TitleUI);
}

TitleUI::~TitleUI()
{
}





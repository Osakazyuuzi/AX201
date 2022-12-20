//--------------------------------------
// 2022/12/20 �|���Y���Y
// �n�[�g���A�j���[�V�������쐬
//
//--------------------------------------
#include "Life.h"
#include "Input.h"

Life::Life()
{
	m_isPlay = true;
	// ���[�v����
	m_isLoop = true;

	KeyFrame Life;

	Life.time = 60;
	Life.uv.uvWidth = 1.0f / 2;
	Life.uv.uvHeight = 1.0f / 3;
	Life.uv.uvTopLeftU = 0.0f;
	Life.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(Life);

	Life.uv.uvTopLeftU = 1.0f / 2;
	Life.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(Life);

	Life.uv.uvTopLeftU = 0.0f;
	Life.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(Life);

	Life.uv.uvTopLeftU = 1.0f / 2;
	Life.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(Life);

	Life.uv.uvTopLeftU = 0.0f;
	Life.uv.uvTopLeftV = 1.0f / 3 * 2;
	m_keyframes.push_back(Life);
}

Life::~Life()
{
}

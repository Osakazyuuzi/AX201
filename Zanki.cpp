//--------------------------------------
// 2022/12/19 �|���Y���Y
// �c�@�̐��������̃A�j���[�V�������쐬
//
//--------------------------------------
#include "Zanki.h"
Zanki::Zanki()
{
	m_isPlay = true;
	// ���[�v����
	m_isLoop = true;

	KeyFrame Zanki;

	// ����9
	Zanki.time = 60;
	Zanki.uv.uvWidth = 1.0f / 4;
	Zanki.uv.uvHeight = 1.0f / 3;
	Zanki.uv.uvTopLeftU = 1.0f / 4;
	Zanki.uv.uvTopLeftV = 1.0f / 3 * 2;
	m_keyframes.push_back(Zanki);
	// ����8
	Zanki.uv.uvTopLeftU = 0.0f;
	Zanki.uv.uvTopLeftV = 1.0f / 3 * 2;
	m_keyframes.push_back(Zanki);
	// ����7
	Zanki.uv.uvTopLeftU = 1.0f / 4 * 3;
	Zanki.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(Zanki);
	// ����6
	Zanki.uv.uvTopLeftU = 1.0f / 4 * 2;
	Zanki.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(Zanki);
	// ����5
	Zanki.uv.uvTopLeftU = 1.0f / 4;
	Zanki.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(Zanki);
	// ����4
	Zanki.uv.uvTopLeftU = 0.0f;
	Zanki.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(Zanki);
	// ����3
	Zanki.uv.uvTopLeftU = 1.0f / 4 * 3;
	Zanki.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(Zanki);
	// ����2
	Zanki.uv.uvTopLeftU = 1.0f / 4 * 2;
	Zanki.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(Zanki);
	// ����1
	Zanki.uv.uvTopLeftU = 1.0f / 4;
	Zanki.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(Zanki);
	// ����0
	Zanki.uv.uvTopLeftU = 0.0f;
	Zanki.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(Zanki);	
}

Zanki::~Zanki()
{
}




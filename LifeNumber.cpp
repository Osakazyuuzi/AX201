#include "LifeNumber.h"

LifeNumber::LifeNumber()
{
	m_isPlay = true;
	// ���[�v����
	m_isLoop = true;

	KeyFrame LifeNumber;

	// ����100
	LifeNumber.time = 60;
	LifeNumber.uv.uvWidth = 1.0f / 2;
	LifeNumber.uv.uvHeight = 1.0f / 2;
	LifeNumber.uv.uvTopLeftU = 0.0f;
	LifeNumber.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(LifeNumber);
	// ����75
	LifeNumber.uv.uvTopLeftU = 0.5f;
	LifeNumber.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(LifeNumber);
	// ����50
	LifeNumber.uv.uvTopLeftU = 0.0f;
	LifeNumber.uv.uvTopLeftV = 0.5f;
	m_keyframes.push_back(LifeNumber);
	// ����25
	LifeNumber.uv.uvTopLeftU = 0.5f;
	LifeNumber.uv.uvTopLeftV = 0.5f;
	m_keyframes.push_back(LifeNumber);
}

LifeNumber::~LifeNumber()
{
}

//--------------------------------------
// 2023/1/31 ���I
// �X�y�V�����̃Q�[�W����
//
//--------------------------------------
#include "SpesialGauge.h"
SpesialGauge::SpesialGauge()
{
	m_isPlay = true;
	// ���[�v����
	m_isLoop = true;

	KeyFrame SpesialGauge;

	// ���߂ĂȂ����
	SpesialGauge.time = 60;
	SpesialGauge.uv.uvWidth = 1.0f / 3;
	SpesialGauge.uv.uvHeight = 1.0f / 2;
	SpesialGauge.uv.uvTopLeftU = 1.0f / 3.0f;
	SpesialGauge.uv.uvTopLeftV = 1.0f / 2.0f;
	m_keyframes.push_back(SpesialGauge);
	//1
	SpesialGauge.uv.uvTopLeftU = 0.0f;
	SpesialGauge.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(SpesialGauge);
	//2
	SpesialGauge.uv.uvTopLeftU = 1.0f / 3.0f;
	SpesialGauge.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(SpesialGauge);
	//3
	SpesialGauge.uv.uvTopLeftU = 1.0f / 3.0f * 2;
	SpesialGauge.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(SpesialGauge);
	//4
	SpesialGauge.uv.uvTopLeftU = 0.0f;
	SpesialGauge.uv.uvTopLeftV = 1.0f / 2.0f;
	m_keyframes.push_back(SpesialGauge);
}

SpesialGauge::~SpesialGauge()
{
}




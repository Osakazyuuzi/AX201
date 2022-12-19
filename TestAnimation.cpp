#include "TestAnimation.h"

TestAnimation::TestAnimation()
{
	// �e�X�g�Ȃ̂ł�����true�ɂ��邪�A
	// Controller�n��Component����true�ɂ��Ă��悢
	m_isPlay = true;
	// ���[�v����
	m_isLoop = true;
	
	// �L�[��ݒ�
	KeyFrame keyframe;
	// �@
	keyframe.time = 60;
	keyframe.uv.uvWidth  = 1.0f / 3;
	keyframe.uv.uvHeight = 1.0f / 3;
	keyframe.uv.uvTopLeftU = 0.0f;
	keyframe.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(keyframe);	// �ǉ�
	// �A
	keyframe.uv.uvTopLeftU = 1.0f / 3;
	keyframe.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(keyframe);	// �ǉ�
	// �B
	keyframe.uv.uvTopLeftU = 1.0f / 3 * 2;
	keyframe.uv.uvTopLeftV = 0.0f;
	m_keyframes.push_back(keyframe);	// �ǉ�
	// �C
	keyframe.uv.uvTopLeftU = 0.0f;
	keyframe.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(keyframe);	// �ǉ�
	// �D
	keyframe.uv.uvTopLeftU = 1.0f / 3;
	keyframe.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(keyframe);	// �ǉ�
	// �E
	keyframe.uv.uvTopLeftU = 1.0f / 3 * 2;
	keyframe.uv.uvTopLeftV = 1.0f / 3;
	m_keyframes.push_back(keyframe);	// �ǉ�
}

TestAnimation::~TestAnimation()
{

}
#include "SpriteAnimation.h"
#include "ObjectBase.h"

SpriteAnimation::SpriteAnimation()
	: m_time(0.0f)
	, m_isLoop(false)
	, m_speed(0.0f)
	, m_isPlay(false)
	, m_frameNum(0)
	, m_isSwap(false)
	, m_NextframeNum(0)
{

}

SpriteAnimation::~SpriteAnimation()
{

}

void SpriteAnimation::Start()
{
	m_SpritePtr = GetOwner()->GetComponent<SpriteRenderer>();
}

void SpriteAnimation::Update()
{
	// �Đ����̂�
	if (m_isPlay) {
		//���Ԍo�߂ŕς��UI����������Ƃ��̂��߂̎Q�l�����̂��߂Ɏc���[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[
		// �A�j���[�V�������Ԃ��X�V
		//m_time++;
		//// �L�[�̎��ԂɂȂ�����
		//if (m_time >= m_keyframes[m_frameNum].time) {
		//	// �o�ߎ��Ԃ�␳����
		//	while (m_time >= m_keyframes[m_frameNum].time)
		//		m_time -= m_keyframes[m_frameNum].time;
		//	// �L�[�t���[�������̃L�[�t���[���ɂ���
		//	m_frameNum++;
		//	// �Ō�̃L�[�t���[��������
		//	if (m_frameNum == m_keyframes.size()) {
		//		// ���[�v����Ȃ�
		//		if (m_isLoop) {
		//			// �ŏ��̃t���[����
		//			m_frameNum = 0;
		//		}
		//		else { // ���Ȃ��Ȃ�
		//			// �Đ��t���O��������
		//			m_isPlay = false;
		//			return;
		//		}
		//	}
		//}�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[�[


		//Swap�t���O����������
		if (m_isSwap) 
		{
			// �L�[�t���[�������̃L�[�t���[���ɂ���
			m_frameNum = m_NextframeNum;
			// �t���O��܂��Ƃ�
			m_isSwap = false;

		}
		// ���݂̃L�[�̏����X�v���C�g���ɔ��f������
		m_SpritePtr->GetInfo()->animeUV = m_keyframes[m_frameNum].uv;
	}
}

void SpriteAnimation::Play()
{
	m_isPlay = true;
	m_frameNum = 0;
}

void SpriteAnimation::Swapframe(unsigned int nextframe)
{
	if (m_keyframes.size() < nextframe)
		MessageBox(nullptr, "SpriteAnimation�FSwapframe�ł̔z��O�A�N�Z�X","Error",MB_OK);
	m_isSwap = true;
	m_NextframeNum = nextframe;
	
}
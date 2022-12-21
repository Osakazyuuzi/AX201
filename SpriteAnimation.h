#ifndef ___SPRITE_ANIMATION_H___
#define ___SPRITE_ANIMATION_H___

#include "ComponentBase.h"
#include "SpriteRenderer.h"
#include <vector>
#include <memory>
#include "SpriteRenderer.h"

class SpriteAnimation : public ComponentBase
{
protected:
	// �A�j���[�V�����L�[
	struct KeyFrame {
		float time;
		SpriteRenderer::AnimeUV uv;
	};
	using KeyFrames = std::vector<KeyFrame>;
public:
	// �R���X�g���N�^
	SpriteAnimation();
	// �f�X�g���N�^
	~SpriteAnimation();

	// ������
	void Start() override final;
	// �X�V
	void Update() override final;

	// �Đ�
	void Play();
	
	//�t���[���؂�ւ�
	void Swapframe(unsigned int nextframe);

protected:
	std::shared_ptr<SpriteRenderer> m_SpritePtr; // ���삷��X�v���C�g�f�[�^
	// �A�j���[�V�������
	float		m_time;			// ���݂̍Đ�����
	float		m_speed;		// �Đ����x
	bool		m_isLoop;		// ���[�v�ݒ�
	KeyFrames	m_keyframes;	// �L�[�t���[�����

	bool		m_isPlay;		// �Đ������ǂ���
	int			m_frameNum;		// ���݂̃t���[���ԍ�
	bool		m_isSwap;			// uv��ύX���邩�ǂ���
	int			m_NextframeNum;
};

#endif //!___SPRITE_ANIMATION_H___
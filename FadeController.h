#ifndef ___FADE_CONTROLLER_H___
#define ___FADE_CONTROLLER_H___

#include "ComponentBase.h"
#include <DirectXMath.h>
#include "SceneName.h"

class FadeController : public ComponentBase
{
public:
	// �t�F�[�h�̐F
	constexpr static DirectX::XMFLOAT3 mc_FadeColor = { 0.0f, 0.0f, 0.0f };
	// �t�F�[�h�̎���
	constexpr static float mc_FadeTime = 100.0f;
public:
	// �t�F�[�h�^�C�v
	enum FadeType {
		Fade_In,	// �t�F�[�h�C��		���񂾂��ʂ�������悤�ɂȂ�
		Fade_Out};	// �t�F�[�h�A�E�g�@ ���񂾂��ʂ������Ȃ��Ȃ�

	// �R���X�g���N�^
	FadeController();
	// �f�X�g���N�^
	~FadeController(){}

	void Update() override final;

	//--- �Z�b�g�֐�
	void SetFadeType(FadeType type) { m_Type = type; }
	void SetFadeColor(DirectX::XMFLOAT4 color) { m_Color = color; }
	void SetFadeTime(float time) { m_TotalTime = time; }
	void SetLoadScene(SceneName::SceneName name) { m_eName = name; }

	//--- �Q�b�g�֐�
	DirectX::XMFLOAT4 GetColor() noexcept { return m_Color; }
	bool IsEnd() noexcept { return m_TotalTime < m_time; }

private:
	// �t�F�[�h�̃^�C�v
	FadeType m_Type;
	// �t�F�[�h�̐F
	DirectX::XMFLOAT4 m_Color;
	// �t�F�[�h�̎���
	float m_TotalTime;

	// �o�ߎ���
	float m_time;

	// �؂�ւ������V�[����
	SceneName::SceneName m_eName;
};

#endif //!___FADE_CONTROLLER_H___
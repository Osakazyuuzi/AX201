#include "FadeController.h"
#include "SceneManager.h"

FadeController::FadeController()
	: m_Color({mc_FadeColor.x, mc_FadeColor.y, mc_FadeColor.z, 1.0f})
	, m_Type(FadeType::Fade_Out)
	, m_time(0.0f), m_TotalTime(mc_FadeTime)
{

}

void FadeController::Update()
{
	// �t�F�[�h���I����Ă��邩
	if (IsEnd()) {
		switch (m_Type) {
		case FadeController::Fade_In:
			return;
			break;
		case FadeController::Fade_Out:
			SceneManager::LoadScene(m_eName);
			break;
		}
	}

	// ���Ԃ����Z
	m_time++;

	switch (m_Type){
	// �����ɂ���
	case FadeController::Fade_In:
		m_Color.w = 1 - (m_time / m_TotalTime);
		break;
	case FadeController::Fade_Out:
		m_Color.w = m_time / m_TotalTime;
		break;
	}
}
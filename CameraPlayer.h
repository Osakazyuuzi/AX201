#ifndef ___CAMERA_PLAYER_H___
#define ___CAMERA_PLAYER_H___

#include "Camera.h"

class CameraPlayer : public Camera
{
public:
	// �R���X�g���N�^
	CameraPlayer()
		: m_radius(mc_radius)
		, m_tick(0)
		, m_bScreenShake(true)
	{}
	// �f�X�g���N�^
	~CameraPlayer(){}

	void Update() override;

	constexpr static float mc_radius = 10.0f;

	constexpr static float mc_screenShakeTime = 10.0f;

	//--- �Z�b�g�֐�
	void SetRadXZ(float rad) { m_StopRadXZ = m_radXZ = rad; }
	void SetRadY(float rad) { m_StopRadY = m_radY = rad; }

	void ScreenShake() {
		m_bScreenShake = true;
		m_tick = 0.0f;
	}

private:
	float m_radXZ, m_radY;		// ��荞�݊p�x
	float m_StopRadXZ, m_StopRadY;
	float m_radius;				// �J�����ƒ����_�̋���

	float m_tick;
	bool m_bScreenShake;
};

#endif //!___CAMERA_PLAYER_H___
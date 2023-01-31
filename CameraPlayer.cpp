#include "CameraPlayer.h"
#include "Transform.h"
#include "ObjectManager.h"

void CameraPlayer::Update()
{
	// Player�^�O�̂����I�u�W�F�N�g�̍��W���擾���A�����_�ɂ���B
	m_LookPoint = ObjectManager::FindObjectWithTag(TagName::Player)->GetComponent<Transform>()->GetPosition();

	// �p�x�Ƌ����A�����_����J�����̈ʒu���v�Z
	GetOwner()->GetComponent<Transform>()->SetPosition({
	cosf(m_radY) * sinf(m_radXZ) * m_radius + m_LookPoint.x,
	sinf(m_radY) * m_radius + m_LookPoint.y,
	cosf(m_radY) * cosf(m_radXZ) * m_radius + m_LookPoint.z
		});

	/* ��ʗh�ꔻ�� */
	if (m_bScreenShake)
	{
		m_tick++;
		m_radius = (mc_radius - sinf(m_tick * 100 / mc_screenShakeTime));
		m_radY = (m_StopRadY - sinf(m_tick*100 / mc_screenShakeTime)) * -0.02f + 3;
		m_radXZ = (m_StopRadXZ - sinf(m_tick * 100 / mc_screenShakeTime)) * -0.02f + 6.27;
		if (mc_screenShakeTime < m_tick) m_bScreenShake = false;
	}
}
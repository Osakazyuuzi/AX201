#ifndef ___CLEARMANAGER_H___
#define ___CLEARMANAGER_H___
#include"ComponentBase.h"

#include<vector>
#include<DirectXMath.h>

class ClearManager : public ComponentBase
{
public:
	//�R���X�g���N�^
	ClearManager();
	//�f�X�g���N�^
	~ClearManager()
	{}

	//�X�V
	void Update() override;
	// �N���A�����̓G��|������
	constexpr static int mc_nClearEnemyNum = 11;
private:
	int m_BreakEnemy;
	float m_alpha;
	DirectX::XMFLOAT4  m_color;
	
	// �o�ߎ���
	float m_time;
	float m_TotalTime;
};
#endif // __CLEARMANAGER_H__

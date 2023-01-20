#ifndef ___ENEMYMANAGER_H___
#define ___ENEMYMANAGER_H___
#include"ComponentBase.h"

#include<vector>
#include<DirectXMath.h>
class EnemyManager : public ComponentBase
{
public:
	//�R���X�g���N�^
	EnemyManager();
	//�f�X�g���N�^
	~EnemyManager()
	{}

	//�X�V
	void Update() override;

	//���|�b�v�֐�
	void EnemyRepop(DirectX::XMFLOAT3,DirectX::XMFLOAT3);
	void StrEnemyRepop(DirectX::XMFLOAT3, DirectX::XMFLOAT3);
	//�W�F�l���[�g�֐�
	void EnemyGenerate(DirectX::XMFLOAT3, DirectX::XMFLOAT3,float,float,float);
	void StrEnemyGenerate(DirectX::XMFLOAT3, DirectX::XMFLOAT3,float,float,float);
	//��{�X�p�W�F�l���[�g�֐�
	void BEnemyGenerate(DirectX::XMFLOAT3, DirectX::XMFLOAT3,float,float,float);
	void BStrEnemyGenerate(DirectX::XMFLOAT3, DirectX::XMFLOAT3,float,float,float);
	//�G�̍ő吔
	constexpr static int mc_EnemyMaxNum = 10;
	//�ʏ풆�{�X����������G�l�~�[�̐�
	constexpr static int mc_RepopBossCount = 8;
	//�������{�X����������G�l�~�[�̐�
	constexpr static int mc_RepopStrBossCount = 3;
	//��{�X����������G�l�~�[�̐�
	constexpr static int mc_RepopFinalBigBossCount = 5;
private:
	//���|�b�v����Ԋu
	float m_RepopTime;
	//�t���[���J�E���g
	float m_tick;
	//��{�X�p�t���[���J�E���g
	float m_FBBtick;
	//���X�{�X���o��܂ł̓G�̌��ސ�
	int m_AppearCount;
	std::vector<DirectX::XMFLOAT3> m_RepopPosList;
	//�ŏ��������|�b�v����t���O
	bool m_FirstOnlyFlg;
	//�{�X���o�Ă���܂ł̃J�E���g
	int m_MBCount;
	//��{�X����������G�l�~�[���|�b�v����Ԋu
	float m_FBBRepopTime;
	//��{�X����������G�l�~�[��
	int m_FBBEnemyCount;
};


#endif // !___ENEMYMANAGER_H___

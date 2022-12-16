#include "SceneTitle.h"
#include "CameraObjBase.h"
#include "MeshRenderer.h"
#include "SpriteRenderer.h"
#include "Rigidbody.h"
#include "ObjectManager.h"
#include "Object3D.h"
#include "Cube.h"
#include "AABBCollider.h"

#include "Transform.h"
#include "CameraObjPlayer.h"
#include "Player.h"
#include "Enemy.h"
#include "Field.h"
#include "UI.h"

SceneTitle::SceneTitle()
{
	//--- �ύX�p�|�C���^
	std::shared_ptr<MeshRenderer> pMeshRenderer;	// 3D�I�u�W�F�N�g�p�����_���[
	std::shared_ptr<SpriteRenderer> pSpriteRenderer;// 2D�I�u�W�F�N�g�p�����_���[
	std::shared_ptr<Transform> pTransform;			// �ʒu���
	std::shared_ptr<Rigidbody> pRigidbody;			// ��������
	std::shared_ptr<AABBCollider> pAABBCollider;	// AABB�����蔻��p
	std::shared_ptr<CameraPlayer> pCameraPlayer;

	//2022/12/16�@���I��P
	//UI�̕`�悪�Ō�ɗ���悤�ɃN���G�C�g�̈ʒu���ŏ��Ɏ����Ă���
	//UI����--------------------------------------------------------------------------------
	ObjectManager::CreateObject<UI>("UI.2");
	pSpriteRenderer = ObjectManager::FindObjectWithName("UI.2")->GetComponent<SpriteRenderer>();
	pTransform = ObjectManager::FindObjectWithName("UI.2")->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/karizanki.png");	//2022/12/14 ���I��P�@�e�N�X�`����ύX
	pSpriteRenderer->SetSize(300, 80);
	ObjectManager::FindObjectWithName("UI.2")->SetLayerNum(1);
	pTransform->SetPosition({ 450.0f, 300.0f, 0.0f });

	//------------------------------------------------------------------------------------

	//--- �I�u�W�F�N�g�쐬
	//   �^�@�FCameraPlayer
	//  ���O �FCameraPlayer
	// �^�O���FCameraPlayer
	ObjectManager::CreateObject<CameraObjPlayer>("CameraPlayer", TagName::MainCamera);
	// CameraPlayer�̃|�C���^���擾����
	pCameraPlayer = ObjectManager::FindObjectWithName("CameraPlayer")->GetComponent<CameraPlayer>();
	// �p�x��ݒ肷��
	pCameraPlayer->SetRadY(40);
	pCameraPlayer->SetRadXZ(0.0f);

	//--- �I�u�W�F�N�g�쐬
	//   �^�@�FPlayer
	//  ���O �FPlayer
	// �^�O���FPlayer
	ObjectManager::CreateObject<Player>("Player", TagName::Player);
	// Transform�̃|�C���^���擾����
	pTransform = ObjectManager::FindObjectWithName("Player")->GetComponent<Transform>();
	// ���W��ݒ肷��
	pTransform->SetPosition({ 0.0f, 0.0f, 0.0f });

	for (int i = 0; i < 3; i++) {
		//--- �I�u�W�F�N�g�쐬
		//   �^�@�FEnemy
		//  ���O �FEnemy
		// �^�O���FEnemy
		std::shared_ptr<ObjectBase> pObj = ObjectManager::CreateObject<Enemy>("Enemy", TagName::Enemy);
		// Transform�̃|�C���^���擾����
		pTransform = pObj->GetComponent<Transform>();
		// ���W��ݒ肷��
		pTransform->SetPosition({ 2.0f, 0.0f, 2.0f });
	}

	//--- �I�u�W�F�N�g�쐬
	//   �^�@�FField
	//  ���O �FField
	// �^�O���FField
	ObjectManager::CreateObject<Field>("Field", TagName::Field);
	// Transform�̃|�C���^���擾����
	pTransform = ObjectManager::FindObjectWithName("Field")->GetComponent<Transform>();
	// ���W��ݒ�
	pTransform->SetPosition({ 0.0f, -5.0f, 0.0f });


}

SceneTitle::~SceneTitle()
{

}
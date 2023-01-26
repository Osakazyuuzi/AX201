#include "SceneGame01.h"
#include "MeshRenderer.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "ObjectManager.h"
#include "Ui.h"
#include "Game01.h"
#include "SBotton.h"
#include "FadeManager.h"

SceneGame01::SceneGame01()
{
	//--- �ύX�p�|�C���^
	std::shared_ptr<MeshRenderer> pMeshRenderer;	// 3D�I�u�W�F�N�g�p�����_���[
	std::shared_ptr<SpriteRenderer> pSpriteRenderer;// 2D�I�u�W�F�N�g�p�����_���[
	std::shared_ptr<Transform> pTransform;			// �ʒu���
	std::shared_ptr<Rigidbody> pRigidbody;			// ��������
	std::shared_ptr<ObjectBase> pObj;               //

	//--- �V�[���؂�ւ����Ȃ̂Ńt�F�[�h�C�����쐬
	FadeManager::CreateFadeIn();

	//--- UI�쐬
	//------------------------------------
	// 1/14 �|��
	//      �^�C�g���p�̉摜�ɍ����ւ�
	//------------------------------------
	// UI.1 �^�C�g�����
	ObjectManager::CreateObject<Game01>("UI.2");
	pSpriteRenderer = ObjectManager::FindObjectWithName("UI.2")->GetComponent<SpriteRenderer>();
	pTransform = ObjectManager::FindObjectWithName("UI.2")->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/Bg.png");
	pSpriteRenderer->SetSize(1280, 720);
	ObjectManager::FindObjectWithName("UI.2")->SetLayerNum(2);
	pTransform->SetPosition({ 0.0f, 0.0f, 0.0f });
	
	//------------------------------------
	// 1/17 �|��
	//      �{�^���A�j���[�V�����p�摜
	//------------------------------------
	pObj = ObjectManager::CreateObject<UI>("UI.3");
	pObj->SetLayerNum(4);
	pObj->AddComponent<SBtton>(); 
	pObj->AddComponent<SpriteAnimation>();
	pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	pSpriteRenderer->LoadTexture("Assets/Texture/Start.png");
	pSpriteRenderer->SetSize(460, 92);
	pTransform = pObj->GetComponent<Transform>();
	pTransform->SetPosition({ 0.0f, -153.0f, 0.0f });

	pObj = ObjectManager::CreateObject<UI>("UI.4");
	pObj->SetLayerNum(4);
	pObj->AddComponent<SBtton>();
	pObj->AddComponent<SpriteAnimation>();
	pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	pSpriteRenderer->LoadTexture("Assets/Texture/End1.png");
	pSpriteRenderer->SetSize(460, 92);
	pTransform = pObj->GetComponent<Transform>();
	pTransform->SetPosition({ 0.0f, -260.0f, 0.0f });
}

SceneGame01::~SceneGame01()
{

}
//----------------------------------------------
// 1/14  �|��
//       ���U���g�p�V�[���쐬
//----------------------------------------------
#include "SceneResult.h"
#include "Result.h"
#include "MeshRenderer.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "ObjectManager.h"
#include "Ui.h"
#include "ResultButton.h"
#include "FadeManager.h"

SceneResult::SceneResult()
{
	//--- �ύX�p�|�C���^
	std::shared_ptr<ObjectBase> pObj;
	std::shared_ptr<SpriteRenderer> pSpriteRenderer;// 2D�I�u�W�F�N�g�p�����_���[
	std::shared_ptr<Transform> pTransform;			// �ʒu���

	//--- �V�[���؂�ւ����Ȃ̂Ńt�F�[�h�C�����쐬
	FadeManager::CreateFadeIn();

	pObj = ObjectManager::CreateObject<Result>("UI.1");
	pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	pTransform = pObj->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/GameOver.png");
	pSpriteRenderer->SetSize(1280, 720);
	pObj->SetLayerNum(2);
	pTransform->SetPosition({ 0.0f, 0.0f, 0.0f });

	// �{�^���A�j���[�V�����p�摜
	pObj = ObjectManager::CreateObject<Result>("UI.2");
	pObj->SetLayerNum(3);
	pObj->AddComponent<ResultButton>();
	pObj->AddComponent<SpriteAnimation>();
	pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	pSpriteRenderer->LoadTexture("Assets/Texture/ResultButton.png");
	pSpriteRenderer->SetSize(600, 100);
	pTransform = pObj->GetComponent<Transform>();
	pTransform->SetPosition({ 18.0f, -202.0f, 0.0f });
}

SceneResult::~SceneResult()
{
}

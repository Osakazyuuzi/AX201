//----------------------------------------------
// 1/14  �|��
//       ���U���g�p�V�[���쐬
//----------------------------------------------
#include "SceneResult.h"
#include "MeshRenderer.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "ObjectManager.h"
#include "Ui.h"
#include "FadeManager.h"

SceneResult::SceneResult()
{
	//--- �ύX�p�|�C���^
	std::shared_ptr<ObjectBase> pObj;
	std::shared_ptr<SpriteRenderer> pSpriteRenderer;// 2D�I�u�W�F�N�g�p�����_���[
	std::shared_ptr<Transform> pTransform;			// �ʒu���

	FadeManager::CreateFadeIn();  //�V�[���������Ƀt�F�[�h

	pObj = ObjectManager::CreateObject<UI>("UI.1");
	pSpriteRenderer = pObj->GetComponent<SpriteRenderer>();
	pTransform = pObj->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/GameOver.png");
	pSpriteRenderer->SetSize(1280, 720);
	pObj->SetLayerNum(2);
	pTransform->SetPosition({ 0.0f, 0.0f, 0.0f });
}

SceneResult::~SceneResult()
{
}

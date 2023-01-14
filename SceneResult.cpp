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

SceneResult::SceneResult()
{
	//--- �ύX�p�|�C���^
	std::shared_ptr<MeshRenderer> pMeshRenderer;	// 3D�I�u�W�F�N�g�p�����_���[
	std::shared_ptr<SpriteRenderer> pSpriteRenderer;// 2D�I�u�W�F�N�g�p�����_���[
	std::shared_ptr<Transform> pTransform;			// �ʒu���
	std::shared_ptr<Rigidbody> pRigidbody;			// ��������

	ObjectManager::CreateObject<UI>("UI.1");
	pSpriteRenderer = ObjectManager::FindObjectWithName("UI.1")->GetComponent<SpriteRenderer>();
	pTransform = ObjectManager::FindObjectWithName("UI.1")->GetComponent<Transform>();
	pSpriteRenderer->LoadTexture("Assets/Texture/GameOver.png");
	pSpriteRenderer->SetSize(1280, 720);
	ObjectManager::FindObjectWithName("UI.1")->SetLayerNum(2);
	pTransform->SetPosition({ 0.0f, 0.0f, 0.0f });
}

SceneResult::~SceneResult()
{
}

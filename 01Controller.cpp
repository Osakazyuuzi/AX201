//-----------------------------------
//1/14 �|��
//     UIController���쐬
//1/17 Game01.h�����Ɏg�p
//     UIController����01Controller�ɖ��O�ƍs
//-----------------------------------
#include "01Controller.h"
#include "Input.h"
#include "SceneManager.h"
#include "SBotton.h"
#include "ObjectManager.h"
#include "FadeManager.h"
#include "WinUtil.h"
#include "TitleUI.h"

void Game01Controller::Start()
{
	m_NextScene = false;
	m_EndWnd = false;
	m_nSelect = 1;
	m_TitleHalf = false;
	m_TitleIV = { 1.0f,1.0f };
	m_TitleMoveOnece = false;
}

void Game01Controller::Update()
{
	if (!m_TitleMoveOnece)	TitleMove();

	//�G���^�[�������ƃQ�[���V�[���Ɉړ�
	if (m_NextScene)	
	{
		//SceneManager::LoadScene(SceneName::SceneTitle);
		FadeManager::CreateFadeOut(SceneName::SceneTitle);
	}
	if (m_EndWnd)
	{
		EndWindow();
	}
	if (IsKeyTrigger(VK_UP))
	{
		m_nSelect++;
	}
	else if (IsKeyTrigger(VK_DOWN))
	{
		m_nSelect++;
	}
	// ��Ȃ�I��
	if (m_nSelect % 2 == 1)
	{
		ObjectManager::FindObjectWithName("UI.3")->GetComponent<SBtton>()->Swapframe(1);
		ObjectManager::FindObjectWithName("UI.3")->GetComponent<SBtton>()->Play();
		ObjectManager::FindObjectWithName("UI.4")->GetComponent<SBtton>()->Swapframe(0);
		ObjectManager::FindObjectWithName("UI.4")->GetComponent<SBtton>()->Play();
	}
	// �����Ȃ疢�I��
	if (m_nSelect % 2 == 0)
	{
		ObjectManager::FindObjectWithName("UI.3")->GetComponent<SBtton>()->Swapframe(0);
		ObjectManager::FindObjectWithName("UI.3")->GetComponent<SBtton>()->Play();
		ObjectManager::FindObjectWithName("UI.4")->GetComponent<SBtton>()->Swapframe(1);
		ObjectManager::FindObjectWithName("UI.4")->GetComponent<SBtton>()->Play();
	}
	// �G���^�[�L�[��UI�؂�ւ�
	if (IsKeyTrigger(VK_RETURN))
	{
		if (m_nSelect % 2 == 1)
		{
			m_NextScene = true;
			ObjectManager::FindObjectWithName("UI.3")->GetComponent<SBtton>()->Swapframe(2);
			ObjectManager::FindObjectWithName("UI.3")->GetComponent<SBtton>()->Play();
		}
		if (m_nSelect % 2 == 0)
		{
			m_EndWnd = true;
			ObjectManager::FindObjectWithName("UI.4")->GetComponent<SBtton>()->Swapframe(2);
			ObjectManager::FindObjectWithName("UI.4")->GetComponent<SBtton>()->Play();
		}
	}
}

void Game01Controller::TitleMove()
{
	//�I���������ǂ���
	bool endflg = false;

	if (m_TitleIV.x <= 2.0f && m_TitleHalf == false)
	{
		m_TitleIV.x += 0.01f;
		m_TitleIV.y -= 0.005f;
		ObjectManager::FindObjectWithName("UI.6")->GetComponent<TitleUI>()->GetOwner()->GetComponent<SpriteRenderer>()->SetSize(DirectX::XMFLOAT2(m_TitleIV.x, m_TitleIV.y));
		if (m_TitleIV.x >= 2.0f)	m_TitleHalf = true;
	}
	if (m_TitleHalf)
	{
		m_TitleIV.x -= 0.2f;
		m_TitleIV.y += 0.01f;
		ObjectManager::FindObjectWithName("UI.6")->GetComponent<TitleUI>()->GetOwner()->GetComponent<SpriteRenderer>()->SetSize(DirectX::XMFLOAT2(m_TitleIV.x, m_TitleIV.y));
		//�����l�Ɠ����T�C�Y�ɖ߂�����t���O��܂�
		if (m_TitleIV.x <= 1.0f)	endflg = true;
	}

	if (endflg)	//�I�������̐F�ɖ߂��ăA�j���[�V�������t���O��������
	{
		ObjectManager::FindObjectWithName("UI.6")->GetComponent<TitleUI>()->GetOwner()->GetComponent<SpriteRenderer>()->SetSize(DirectX::XMFLOAT2(1.0f, 1.0f));	//�傫����߂�
		m_TitleHalf = false;
		m_TitleMoveOnece = true;
	}

}

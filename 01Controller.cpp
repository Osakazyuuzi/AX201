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
#include "EButton.h"
#include "WinUtil.h"

void Game01Controller::Start()
{
	m_NextScene = false;
	m_EndWnd = false;
	m_nSelect = 0;
}

void Game01Controller::Update()
{
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

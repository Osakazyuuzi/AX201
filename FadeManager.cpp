#include "FadeManager.h"
#include "ObjectManager.h"
#include "ObjectBase.h"
#include "FadeController.h"
#include "SceneManager.h"
#include "FadeObj.h"

SceneName::SceneName mName = SceneName::SceneName::SceneMax;

void FadeManager::CreateFadeIn()
{
	// �t�F�[�h�C���̃t�F�[�h�����݂��邩�`�F�b�N
	if (ObjectManager::FindObjectWithTag(TagName::FadeIn)) return;

	// �t�F�[�h���쐬����
	std::shared_ptr<ObjectBase> pObj;
	pObj = ObjectManager::CreateObject<FadeObj>("FadeIn", TagName::FadeIn);

	// �^�C�v���Z�b�g����
	pObj->GetComponent<FadeController>()->SetFadeType(FadeController::FadeType::Fade_In);
}

void FadeManager::CreateFadeOut(SceneName::SceneName name)
{
	// �t�F�[�h�A�E�g�̃t�F�[�h�����݂��邩�`�F�b�N
	if (ObjectManager::FindObjectWithTag(TagName::FadeOut)) return;

	// �t�F�[�h���쐬����
	std::shared_ptr<ObjectBase> pObj;
	pObj = ObjectManager::CreateObject<FadeObj>("FadeOut", TagName::FadeOut);

	// �t�F�[�h���I������Ƃ��Ƀ��[�h����V�[�����Z�b�g����
	pObj->GetComponent<FadeController>()->SetLoadScene(name);

	// �^�C�v���Z�b�g����
	pObj->GetComponent<FadeController>()->SetFadeType(FadeController::FadeType::Fade_Out);
}
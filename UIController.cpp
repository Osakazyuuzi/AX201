//-----------------------------------
//1/14 �|��
//     UIController���쐬
//
//-----------------------------------
#include "UIController.h"
#include "Input.h"
#include "SceneManager.h"

void UIController::Start()
{
}

void UIController::Update()
{
	//ENTER�������ƃQ�[���V�[���Ɉړ�
	if (IsKeyTrigger(VK_RETURN))
	{
		SceneManager::LoadScene(SceneName::SceneTitle);
	}
}

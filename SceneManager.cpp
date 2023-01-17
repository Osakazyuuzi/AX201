#include "SceneManager.h"
#include "ObjectManager.h"
#include "SceneTitle.h"
#include "SceneGame01.h"
#include "SceneResult.h"

bool SceneManager::m_bLoad = false;
SceneName::SceneName SceneManager::m_loadScene = SceneName::SceneGame01; // �X�^�[�g���^�C�g����ʂ���ɕύX

void SceneManager::LoadUpdate() {
	if (m_bLoad) {
		m_bLoad = false;
		// �I�u�W�F�N�g��S�폜
		ObjectManager::DestroyAllObject();

		// ���[�h�V�[���ŕ���
		switch (m_loadScene) {
		case SceneName::SceneGame01:
			SceneGame01();
			break;
		case SceneName::SceneTitle:
			SceneTitle();
			break;
		case SceneName::SceneResult:
			SceneResult();
			break;
		}
	}
}

void SceneManager::LoadScene(SceneName::SceneName scene) {
	m_loadScene = scene;
	m_bLoad = true;
}

int SceneManager::GetScene()
{
	return m_loadScene;
}

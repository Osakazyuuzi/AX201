#include "Game3D.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "Input.h"

Game3D::Game3D()
{
	// �^�C�g���V�[���֕ύX
	SceneManager::LoadScene(SceneName::SceneGame01); // �ŏ��̓^�C�g������X�^�[�g�ɕύX
}
Game3D::~Game3D()
{
}
void Game3D::Update()
{

	ObjectManager::FixedUpdate();
	ObjectManager::Update();
}

void Game3D::LateUpdate()
{
	ObjectManager::LateUpdate();
}

void Game3D::Draw()
{
	ObjectManager::Draw();
}
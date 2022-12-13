#include "ArrowController.h"
#include "ObjectBase.h"
#include "ObjectManager.h"
#include <DirectXMath.h>
#include "Transform.h"
#include "Rigidbody.h"

void ArrowController::Update()
{
	//--- ��̐i�s�����Ɍ��������킹��v���O����
	// ���݂̐��ʂ̃x�N�g��
	GetOwner()->GetComponent<Transform>()->GetVectorForword();
	// ���f���̐��ʕ����̃x�N�g��
	DirectX::XMFLOAT3 zVector = { 0.0f, 0.0f, -1.0f };
}

void ArrowController::OnCollisionEnter(ObjectBase* object)
{
	if (object->GetTag() == TagName::Enemy) {
		ObjectManager::RemoveObject(GetOwner()->GetThisPtr());
	}
}

void ArrowController::OnCollisionStay(ObjectBase* object)
{
}

void ArrowController::OnCollisionExit(ObjectBase* object)
{

}
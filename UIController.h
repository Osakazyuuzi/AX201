#ifndef ___UI_CONTROLLER_H___
#define ___UI_CONTROLLER_H__

#include "ComponentBase.h"
#include "ObjectBase.h"
#include <memory>
#include <DirectXMath.h>

class UIController : public ComponentBase
{
private:
	
public:
	// �R���X�g���N�^
	UIController() {};
	// �f�X�g���N�^
	~UIController() {};

	// ������
	void Start() override;
	// �X�V
	void Update()override;
};

#endif //!___UI_CONTROLLER_H___

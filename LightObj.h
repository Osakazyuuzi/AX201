#pragma once

#include "ObjectBase.h"
#include "light.h"

class LightObj : public ObjectBase
{
public:
	// �R���X�g���N�^
	LightObj(std::string name, std::string tag) : ObjectBase(name, tag) {
		AddComponent<light>();
	}
	// �f�X�g���N�^
	~LightObj() {}
};
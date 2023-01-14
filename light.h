#pragma once
#include <DirectXMath.h>
#include "ComponentBase.h"
#include "ConstantBuffer.h"

using namespace DirectX;

class light : public ComponentBase
{
public:
	//float pad  HLSL���̒萔�o�b�t�@�ł���float3�^�ϐ���16�̔{���̃A�h���X�ɔz�u����邯�ǁA
	//           C++��4�̔{���̃A�h���X�ɔz�u����邩��p�f�B���O�𖄂߂Ă����Ȃ��ƃf�[�^�̎󂯓n���ł��ꂽ�f�[�^���n���ꂿ�Ⴄ
	//          ��XMVECTOR��x,y,z,w�ŏo���Ă��邩��p�f�B���O�����Ȃ��Ă������Ǝ󂯓n������邩�珑���Ȃ��悤�ɁI
	struct Light
	{
		//XMVECTOR dirDirection;    //�f�B���N�V�������C�g�̕���      00  x,y,z,w
		XMFLOAT4 dirDirection;    //�f�B���N�V�������C�g�̕���      00  x,y,z,w
		XMFLOAT3 dirColor;        //�f�B���N�V�������C�g�̃J���[    16  x,y,z
		float pad;                //�p�f�B���O                      28  w

		XMFLOAT3 ptPosition;      //�|�C���g���C�g�̈ʒu            32  x,y,z
		float pad0;               //�p�f�B���O                      44  w
		XMFLOAT3 ptColor;         //�|�C���g���C�g�̐F              48  x,y,z
		float ptRange;            //�|�C���g���C�g�͈̔�            60  w

		XMFLOAT3 spPosition;      //�X�|�b�g���C�g�̈ʒu            64  x,y,z
		float spRange;            //�X�|�b�g���C�g�͈̔�            76  w
		XMFLOAT3 spColor;         //�X�|�b�g���C�g�̐F              80  x,y,z
		float spAngle;            //�X�|�b�g���C�g�̊p�x            92  w
		//XMVECTOR spDirection;     //�X�|�b�g���C�g�̕���            96  x,y,z,w
		XMFLOAT4 spDirection;     //�X�|�b�g���C�g�̕���            96  x,y,z,w

		XMFLOAT3 groundColor;     //�n�ʂ̐F
		float pad1;               //�p�f�B���O
		XMFLOAT3 skyColor;        //��̐F
		float pad2;               //�p�f�B���O
		//XMVECTOR groundNormal;    //�n�ʂ̖@��
		XMFLOAT4 groundNormal;    //�n�ʂ̖@��

		XMFLOAT3 eyePos;          //���_�̈ʒu                     
		float pad3;               //�p�f�B���O                     
		XMFLOAT3 ambientLIght;    //�A���r�G���g���C�g(����)      
		float pad4;               //�p�f�B���O
	};

public:
	light();
	~light();
	void Update() override;
	void SetLight();

private:
	Light m_Light;
	ConstantBuffer* m_pWVP;
};


//====================================
// ModelPS  ���f���p  �����V�^ 
//
//-----------���C�e�B���O�J�n-----------
// 2022/12/02  �f�B���N�V�������C�g�ǉ�
// 2022/12/04  ���ʔ��ˌ���ǉ�
// 2022/12/04  �����ǉ�
// 2022/12/07  �|�C���g���C�g�̒ǉ�
// 2022/12/08  �X�|�b�g���C�g�̒ǉ�
// 2022/12/09  �������C�g�ǉ�
// 2022/12/10  �������C�g�ǉ�
//-----------���C�e�B���O�I��-----------
//
//
//
//
//
//====================================

//******************************************
//******���_�V�F�[�_����󂯎��f�[�^******
//******�s�N�Z���V�F�[�_�ւ̓���      ******
//******************************************
struct PSIn
{
	float4 pos          : SV_POSITION;
	float3 normal       : NORMAL;
	float2 uv           : TEXCOORD0;
	float3 worldPos     : TEXCOORD1;
	float3 normalInView : TEXCOORD2;
};

//**************************************************************
//************���C�g�̃f�[�^���󂯎��o�b�t�@��p��************
//**************************************************************
cbuffer DirectionLightCb : register(b1)
{
	//�f�B���N�V�������C�g�̕ϐ�
	float3 dirDirection;  //����
	float3 dirColor;      //�F

	//�|�C���g���C�g�̕ϐ�
	float3 ptPosition;    //�ʒu
	float3 ptColor;       //�F
	float ptRange;        //�e���͈�

	//�X�|�b�g���C�g�̕ϐ�
	float3 spPosition;    //�ʒu
	float spRange;        //�e���͈�
	float3 spColor;       //�F
	float spAngle;        //�p�x
	float3 spDirection;   //����

	//�������C�g�̕ϐ�
	float3 groundColor;   //�n�ʂ̐F
	float3 skyColor;      //��̐F
	float3 groundNormal;  //�n�ʂ̖@��

	//���̑��̕ϐ�
	float3 eyePos;        //���_�̈ʒu
	float3 ambientLight;  //����
};

//****************
//****�֐��錾****
//****************
//�g�U���ˌ�
float3 CalcLambertDiffuse(float3 lightDirection, float3 lightColor, float3 normal);
//���ʔ��ˌ�
float3 CalcPhongSpecular(float3 lightDirection, float3 lightColor, float3 worldPos, float3 normal);
//�f�B���N�V�������C�g
float3 CalcLigFromDirectionLight(PSIn psin);
//�|�C���g���C�g
float3 CalcLigFromPointLight(PSIn psin);
//�X�|�b�g���C�g
float3 CalcLigFromSpotLight(PSIn psin);
//�������C�g
float3 CalcLigFromLimLight(PSIn psin);
//�������C�g
float3 CalcLigFromHemLight(PSIn psin);

//**************************
//*****���f���e�N�X�`��*****
//**************************
texture2D<float4> g_texture : register(t0);

//**************************
//****�T���v���[�X�e�[�g****
//**************************
sampler g_sampler : register(s0);

//**********************************************************
//******���f���p�̃s�N�Z���V�F�[�_�̃G���g���[�|�C���g******
//**********************************************************
float4 main(PSIn psin) : SV_Target0
{
	//========================
	//==�f�B���N�V�������C�g==
	//========================
	float3 directionLig = CalcLigFromDirectionLight(psin);

	//==================
	//==�|�C���g���C�g==
	//==================
	float3 pointLig = CalcLigFromPointLight(psin);

	//==================
	//==�X�|�b�g���C�g==
	//==================
	float3 spotLig = CalcLigFromSpotLight(psin);

	//==============
	//==�������C�g==
	//==============
	float3 limColor = CalcLigFromLimLight(psin);

	//==============
	//==�������C�g==
	//==============
	float3 hemLight = CalcLigFromHemLight(psin);

	//�ŏI�I�Ȕ��ˌ������߂�
	//�S�Ẵ��C�g�����Z����
	float3 finalLig = directionLig + limColor + hemLight + spotLig + pointLig + ambientLight; //ambientLight ���C�g�̌��ʂ��ꗥ�Œ�グ���� (�����͂��ꂾ��)  
	float4 finalColor = g_texture.Sample(g_sampler, psin.uv);//�e�N�X�`������J���[���t�F�b�`����

	//�ŏI�I�ȐF�Ɍ�����Z����
	finalColor.xyz *= finalLig;

	return finalColor;
}


//************************
//****�g�U���ˌ��̌v�Z****
//************************
float3 CalcLambertDiffuse(float3 lightDirection, float3 lightColor, float3 normal)
{
	//�s�N�Z���̖@���ƃ��C�g�̕����̓��ς��v�Z
	float t = dot(normal, lightDirection);
	t *= -1.0f; //���]

	//���ς̒l��0�ȏ�ɂ���
	t = max(0.0f, t);

	//�g�U���ˌ������߂�
	float3 diffuse = lightColor * t;

	//�G�l���M�[�ۑ��̖@����K�p
	diffuse /= 3.1415926;

	return diffuse;
}


//************************
//****���ʔ��ˌ��̌v�Z****
//************************
float3 CalcPhongSpecular(float3 lightDirection, float3 lightColor, float3 worldPos, float3 normal)
{
	//���˃x�N�g�������߂�
	float3 refVec = reflect(lightDirection, normal);

	//�������������T�[�t�F�C�X���王�_�̈ʒu�̃x�N�g�������߂�
	float3 toEye = eyePos - worldPos;
	toEye = normalize(toEye); //���K��

	//���ʔ��˂̋��������߂�
	float t = dot(refVec, toEye);

	//���ς̒l��0�ȏ�ɂ���
	t = max(0.0f, t);

	//���ʔ��˂̋������i�� �������̒l��ς���Ƌ������ς��
	t = pow(t, 5.0f);

	//���ʔ��ˌ������߂�
	return lightColor * t;
}


//****************************************
//*****�f�B���N�V�������C�g�̌����v�Z*****
//****************************************
float3 CalcLigFromDirectionLight(PSIn psin)
{
	//�g�U���ˌ������߂�
	float3 diffDirection = CalcLambertDiffuse(dirDirection, dirColor, psin.normal);
	//���ʔ��ˌ������߂�
	float3 specDirection = CalcPhongSpecular(dirDirection, dirColor, psin.worldPos, psin.normal);

	return diffDirection + specDirection;
}


//****************************************
//********�|�C���g���C�g�̌����v�Z********
//****************************************
float3 CalcLigFromPointLight(PSIn psin)
{
	//�T�[�t�F�C�X�ɓ��˂�����̌������v�Z
	float3 ligDir = psin.worldPos - ptPosition;
	ligDir = normalize(ligDir);

	//�g�U���ˌ������߂�
	float3 diffPoint = CalcLambertDiffuse(ligDir, ptColor, psin.normal);
	//���ʔ��ˌ������߂�
	float3 specPoint = CalcPhongSpecular(ligDir, ptColor, psin.worldPos, psin.normal);

	//�����ɂ��e�������v�Z
	float distance = length(psin.worldPos - ptPosition);
	float affect = 1.0f - 1.0f / ptRange * distance;
	if (affect < 0.0f) affect = 0.0f;
	affect = pow(affect, 3.0f);

	//�g�U���ˌ��Ƌ��ʔ��ˌ��ɉe��������Z���ĉe������߂�
	diffPoint *= affect;
	specPoint *= affect;

	return diffPoint + specPoint;
}


//****************************************
//********�X�|�b�g���C�g�̌����v�Z********
//****************************************
float3 CalcLigFromSpotLight(PSIn psin)
{
	//�T�[�t�F�C�X�ɓ��˂���X�|�b�g���C�g�̌��̌������v�Z
	float ligDir = psin.worldPos - spPosition;
	ligDir = normalize(ligDir);

	//�g�U���ˌ������߂�
	float3 diffSpotLight = CalcLambertDiffuse(ligDir, spColor, psin.normal);

	//���ʔ��ˌ������߂�
	float3 specSpotLight = CalcPhongSpecular(ligDir, spColor, psin.worldPos, psin.normal);

	//�e�������v�Z
	float3 distance = length(psin.worldPos - spPosition);
	float affect = 1.0f - 1.0f / spRange * distance;
	if (affect < 0.0f) affect = 0.0f;
	affect = pow(affect, 3.0f);

	//�e��������Z���Ĕ��ˌ�����߂�
	diffSpotLight *= affect;

	//���ˌ��Ǝˏo�����̊p�x�����߂�
	float angle = dot(ligDir, spDirection);
	angle = abs(acos(angle));

	//�p�x�ɂ��e���������߂�
	affect = 1.0f - 1.0f / spAngle * angle;
	if (affect < 0.0f) affect = 0.0f;
	affect = pow(affect, 0.5f);

	//�p�x�ɂ��e�����𔽎ˌ��ɏ�Z���Ď�߂�
	diffSpotLight *= affect;
	specSpotLight *= affect;

	return diffSpotLight + specSpotLight;
}


//****************************************
//**********�������C�g�̌����v�Z**********
//****************************************
float3 CalcLigFromLimLight(PSIn psin)
{
	//�T�[�t�F�C�X�̖@���ƌ��̓��˕����Ɉˑ����郊���̋��������߂�
	float power1 = 1.0f - max(0.0f, dot(dirDirection, psin.normal));

	//�T�[�t�F�C�X�̖@���Ǝ��_�̕����Ɉˑ����郊���̋��������߂�
	float power2 = 1.0f - max(0.0f, psin.normalInView.z * -1.0f);

	//�ŏI�I�ȃ����̋��������߂�
	float limPower = power1 * power2;
	limPower = pow(limPower, 1.3f);

	//�������C�g�̐F���v�Z
	return limPower * dirColor;
}


//****************************************
//**********�������C�g�̌����v�Z**********
//****************************************
float3 CalcLigFromHemLight(PSIn psin)
{
	//�T�[�t�F�C�X�̖@���ƒn�ʂ̖@���̓��ς��v�Z
	float t = dot(psin.normal, groundNormal);

	//���ς̌��ʂ�0�`1�̊Ԃɂ���
	t = (t + 1.0f) / 2.0f;

	//�n�ʂ̐F�Ƌ�̐F���ԗ�t�Ő��`���:lerp()   groundColor * (1.0f - t) + skyColor * t
	float3 hemLight = lerp(groundColor, skyColor, t);

	return hemLight;
}
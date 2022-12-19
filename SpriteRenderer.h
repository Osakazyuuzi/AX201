#ifndef ___SPRITERENDERER_H___
#define ___SPRITERENDERER_H___

#include "ComponentBase.h"
#include "DirectXTex/Texture.h"
#include "VertexBuffer.h"
#include "Shader.h"
#include "ConstantBuffer.h"
#include "BlendState.h"
#include "SamplerState.h"
#include <memory>
#include <list>
#include <DirectXMath.h>

class SpriteRenderer : public ComponentBase
{
public:

	struct AnimeUV {
		float uvWidth;		// 横幅
		float uvHeight;		// 縦幅
		float uvTopLeftU;	// 左上U座標
		float uvTopLeftV;	// 左上V座標
	};
	struct Info {
		// 頂点情報
		VertexBuffer* pVtxBuf;
		// UV情報
		AnimeUV animeUV;
		// テクスチャ
		ID3D11ShaderResourceView* pTexture;
		// 行列
		DirectX::XMFLOAT4X4 m_Mat[3];
	};

public:
	// コンストラクタ
	SpriteRenderer();
	// デストラクタ
	~SpriteRenderer();

	void Start();
	void LateUpdate();
	// 描画
	void Draw();
	void End();

	// テクスチャ読み込み
	ID3D11ShaderResourceView* LoadTexture(std::string);

	//--- セット関数
	void SetInfo(Info info) { m_SpriteInfo = info; }
	void SetSize(float width, float height);

	//--- ゲット関数
	Info* GetInfo() { return &m_SpriteInfo; }

private:
	static VertexShader* m_pDefVS;
	static PixelShader* m_pDefPS;
	static unsigned int m_shaderRef;
	static SamplerState* m_pSamplerState;
	static BlendState* m_pAlphaBlend;
	static ConstantBuffer* m_pConst[2];
	// テクスチャリスト
	static std::list<std::pair<std::string, ID3D11ShaderResourceView*>> m_TextureList;
private:
	Info m_SpriteInfo;
};

#endif //!___SPRITERENDERER_H___

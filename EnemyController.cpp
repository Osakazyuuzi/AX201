////////////////////////////
//編集履歴
//2022年12月16日　矢野　ノックバック追加
//2022年12月19日　矢野　EnemyのHPを追加
//2022年12月19日　矢野　中ボスを追加
//
//
//
#include "EnemyController.h"
#include "Transform.h"
#include "ObjectBase.h"
#include "Primitive.h"
#include "Vector3.h"
#include "Float3.h"
#include "ObjectManager.h"
#include "Arrow.h"
#include "PlayerController.h"
#include"EnemyRepop.h"
#include "AABBCollider.h"

void EnemyController::Start()
{
	GetOwner()->GetComponent<AABBCollider>()->SetTouchOBB(TagName::Ground);
	GetOwner()->GetComponent<AABBCollider>()->SetTouchOBB(TagName::Wall);
	GetOwner()->GetComponent<AABBCollider>()->SetTouchOBB(TagName::Arrow);
}

void EnemyController::Update()
{
	
	// 座標を保存する
	m_prevPos = GetOwner()->GetComponent<Transform>()->GetPosition();
	//当たり判定用のプレイヤーの座標
	DirectX::XMFLOAT3 HeadPlayerPos = ObjectManager::FindObjectWithTag(TagName::Player)->GetComponent<Transform>()->GetPosition();
	//当たり判定用のエネミーの座標
	DirectX::XMFLOAT3 HeadEnemyPos = GetOwner()->GetComponent<Transform>()->GetPosition();
	//--- Playerを追いかける処理
	DirectX::XMFLOAT3 rotateDirection;
	
	m_tic++;
	
	if (m_tic >= m_ChangeTargetTime) {
		m_tic = rand() % (int)m_ChangeTargetTime;
		// Playerタグのオブジェクトの座標を取得
		DirectX::XMFLOAT3 PlayerPos = ObjectManager::FindObjectWithTag(TagName::Player)->GetComponent<Transform>()->GetPosition();
		// ターゲットとなるプレイヤーの座標をランダムでずらす
		PlayerPos.x += rand() % 8 - 4;
		PlayerPos.z += rand() % 8 - 4;
		// ターゲットまでのベクトルを算出
		DirectX::XMVECTOR vTargetVector =
			DirectX::XMVectorSubtract(DirectX::XMLoadFloat3(&PlayerPos), DirectX::XMLoadFloat3(&GetOwner()->GetComponent<Transform>()->GetPosition()));
		// ベクトルを正規化
		vTargetVector = DirectX::XMVector3Normalize(vTargetVector);
		// 移動スピードを掛ける
		vTargetVector = DirectX::XMVectorScale(vTargetVector, m_MoveSpeed);
		// Float3に変換する
		DirectX::XMStoreFloat3(&m_TargetVector, vTargetVector);
	
		// 移動した場合、移動した方向に回転する
		if (m_TargetVector.x != 0.0f || m_TargetVector.y != 0.0f || m_TargetVector.z != 0.0f) {
			m_TargetRotY = 0.0f;
			// Z方向へのベクトル(モデルの正面方向のベクトル)
			DirectX::XMFLOAT3 zVector = { 0.0f, 0.0f, 1.0f };
			// 内積とベクトルの長さを使ってcosθを求める
			DirectX::XMStoreFloat(&m_TargetRotY, DirectX::XMVector3Dot(DirectX::XMVector3Normalize(vTargetVector), DirectX::XMLoadFloat3(&zVector)));
			// 内積から角度を求める
			m_TargetRotY = ::acos(m_TargetRotY);
			// ラジアン角からおなじみの角度に変更
			m_TargetRotY = DirectX::XMConvertToDegrees(m_TargetRotY);
			// 回転が右回転か左回転かを判別するために、外積で求める
			// 求めた外積のY成分がプラスだったら左回り。
			// 求めた外積のY成分がマイナスだったら右回り。
			DirectX::XMStoreFloat3(&rotateDirection, DirectX::XMVector3Cross(DirectX::XMVector3Normalize(vTargetVector), DirectX::XMLoadFloat3(&zVector)));
			if (rotateDirection.y > 0) m_TargetRotY = 180.0f + (180.0f - m_TargetRotY);
		}
	}
	
	if (m_EnemyMotionType == NORMAL)
	{
		//ノックバック後のスタン
		if (m_bKnockBackFlg)
		{
			m_FlgCount--;
			m_MoveSpeed = 0.0f;					//動きを止める為に0を設定
			m_TargetVector = { 0.0f,0.0f,0.0f };//動きを止める為に0を設定
			if (m_FlgCount <= 0)
			{
				//初期化処理
				m_MoveSpeed = 0.05f;	//速度を元に戻す
				m_bKnockBackFlg = false;
				m_FlgCount = 100.0f;
			}
		}
		//プレイヤーとエネミーの当たり判定
		//Enemyが一定範囲に入ると攻撃モーションになる
		if ((HeadPlayerPos.x - HeadEnemyPos.x) * (HeadPlayerPos.x - HeadEnemyPos.x) +
			(HeadPlayerPos.z - HeadEnemyPos.z) * (HeadPlayerPos.z - HeadEnemyPos.z) <=
			(m_EAttackErea + 0.5f)*(m_EAttackErea + 0.5f))
		{
			m_EnemyMotionType = ATTACK;
			m_MoveSpeed = 0.0f;
			m_TargetVector = { 0.0f,0.0f,0.0f };	//攻撃モーションに入る
		}
		else
		{
			m_MoveSpeed = 0.05f;//速度を元に戻す
		}
	}
	else if (m_EnemyMotionType == DEAD)
	{
		m_MoveSpeed = 0.0f;					//動きを止める為に0を設定
		m_TargetVector = { 0.0f,0.0f,0.0f };//動きを止める為に0を設定
		if (m_MoveStopCount >= 180.0f)	//動きを止める時間
		{
			m_MoveSpeed = 0.05f;	//速度を元に戻す
			DirectX::XMVECTOR DeadVector = DirectX::XMVectorZero();
			if (HeadEnemyPos.z <= -5.0f &&
				HeadEnemyPos.z >= -15.0f)
			{
				DeadVector =
					DirectX::XMVectorSubtract(DirectX::XMLoadFloat3(&m_DeadPos), DirectX::XMLoadFloat3(&GetOwner()->GetComponent<Transform>()->GetPosition()));
				// ベクトルを正規化
				DeadVector = DirectX::XMVector3Normalize(DeadVector);
				// 移動スピードを掛ける
				DeadVector = DirectX::XMVectorScale(DeadVector, m_MoveSpeed);
				// Float3に変換する
				DirectX::XMStoreFloat3(&m_TargetVector, DeadVector);
			}
			else {
				DirectX::XMFLOAT3 deadPos = m_DeadPos;
				DirectX::XMFLOAT3 myPos = GetOwner()->GetComponent<Transform>()->GetPosition();
				// X軸への移動を打ち消す
				deadPos.x = 0.0f;
				myPos.x = 0.0f;
				DeadVector =
					DirectX::XMVectorSubtract(DirectX::XMLoadFloat3(&deadPos), DirectX::XMLoadFloat3(&myPos));
				// ベクトルを正規化
				DeadVector = DirectX::XMVector3Normalize(DeadVector);
				// 移動スピードを掛ける
				DeadVector = DirectX::XMVectorScale(DeadVector, m_MoveSpeed);
				// Float3に変換する
				DirectX::XMStoreFloat3(&m_TargetVector, DeadVector);
			}

			// --- コピペした↓
			// 移動した場合、移動した方向に回転する
			if (m_TargetVector.x != 0.0f || m_TargetVector.y != 0.0f || m_TargetVector.z != 0.0f) {
				m_TargetRotY = 0.0f;
				// Z方向へのベクトル(モデルの正面方向のベクトル)
				DirectX::XMFLOAT3 zVector = { 0.0f, 0.0f, 1.0f };
				// 内積とベクトルの長さを使ってcosθを求める
				DirectX::XMStoreFloat(&m_TargetRotY, DirectX::XMVector3Dot(DirectX::XMVector3Normalize(DeadVector), DirectX::XMLoadFloat3(&zVector)));
				// 内積から角度を求める
				m_TargetRotY = ::acos(m_TargetRotY);
				// ラジアン角からおなじみの角度に変更
				m_TargetRotY = DirectX::XMConvertToDegrees(m_TargetRotY);
				// 回転が右回転か左回転かを判別するために、外積で求める
				// 求めた外積のY成分がプラスだったら左回り。
				// 求めた外積のY成分がマイナスだったら右回り。
				DirectX::XMStoreFloat3(&rotateDirection, DirectX::XMVector3Cross(DirectX::XMVector3Normalize(DeadVector), DirectX::XMLoadFloat3(&zVector)));
				if (rotateDirection.y > 0) m_TargetRotY = 180.0f + (180.0f - m_TargetRotY);
			}
		}
		//フレームカウントの初期化
		m_MoveStopCount++;
	}
	else if (m_EnemyMotionType == ATTACK)
	{
		m_EnemyMotionType = NORMAL;
	}

	// 座標に適用する
	GetOwner()->GetComponent<Transform>()->SetPosition({
		GetOwner()->GetComponent<Transform>()->GetPosition().x + m_TargetVector.x,
		GetOwner()->GetComponent<Transform>()->GetPosition().y,
		GetOwner()->GetComponent<Transform>()->GetPosition().z + m_TargetVector.z
		});

	// 二つの間の角度が180°超えていた場合、逆回転の方が速いため、補正
	if (abs(m_lateRotY - m_TargetRotY) >= 180.0f)
		if (m_TargetRotY < 0.0f) m_TargetRotY = (int)m_TargetRotY + 360;
		else if (m_TargetRotY >= 0.0f) m_TargetRotY = (int)m_TargetRotY - 360;
	// 180°を超えたもしくは、-180°以下になったときに範囲内に補正する
	if (m_lateRotY < -180)  m_lateRotY = ((int)(fabs(m_lateRotY) + 180) % 360 - 180) * -1.0f;
	if (180 <= m_lateRotY) m_lateRotY = (int)(m_lateRotY + 180) % 360 - 180;
	// 遅れてついていく場合の角度を計算し適応する
	m_lateRotY = (m_TargetRotY - m_lateRotY) * 0.05f + m_lateRotY;
	GetOwner()->GetComponent<Transform>()->SetAngle({ 0.0f, m_lateRotY,0.0f });
		
		//敵を削除
	if (GetOwner()->GetComponent<Transform>()->GetPosition().x <= -40.0f)
	{
		m_MoveStopCount = 0.0f;	//カウントの初期化
		ObjectManager::RemoveObject(GetOwner()->GetThisPtr());
	}
}

void EnemyController::OnCollisionEnter(ObjectBase* object)
{
	

	// フィールドと当たったときの処理
	if (object->GetTag() == TagName::Ground) {
		// Y軸の加速度をゼロに
		this->GetOwner()->GetComponent<Rigidbody>()->SetAccele({
			this->GetOwner()->GetComponent<Rigidbody>()->GetAccele().x,
			0.0f,
			this->GetOwner()->GetComponent<Rigidbody>()->GetAccele().z
			});

		// --- めり込んだ位置からY方向に戻し距離だけオフセットする
		float offsetPosY =
			object->GetComponent<AABBCollider>()->GetPrimitive().p.y +
			object->GetComponent<AABBCollider>()->GetPrimitive().hl.y +
			this->GetOwner()->GetComponent<AABBCollider>()->GetPrimitive().hl.y;
		this->GetOwner()->GetComponent<Transform>()->SetPosition({
			this->GetOwner()->GetComponent<Transform>()->GetPosition().x,
			offsetPosY,
			this->GetOwner()->GetComponent<Transform>()->GetPosition().z
			});
	}

	// 壁と当たったときの処理
	if (object->GetTag() == TagName::Wall) {
		GetOwner()->GetComponent<Transform>()->SetPosition(m_prevPos);
		// 加速度を補正
		GetOwner()->GetComponent<Rigidbody>()->SetAccele({ 0.0f, 0.0f, 0.0f });
	}


	// 矢と当たったときの処理
	if (m_EnemyMotionType == NORMAL || m_EnemyMotionType == ATTACK)
	{
		if (object->GetTag() == TagName::Arrow)
		{
			// 今プレイヤーが持っている矢であれば処理を行わない
			if (ObjectManager::FindObjectWithTag(TagName::Player)->GetComponent<PlayerController>()->GetHaveArrow()
				!= object->GetThisPtr()) {

				m_bKnockBackFlg = true;
				
				if (this->GetOwner()->GetTag() == TagName::MiddleBoss)
				{	
					//ノックバックとスタンをしない
					m_KnockbackPower = 0.0f;
					m_FlgCount = 0.0f;
					if (ArrowController::ARROW_TYPE::SUPER == object->GetComponent<ArrowController>()->GetArrowType())
					{
						//BossのHPを減らす
						m_BossHP--;
					}
				}
				else {
					//EnemyのHPを減らす
					m_Hp--;
					m_KnockbackPower = 0.7f;
				}
				//ノックバック　矢野12/16
				GetOwner()->GetComponent<Rigidbody>()->SetAccele({
					object->GetComponent<Rigidbody>()->GetAccele().x * m_KnockbackPower,
					object->GetComponent<Rigidbody>()->GetAccele().y * m_KnockbackPower,
					object->GetComponent<Rigidbody>()->GetAccele().z * m_KnockbackPower
					});

				// 自分を削除
				if (m_Hp == 0 || m_BossHP == 0)
				{
					m_EnemyMotionType = DEAD;
					
				}
			}
		}
	}
	
}

void EnemyController::OnCollisionStay(ObjectBase* object)
{
	// フィールドと当たったときの処理
	if (object->GetTag() == TagName::Ground) {
		// Y軸の加速度をゼロに
		this->GetOwner()->GetComponent<Rigidbody>()->SetAccele({
			this->GetOwner()->GetComponent<Rigidbody>()->GetAccele().x,
			0.0f,
			this->GetOwner()->GetComponent<Rigidbody>()->GetAccele().z
			});

		// --- めり込んだ位置からY方向に戻し距離だけオフセットする
		float offsetPosY =
			object->GetComponent<AABBCollider>()->GetPrimitive().p.y +
			object->GetComponent<AABBCollider>()->GetPrimitive().hl.y +
			this->GetOwner()->GetComponent<AABBCollider>()->GetPrimitive().hl.y;
		this->GetOwner()->GetComponent<Transform>()->SetPosition({
			this->GetOwner()->GetComponent<Transform>()->GetPosition().x,
			offsetPosY,
			this->GetOwner()->GetComponent<Transform>()->GetPosition().z
			});
	}

	// 壁と当たったときの処理
	if (object->GetTag() == TagName::Wall) {
		GetOwner()->GetComponent<Transform>()->SetPosition(m_prevPos);
		// 加速度を補正
		GetOwner()->GetComponent<Rigidbody>()->SetAccele({ 0.0f, 0.0f, 0.0f });
	}
}

void EnemyController::OnCollisionExit(ObjectBase* object)
{

}



#include "ColliderManager.h"

std::list<ColliderBase*> ColliderManager::m_ColliderList;

void ColliderManager::Update()
{
	//--- Enter&Stay
	for (auto it1 = m_ColliderList.begin(); it1 != m_ColliderList.end(); ++it1) {
		for (auto it2 = it1; it2 != m_ColliderList.end(); ++it2) {
			if (it1 == it2) continue;
			// 処理を呼び出す
			(*it2)->CallTouchOperation((*it1));
		}
	}

	//--- Exit
	for (auto it = m_ColliderList.begin(); it != m_ColliderList.end(); ++it) {
		(*it)->CheckExitCollider();
	}

	// 当たり判定リストを削除
	m_ColliderList.clear();
}
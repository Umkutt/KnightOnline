#ifndef __STLMAP_H_
#define __STLMAP_H_

#include <map>

//-----------------------------------------------------------------------------
template<class T> class CSTLMap {
private:
	std::map<unsigned int, T*> m_UserTypeMap;

public:
	typedef typename std::map<unsigned int, T*>::iterator Iterator;

public:
	int GetSize(void) {
		return m_UserTypeMap.size();
	}

	bool IsExist(unsigned int key) {
		return m_UserTypeMap.find(key) != m_UserTypeMap.end();
	}

	bool PutData(unsigned int key, T* pData) {
		return m_UserTypeMap.insert(std::make_pair(key, pData)).second;
	}

	T* GetData(unsigned int key) {
		auto itor = m_UserTypeMap.find(key);
		return (itor != m_UserTypeMap.end()) ? itor->second : NULL;
	}

	void DeleteData(unsigned int key) {
		auto itor = m_UserTypeMap.find(key);
		if(itor != m_UserTypeMap.end()) {
			delete itor->second;
			m_UserTypeMap.erase(itor);
		}
	}

	void DeleteAllData(void) {
		if(m_UserTypeMap.empty()) return;
		Iterator itor = m_UserTypeMap.begin();
		for(; itor!=m_UserTypeMap.end(); ++itor)
			delete itor->second;
		m_UserTypeMap.clear();
	}

	~CSTLMap(void) {
		DeleteAllData();
	}
};

#endif

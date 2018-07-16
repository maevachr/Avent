//
// Created by maeva on 16/07/18.
//

#include "HandleMgr.h"

template <typename DATA, typename HANDLE>
DATA* HandleMgr <DATA, HANDLE>::Acquire(HANDLE& handle){
    // if free list is empty, add a new one otherwise use first one found
    unsigned int index;
    if(m_FreeSlots.empty()){
        index = m_MagicNumbers.size();
        handle.Init(index);
        m_UserData.push_back(DATA());
        m_MagicNumbers.push_back(handle.GetMagic());
    } else {
        index = m_FreeSlots.back();
        handle.Init(index);
        m_FreeSlots.pop_back();
        m_MagicNumbers[index] = handle.GetMagic();
    }
    return (m_UserData.begin() + index);
};

template <typename DATA, typename HANDLE>
void HandleMgr <DATA, HANDLE>::Release(HANDLE handle) {
    // which one ?
    unsigned int index = handle.GetIndex();

    //make sure it's valid
    assert(index < m_UserData.size());
    assert(m_MagicNumbers[index] == handle.GetMagic());

    //ok remove it - tag as unused and add to free list
    m_MagicNumbers[index] = 0;
    m_FreeSlots.push_back(index);
}

template <typename DATA, typename HANDLE>
inline DATA* HandleMgr <DATA, HANDLE> :: Dereference(HANDLE handle){
    if(handle.IsNull()) return (0);

    // check handle validity - $ this check can be removed for speed
    // if you can assume all handle references are always valid.
    unsigned int index = handle.GetIndex();
    if((index >= m_UserData.size()) || (m_MagicNumbers[index] != handle.GetMagic())){
        // no good! invalid handle == client programming error
        assert(0);
        return (0);
    }
    return (m_UserData.begin() + index);
};

template <typename DATA, typename HANDLE>
inline const DATA* HandleMgr<DATA, HANDLE>::Dereference(HANDLE handle) const {
    // this lazy cast is ok - non-const version does not modify anything
    using ThisType = HandleMgr<DATA, HANDLE>;
    return (const_cast<ThisType*> (this)->Dereference(handle));
}

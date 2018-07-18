//
// Created by maeva on 16/07/18.
//

#ifndef AVENT_HANDLEMGR_H
#define AVENT_HANDLEMGR_H

#include <vector>
#include <cassert>
#include "Handle.h"

template <typename DATA, typename HANDLE>
class HandleMgr {
private:
    //private types
    using UserVec = std::vector<DATA>;
    using MagicVec = std::vector<unsigned int>;
    using FreeVec = std::vector<unsigned int>;

    //private data
    UserVec m_UserData;         // data we're going to get to
    MagicVec m_MagicNumbers;    // corresponding magic number
    FreeVec m_FreeSlots;        //keep track of free slots in the db
public:
//Lifetime
    HandleMgr() = default;
    ~HandleMgr() = default;

//Handle methods
    //acquisition
    DATA* Acquire(HANDLE& handle);
    void Release(HANDLE handle);

    //dereferencing
    DATA* Dereference(HANDLE handle);
    const DATA* Dereference(HANDLE handle) const;

    //other query
    unsigned  int GetUsedHandleCount() const { return static_cast<unsigned int>(m_MagicNumbers.size() - m_FreeSlots.size()); }

    bool HasUsedHandles() const { return (GetUsedHandleCount() != 0);}
};


template <typename DATA, typename HANDLE>
DATA* HandleMgr <DATA, HANDLE>::Acquire(HANDLE& handle){
    // if free list is empty, add a new one otherwise use first one found
    unsigned int index;
    if(m_FreeSlots.empty()){
        index = static_cast<unsigned int>(m_MagicNumbers.size());
        handle.Init(index);
        m_UserData.push_back(DATA());
        m_MagicNumbers.push_back(handle.GetMagic());
    } else {
        index = m_FreeSlots.back();
        handle.Init(index);
        m_FreeSlots.pop_back();
        m_MagicNumbers[index] = handle.GetMagic();
    }
    return &(*(m_UserData.begin() + index));
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

    delete &(*(m_UserData.begin() + index));
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
    return &(*(m_UserData.begin() + index));
};

template <typename DATA, typename HANDLE>
inline const DATA* HandleMgr<DATA, HANDLE>::Dereference(HANDLE handle) const {
    // this lazy cast is ok - non-const version does not modify anything
    using ThisType = HandleMgr<DATA, HANDLE>;
    return (const_cast<ThisType*> (this)->Dereference(handle));
}



#endif //AVENT_HANDLEMGR_H

//
// Created by maeva on 16/07/18.
//

#ifndef AVENT_HANDLEMGR_H
#define AVENT_HANDLEMGR_H

#include <vector>
#include <cassert>

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
    unsigned  int GetUsedHandleCount() const { return (m_MagicNumbers.size() - m_FreeSlots.size()); }

    bool HasUsedHandles() const { return (!!GetUsedHandleCount());}
};


#endif //AVENT_HANDLEMGR_H

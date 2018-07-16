//
// Created by maeva on 16/07/18.
//

#include "Handle.h"
template <typename TAG>
void Handle<TAG>::Init(unsigned int index) {
    assert(IsNull());           // don't allow reassignment
    assert(index <= MAX_INDEX);  // verify range

    static unsigned int s_AutoMagic = 0;
    if( ++s_AutoMagic > MAX_MAGIC){
        s_AutoMagic = 1;
    }

    m_Index = index;
    m_Magic = s_AutoMagic;
}

template <typename TAG>
inline bool operator != (Handle <TAG> l, Handle <TAG> r){
    return (l.GetHandle() != r.GetHandle());
}

template <typename TAG>
inline bool operator == (Handle <TAG> l, Handle<TAG> r){
    return (l.GetHandle() == r.GetHandle());
}
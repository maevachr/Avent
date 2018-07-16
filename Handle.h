//
// Created by maeva on 16/07/18.
//

#ifndef AVENT_HANDLE_H
#define AVENT_HANDLE_H

#include <cassert>

template <typename TAG>
class Handle {
    union {
        enum {
            //sizes to use for bit fields
                    MAX_BITS_INDEX = 16,
            MAX_BITS_MAGIC = 16,

            //sizes to compare against for asserting dereferences
                    MAX_INDEX = (1 << MAX_BITS_INDEX) - 1,
            MAX_MAGIC = (1 << MAX_BITS_MAGIC) - 1,
        };

        struct {
            unsigned m_Index : MAX_BITS_INDEX; // index into resource array
            unsigned m_Magic : MAX_BITS_MAGIC; // magic number to check
        };
        unsigned int m_Handle;
    };
public:
    // Lifetime
    Handle() : m_Handle(0) {}

    void Init(unsigned int index);

    // Query
    unsigned int GetIndex() const { return (m_Index); }

    unsigned int GetMagic() const { return (m_Magic); }

    unsigned int GetHandle() const { return (m_Handle); }

    bool IsNull() const { return (!m_Handle); }

    operator unsigned int() const { return (m_Handle); }

};


#endif //AVENT_HANDLE_H

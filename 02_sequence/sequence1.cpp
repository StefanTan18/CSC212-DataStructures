// FILE: sequence1.cpp
// CLASS IMPLEMENTED: sequence  (See sequence1.h for documentation.)
// INVARIANT for the sequence class:
//   1. The number of items in the sequence is in the member variable m_used;
//   2. For an empty sequence, we do not care what is stored in any of m_data; for a
//      non-empty sequence the items in the sequence are stored in m_data[0] through
//      m_data[m_used-1], and we don't care what's in the rest of m_data.
//   3. If there is a current item, then it lies in data[m_current_index]; 
//      if there is no current item, then m_current_index equals m_used.

#include <iostream>
#include <cstdlib>
#include <cassert>
#include "sequence1.h"
using namespace std;

namespace main_savitch_3 //ADD COMMENTS TO MEMBER FUNCTIONS
{
    const sequence::size_type sequence::CAPACITY;

    sequence::sequence()
    {
        m_used = 0;
        m_current_index = m_used;
    }

    void sequence::start()
    {
        m_current_index = 0;
    }

    void sequence::advance()
    {
        assert(is_item());
        m_current_index++;
    }

    void sequence::insert(const value_type& entry)
    {
        assert(size() < CAPACITY);
        if (size() == 0) {
            m_data[0] = entry;
        }
        else {
            for (size_type i = size(); i > m_current_index; i--) {
                m_data[i] = m_data[i - 1];
            }
            m_data[m_current_index] = entry; 
        }
        m_used++;
    }

    void sequence::attach(const value_type& entry)
    {
        //CODE HERE
    }

    void sequence::remove_current()
    {
        //CODE HERE
    }

    sequence::size_type sequence::size() const
    {
        return m_used;
    }

    bool sequence::is_item() const
    {
        return (m_current_index != m_used);
    }

    sequence::value_type sequence::current() const
    {
        assert(is_item());
        return m_data[m_current_index];
    }
}
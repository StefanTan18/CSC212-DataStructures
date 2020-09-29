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
#include <cassert>  // Provides assert
#include "sequence1.h"
using namespace std;

namespace main_savitch_3
{
    const sequence::size_type sequence::CAPACITY;

    // Intializes an empty sequence
    sequence::sequence()
    {
        m_used = 0;
        m_current_index = m_used;
    }

    // The first item becomes the current item
    // If the sequence is empty then there is no current item
    void sequence::start()
    {
        m_current_index = 0;
    }

    // The item after the current item becomes the new current item
    //If the current item is the last item in the sequence, then there is no longer any current item
    void sequence::advance()
    {
        assert(is_item());
        m_current_index++;
    }

    // Entry is inserted before the current item and is the new current item
    // If there is no current item, then it is inserted in the front of the sequence
    void sequence::insert(const value_type& entry)
    {
        assert(size() < CAPACITY);
        // If the sequence is empty then entry is the first item
        if (size() == 0) {
            m_data[0] = entry;
        }
        else {
            // Inserts item at the front when there's no current item
            if (m_current_index == m_used) {
                m_current_index = 0;
            }
            // Moves items after current item back one
            for (size_type i = size(); i > m_current_index; i--) {
                m_data[i] = m_data[i - 1];
            }
            m_data[m_current_index] = entry; 
        }
        m_used++;
    }

    // Entry is inserted after the current item and is the new current item
    // If there is no current item, then it is inserted at the end of the sequence
    void sequence::attach(const value_type& entry)
    {
        assert(size() < CAPACITY);
        // If the sequence is empty then entry is the first item
        if (size() == 0) {
            m_data[0] = entry;
        }
        else {
            // Inserts item at the end when there's no current item
            if (m_current_index == m_used) {
                m_current_index = size() - 1;
            }
            m_current_index++;
            // Moves items after current item back one
            for (size_type i = size(); i > m_current_index; i--) {
                m_data[i] = m_data[i - 1];
            }
            m_data[m_current_index] = entry;
        }
        m_used++;
    }

    // The current item is removed from the sequence
    // If there is a item after the current item then it becomes the new current item
    void sequence::remove_current()
    {
        assert(is_item());
        // Moves every item after the current item forward one item
        for (size_type i = m_current_index + 1; i < size(); i++) {
            m_data[i - 1] = m_data[i];
        }
        m_used--;
    }

    // Returns the number of items in the sequence
    sequence::size_type sequence::size() const
    {
        return m_used;
    }

    // Returns whether or not there exists a current item
    bool sequence::is_item() const
    {
        return (m_current_index != m_used);
    }

    // Returns the current item in the sequence
    sequence::value_type sequence::current() const
    {
        assert(is_item());
        return m_data[m_current_index];
    }
}
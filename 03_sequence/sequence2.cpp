// FILE: sequence2.cpp
// CLASS IMPLEMENTED: sequence  (See sequence2.h for documentation.)
// INVARIANT for the sequence class:
//   1. The number of items in the sequence is in the member variable m_used;
//   2. The actual items of the sequence is stored in a partially filled 
//      array. The array is a dynamic array, pointed to by the member 
//      variable m_data.
//   3. The total size of the dynamic array is stored in the member 
//      variable m_capacity.
//   4. If there is a current item, then it lies in data[m_current_index]; 
//      if there is no current item, then m_current_index equals m_used.

#include <iostream>
#include <cstdlib>
#include <algorithm> // Provides copy function
#include <cassert>   // Provides assert function
#include "sequence2.h"
using namespace std;

namespace main_savitch_4
{
    const sequence::size_type sequence::DEFAULT_CAPACITY;

    // Constructor, intializes an empty sequence with a capacity of intial_capacity
    sequence::sequence(size_type intial_capacity)
    {
        m_data = new value_type[intial_capacity];
        m_capacity = intial_capacity;
        m_used = 0;
        m_current_index = m_used;
    }

    // Constructor, intializes an sequence that is a copy of source
    sequence::sequence(const sequence& source)
    {
        m_data = new value_type[source.m_capacity];
        m_capacity = source.m_capacity;
        m_used = source.m_used;
        m_current_index = source.m_current_index;
        copy(source.m_data, source.m_data + m_used, m_data);
    }

    // Destructor, releases dynamic memory when its no longer being used
    sequence::~sequence()
    {
        delete [] m_data;
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
        // Resizes the dynamic array if there is no more capacity to insert an item
        if (size() == m_capacity) {
            resize(2 * m_capacity);
        }
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
        // Resizes the dynamic array if there is no more capacity to insert an item
        if (size() == m_capacity) {
            resize(2 * m_capacity);
        }
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

    // Sequence's current capacity is changed to new_capacity through dynamic allocation
    void sequence::resize(size_type new_capacity)
    {
        value_type *larger_array;

        if (new_capacity == m_capacity) {
            return;     // The array is already the correct size
        }
        if (new_capacity < m_used) {
            new_capacity = m_used;     // Can't allocate less than we are using;
        }
        larger_array = new value_type[new_capacity];
        copy(m_data, m_data + m_used, larger_array);
        delete [] m_data;
        m_data = larger_array;
        m_capacity = new_capacity;
    }

    // Assignment Operator, assigns a sequence to be a copy of source
    void sequence::operator=(const sequence& source)
    {
        value_type *new_data;

        // Checks for self-assignment
        if (this == &source) {
            return;
        }
        if (m_capacity != source.m_capacity) {
            new_data = new value_type[source.m_capacity];
            delete [] m_data;
            m_data = new_data;
            m_capacity = source.m_capacity;
        }
        m_used = source.m_used;
        m_current_index = source.m_current_index;
        copy(source.m_data, source.m_data + m_used, m_data);
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
// FILE: sequence3.cpp
// CLASS IMPLEMENTED: sequence  (See sequence3.h for documentation.)
// INVARIANT for the sequence class:
//   1. The items in the sequence are stored in a linked list.
//   2. The head pointer of the list is stored in the member variable
//      m_head_ptr.
//   2. The tail pointer of the list is stored in the member variable
//      m_tail_ptr.
//   3. The pointer to the node with the current item is stored in the
//      member variable m_cursor. If there is no current item, then
//      m_cursor will point to NULL.
//   4. The pointer to the node before the current item is stored in the
//      member variable m_precursor. If there is no current item or the
//      current item is the first item, then m_precursor will point to
//      NULL.
//   5. The total number of items in the list is stored in the member
//      variable m_many_nodes.

#include <iostream>
#include <cstdlib>
#include <cassert>   // Provides assert function
#include "sequence3.h"
using namespace std;

namespace main_savitch_5
{
    sequence::sequence()
    {
        //WRITE CODE
    }

    sequence::sequence(const sequence& source)
    {
        //WRITE CODE
    }

    sequence::~sequence()
    {
        //WRITE CODE
    }

    void sequence::start()
    {
        //WRITE CODE
    }

    void sequence::advance()
    {
        //WRITE CODE
    }

    void sequence::insert(const value_type& entry)
    {
        //WRITE CODE
    }

    void sequence::attach(const value_type& entry)
    {
        //WRITE CODE
    }

    void sequence::remove_current()
    {
        //WRITE CODE
    }

    void sequence::operator=(const sequence& source)
    {
        //WRITE CODE
    }

    sequence::size_type sequence::size() const
    {
        return m_many_nodes;
    }

    bool sequence::is_item() const
    {
        //WRITE CODE
    }

    sequence::value_type sequence::current() const
    {
        //WRITE CODE
    }
}
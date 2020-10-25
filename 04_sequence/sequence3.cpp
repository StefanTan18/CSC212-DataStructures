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
    // Default Constructor, intializes an empty sequence
    sequence::sequence()
    {
        m_head_ptr = NULL;
        m_tail_ptr = NULL;
        m_cursor = NULL;
        m_precursor = NULL;
        m_many_nodes = 0;
    }

    // Copy Constructor, intializes a sequence that is a copy of the source
    sequence::sequence(const sequence& source)
    {
        // Handles the case when the source sequence has no current item
        if (!source.is_item()) {
            list_copy(source.m_head_ptr, m_head_ptr, m_tail_ptr);
            m_cursor = NULL;
            m_precursor = NULL;
        }
        // Handles the case when the current item of the source sequence is the first item
        else if (source.m_cursor == source.m_head_ptr) {
            list_copy(source.m_head_ptr, m_head_ptr, m_tail_ptr);
            m_cursor = m_head_ptr;
            m_precursor = NULL;
        }
        // Handles the case when the current item of the source sequence is after the first item
        else {
            list_piece(source.m_head_ptr, source.m_cursor, m_head_ptr, m_precursor);
            list_piece(source.m_cursor, source.m_tail_ptr, m_cursor, m_tail_ptr);
            m_precursor->set_link(m_cursor);
        }
        m_many_nodes = source.m_many_nodes;
    }

    // Destructor, releases dynamic memory when its no longer being used
    sequence::~sequence()
    {
        list_clear(m_head_ptr);
        m_cursor = NULL;
        m_precursor = NULL;
        m_many_nodes = 0;
    }

    // The first item becomes the current item
    // If the sequence is empty then there is no current item
    void sequence::start()
    {
        m_cursor = m_head_ptr;
        m_precursor = NULL;
    }

    // The item after the current item becomes the new current item
    //If the current item is the last item in the sequence, then there is no longer any current item
    void sequence::advance()
    {
        assert(is_item());
        m_precursor = m_cursor;
        m_cursor = m_cursor->link();
    }

    // Entry is inserted before the current item and is the new current item
    // If there is no current item, then it is inserted in the front of the sequence
    void sequence::insert(const value_type& entry)
    {
        // The entry is the first item if the sequence is empty
        if (size() == 0) {
            list_head_insert(m_head_ptr, entry);
            m_tail_ptr = m_head_ptr->link();
            m_cursor = m_head_ptr;
            m_precursor = NULL;
        }
        // The entry inserted in the front when there's no current item
        // or the current item is the first item
        else if (!is_item() || m_cursor == m_head_ptr) {
            list_head_insert(m_head_ptr, entry);
            m_cursor = m_head_ptr;
            m_precursor = NULL;
        }
        else {
            list_insert(m_precursor, entry);
            m_cursor = m_precursor->link();
        }
        m_many_nodes++;
    }

    // Entry is inserted after the current item and is the new current item
    // If there is no current item, then it is inserted at the end of the sequence
    void sequence::attach(const value_type& entry)
    {
        // The entry is the first item if the sequence is empty
        if (size() == 0) {
            list_head_insert(m_head_ptr, entry);
            m_tail_ptr = m_head_ptr->link();
            m_cursor = m_head_ptr;
            m_precursor = NULL;
        }
        // Inserts the item at the end when there's no current item
        else if (!is_item()) {
            node* temp = m_head_ptr;
            // Assigns temp to be the pointing to the last node using a loop 
            while (temp->link() != m_tail_ptr) {
                temp = temp->link();
            }
            list_insert(temp, entry);
            m_precursor = temp;
            m_cursor = m_precursor->link();
            m_tail_ptr = m_cursor->link();
        }
        else {
            list_insert(m_cursor, entry);
            m_precursor = m_cursor;
            m_cursor = m_cursor->link();
        }
        m_many_nodes++;
    }

    // The current item is removed from the sequence
    // If there is a item after the current item then it becomes the new current item
    void sequence::remove_current()
    {
        assert(is_item());
        // Handles the case when the cursor is on the first item of the sequence
        if (m_cursor == m_head_ptr) {
            m_cursor = m_cursor->link();
            list_head_remove(m_head_ptr);
        }
        else {
            m_cursor = m_cursor->link();
            list_remove(m_precursor);
        }
        m_many_nodes--;
    }

    // Assignment Operator, assigns a sequence to be a copy of source
    void sequence::operator=(const sequence& source)
    {
        // Checks for self-assignment
        if (this == &source) {
            return;
        }
        list_clear(m_head_ptr);
        m_many_nodes = 0;   // Ensures the sequence is valid before calling list_copy

        // Handles the case when the source sequence has no current item
        if (!source.is_item()) {
            list_copy(source.m_head_ptr, m_head_ptr, m_tail_ptr);
            m_cursor = NULL;
            m_precursor = NULL;
        }
        // Handles the case when the current item of the source sequence is the first item
        else if (source.m_cursor == source.m_head_ptr) {
            list_copy(source.m_head_ptr, m_head_ptr, m_tail_ptr);
            m_cursor = m_head_ptr;
            m_precursor = NULL;
        }
        // Handles the case when the current item of the source sequence is after the first item
        else {
            list_piece(source.m_head_ptr, source.m_cursor, m_head_ptr, m_precursor);
            list_piece(source.m_cursor, source.m_tail_ptr, m_cursor, m_tail_ptr);
            m_precursor->set_link(m_cursor);
        }
        m_many_nodes = source.m_many_nodes;
    }

    // Returns the number of items in the sequence
    sequence::size_type sequence::size() const
    {
        return m_many_nodes;
    }

    // Returns whether or not there exists a current item    
    bool sequence::is_item() const
    {
        return (m_cursor != NULL);
    }

    // Returns the current item in the sequence
    sequence::value_type sequence::current() const
    {
        assert(is_item());
        return m_cursor->data();
    }
}
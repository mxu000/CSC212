//Mingzhi Xu
//mxu000@citymail.cuny.edu

#include <cassert>
#include "sequence3.h"
using namespace std;
//INVARIANTS
//head_pt is a node pointer that points to the first node
//tail_pt is a node pointer that points to the last node
//cursor is a node pointer that points to current item
//precursor is a node point that points to the item before cursor
// if cursor is pointing to the head_pt then precursor should be null
//num keeps track of how many elements are used
namespace main_savitch_5
{
    sequence::sequence()//Run Time Analysis Linked:O(1) Dynamic:O(1)
    {
        head_pt = NULL;
        tail_pt = NULL;
        cursor = NULL;
        precursor = NULL;
        num = 0;
    }
    sequence::sequence(const sequence& source)//Run Time Analysis Linked:O(n) Dynamic:O(n)
    {
        list_copy(source.head_pt, head_pt, tail_pt);//function from node1
        num = source.size();//adjust num
        start();//set cursor to head_pt and precursor to NULL
        node* temp;
        for(temp = source.head_pt; temp != NULL; temp = temp ->link())
        {
            if(temp == source.cursor) return;
            precursor = cursor;
            cursor = cursor ->link();
        }
        //similar to list_search but finds both cursor and precursor in one for loop
    }

    sequence::~sequence()//Run Time Analysis Linked:O(n) Dynamic:O(n) list_clear uses a while loop
    {
        list_clear(head_pt);//function from node1
    }
    void sequence::start()//Run Time Analysis Linked:O(1) Dynamic:O(1)
    {
        cursor = head_pt;
        precursor = NULL;
    }
    void sequence::advance()//Run Time Analysis Linked:O(1) Dynamic:O(1)
    {
        assert(is_item());
        precursor = cursor;
        cursor = cursor->link();
    }
    void sequence::insert(const value_type& entry)//Run Time Analysis Linked:O(1) no loops were needed Dynamic:O(n) for loop was needed to move the objects
    {
        if(is_item() && precursor != NULL)//check if cursor is pointing at something and not at head_pt
        {
            list_insert(precursor, entry);//function from node1
            cursor = precursor->link();
        }
        else//if cursor points at empty or at head_pt
        {
                list_head_insert(head_pt, entry);//function from node1
                start();//set cursor to point at head_pt and precursor to NULL
        }
        num++;
    }
    void sequence::attach(const value_type& entry)//Run Time Analysis Linked:O(1) no loops were needed Dynamic:O(n) for loop was needed to move the objects
    {
        if(is_item())//cursor points at object exist
        {
            list_insert(cursor,entry);//function from node1
            precursor = cursor;
            cursor = cursor->link();
        }
        else//cursor points at null
        {
            if(precursor == NULL)//cursor points at head_pt
            {
                list_head_insert(head_pt,entry);
                start();//set cursor to point at head_pt and precursor to NULL
            }
            else
            {
                list_insert(precursor, entry);
                cursor = precursor->link();
            }
        }
        num++;
    }
    void sequence::remove_current()//Run Time Analysis Linked:O(1) no loops were needed Dynamic:O(n) for loop was used to remove the object
    {
        assert(is_item());
        if(cursor == head_pt)
        {
            list_head_remove(head_pt);//function from node1
            start();
        }
        else
        {
            cursor = cursor ->link();
            list_remove(precursor);
        }
        num--;
    }
    void sequence::operator=(const sequence& source)//Run Time Analysis Linked:O(n) Dynamic:O(n) for loop was used to copy the objects
    {
        if(this == &source) return;
        list_clear(head_pt);//function from node1 remove using while loop
        list_copy(source.head_pt, head_pt, tail_pt);//functions from node1 copies from source
        num = source.size(); //adjust num
        start();
        node* temp;
        for(temp = source.head_pt; temp != NULL; temp = temp ->link())
        {
            if(temp == source.cursor) return;
            precursor = cursor;
            cursor = cursor ->link();
        }
        //similar to list_search but finds both cursor and precursor in one for loop
    }

    size_t sequence::size() const//Run Time Analysis Linked:O(1) Dynamic:O(1)
    {
        return num;
    }
    bool sequence::is_item() const//Run Time Analysis Linked:O(1) Dynamic:O(1)
    {
        return cursor != NULL;
    }
    sequence::value_type sequence::current() const//Run Time Analysis Linked:O(1) Dynamic:O(1)
    {
        return cursor->data();
    }
}

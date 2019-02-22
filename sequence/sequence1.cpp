// Provided by:   ____________Mingzhi Xu__________
// Email Address: ____________mxu000@citymail.cuny.edu________
// FILE: sequence1.cpp

#include "sequence1.h"
#include <cassert>
#include <cstdlib>

namespace main_savitch_3
{
    sequence::sequence()
    {
        count = 0;
        index = 0;
    }
    void sequence::start()
    {
        index = 0;
    }
    void sequence::advance()
    {
        assert(is_item());
        if(index < count) index++;
    }
    void sequence::insert(const value_type& entry)
    {
        assert(size() < CAPACITY);
        if(!is_item())//no object in index, no need to check if empty array since insert will always point to index 0 if index contains no object
        {
                index = 0;//object is to placed in index 0
                for(size_t i = count; i > index; i--)
                {
                    data[i] = data[i - 1];//moves all object index+1 until 0, data[0] = data[1] at this point
                }
                data[index] = entry;//insert entry at data[0] and index = 0 as current item of sequence
                count++;
        }
        else//there is object in index
        {
            for(size_t i = count; i > index; i--)
                {
                    data[i] = data[i - 1];//moves all object index+1 until index, data[index] = data[index+1] at this point
                }
                data[index] = entry;//insert entry at data[index] and index as current item of sequence
                count++;
        }

    }
    void sequence::attach(const value_type& entry)
    {
        assert(size() < CAPACITY);
        if(!is_item())//no object in index, no need to check if empty array since advance has assert(is_item())
        {
            data[index] = entry;
            //attach entry to index which should be the end of sequence unless the array is initialized as something like (10, empty, 20, empty...)
            //but such case should not happen if using insert and attach function to an empty array.
            count++;
        }
        else//there is object in index
        {
            for(size_t i = count; i > index; i--)
            {
                data[i] = data[i - 1];//moves all object index+1 until index, data[index] = data[index+1] at this point
            }
            data[++index] = entry;//attach entry to data[index+1] and index+1 as current item of sequence
            count++;
        }

    }
    void sequence::remove_current()
    {
        assert(is_item());
        for(size_t i = index; i < count; i++)
        {
            data[i] = data[i + 1];//data[index] overwrite by data[index+1] which makes it look like original data[index] is removed
        }
        count--;//adjust array size
    }
    sequence::size_type sequence::size( ) const
    {
        return count;
    }
    bool sequence::is_item( ) const
    {
        return index < count;
    }
    sequence::value_type sequence::current( ) const
    {
        assert(is_item());
        return data[index];
    }
}

// Provided by:   ____________Mingzhi Xu__________
// Email Address: ____________mxu000@citymail.cuny.edu________
// FILE: sequence2.cpp
// CLASS PROVIDED: sequence (part of the namespace main_savitch_4)
// "array_pt" is the pointer to a dynamic array which is used to point at the array which stores a sequence of variables
// "count" is the current length of the sequence, or in another words how many items are current in this sequence
// "index" is the current position of the item or at which position that it is currently pointing at
// "capacity" is the size of the array
#include "sequence2.h"
#include <cassert>

namespace main_savitch_4
{
    sequence::sequence(sequence::size_type initial_capacity)
    {
        array_pt = new sequence::value_type[initial_capacity];
        count = 0;
        index = 0;
        capacity = initial_capacity;
    }
    sequence::sequence(const sequence &source)
    {
        array_pt = new sequence::value_type[source.capacity];
        count = source.count;
        index = source.index;
        capacity = source.capacity;
        for(sequence::size_type i = 0; i < count; i++) {array_pt[i] = source.array_pt[i];}
    }
    sequence::~sequence()
    {
        delete [] array_pt;
    }
    void sequence::start()
    {
        index = 0;
    }
    void sequence::advance()
    {
        if(is_item()) index++;
    }
    void sequence::insert(const value_type &entry)
    {
        if (capacity <= count) resize(size()+1);//different from seq1 no assert since need to resize
        if (!is_item())//basically same as seq1
        {
            index = 0;
            for (sequence::size_type i = count; i > index; i--) {array_pt[i] = array_pt[i - 1];}
            array_pt[0] = entry;
        }
        else
        {
            for (sequence::size_type i = count; i > index; i--) {array_pt[i] = array_pt[i - 1];}
            array_pt[index] = entry;
        }
        count++;
    }
    void sequence::attach(const value_type &entry)
    {
        if (capacity <= size()) resize(size()+1);//different from seq1 no assert since need to resize
        if (!is_item()) array_pt[index] = entry;//basically same as seq1
        else
        {
            for(sequence::size_type i = count; i > index; i--) {array_pt[i] = array_pt[i-1];}
            array_pt[++index] = entry;
        }
        count++;
    }
    void sequence::remove_current()
    {
        assert(is_item());//basically same as seq1
        for(sequence::size_type i = index; i < size(); i++) {array_pt[i] = array_pt[i+1];}
        count--;
    }
    void sequence::resize(size_type new_capacity)
    {
        if(new_capacity > count)//postcondition
        {
            value_type* array_pt2;
            capacity = new_capacity;
            array_pt2 = new value_type[capacity];
            for(sequence::size_type i = 0; i < count; i++) {array_pt2[i] = array_pt[i];}
            delete [] array_pt;
            array_pt = array_pt2;
        }
    }
    void sequence::operator=(const sequence &source)//overloaded operator= similarly to one did in class, memory de-allocating.
    {
        if (this == &source) return;
        else
        {
        delete [] array_pt;
        array_pt = new sequence::value_type[source.capacity];
        count = source.count;
        index = source.index;
        capacity = source.capacity;
        for(sequence::size_type i = 0; i < count; i++) {array_pt[i] = source.array_pt[i];}
        }
    }
    sequence::size_type sequence::size() const
    {
        return count;
    }
    bool sequence::is_item() const
    {
        return (index >= 0 && (index < size()));
    }
    sequence::value_type sequence::current() const
    {
        assert(is_item());
        return array_pt[index];
    }
    void sequence::operator+=(const sequence &source)//adding source.array behind current array
    {
        sequence::size_type newcount = size() + source.size();//length of combined array
        if(capacity < newcount) resize(capacity + source.size());//need to resize if new length > capacity
        for(sequence::size_type i = 0; i < source.size(); i++) {array_pt[i + size()] = source.array_pt[i];}//i + size() to start adding source.array to end of the resized current array
        count = newcount;
    }
    sequence operator+(const sequence &s1, const sequence &s2)//type sequence returns a sequence
    {
        sequence s3 = s1;//using overloaded operator= to set s3 to have same values as s1
        s3 += s2;//using overloaded operator+= to add s2 onto resized s3
        return s3;
    }
    sequence::value_type sequence::operator[](size_type index) const//returns item in index if valid
    {
        assert(is_item());
        return array_pt[index];
    }
}

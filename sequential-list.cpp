#include "sequential-list.h"
#include <iostream>
#include <string>
using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
    capacity_ = cap;
    data_ = new DataType [cap]; // making new array and storing in data_ datatype
    size_ = 0; // initialize at 0
}

SequentialList::~SequentialList()
{
    delete[ ] data_;
}

unsigned int SequentialList::size() const
{
    return size_; // size stored in size_ variable
}

unsigned int SequentialList::capacity() const
{
    return capacity_; // size stored in capacity_ variable
}

bool SequentialList::empty() const
{
    if (size_ == 0) // if the size of list is 0 (therefore empty), return true
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool SequentialList::full() const
{
    if (size_ == capacity_) // if the size is equal to capacity no more elements can be added therefore the list is full
    {
        return true;
    }
    else
    {
        return false;
    }
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
        if ( index >= size_ ) // if index of element is greater than scope of list then invalid
        {
            return data_[size_ - 1];// return previous element of array
        }
        else if (size_ == 0) // if list is empty
        {
            return data_[0];
        }
        else
        {
            return data_[index]; //return value of array at index
        }
}

unsigned int SequentialList::search(DataType val) const
{
    for( int i = 0; i < size_ ; i++) //goes through each element in list until the end
    {
        if ( data_[i] == val) // searches for specific value
        {
            return i; // when it finds said value return the index
        }
    }
    return size_; // if value not found returns size of list
}
void SequentialList::print() const
{
    for( int i = 0; i < size_ ; i++) // goes through each element of list sequentially
    {
       cout << " data_[i] \n" ; // prints value at each index to console
    }
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if (capacity_ <= size_ || index > size_) // can't add to list if there is no space (cap) or index isn't in list
    {
        return false;
    }
    for (int i = size_; i > index; i--) // start at end of list and go through until reach index
    {
        data_[i] = data_[i - 1]; // move each data value to index one over so index becomes empty
    }
    data_[index] = val; // insert value at index
    size_++; // increase size of list to accommodate insertion
    return true;
}

bool SequentialList::insert_front(DataType val)
{
    if (capacity_ <= size_ || 0 > size_) // can't add to list if there is no space (cap) or if size is less than one because would increase to still zero spaces
    {
        return false;
    }
    for (int i = size_; i > 0; i--) // start at end of list and go through until reach beginning
    {
        data_[i] = data_[i - 1]; // move each data value to index one over so index 0  becomes empty
    }
    data_[0] = val; // insert value at index 0
    size_++; // increase size of list to accommodate insertion
    return true;

}

bool SequentialList::insert_back(DataType val)
{
    if (size_ >= capacity_) // can't fit in list if not adequate space
    {
        return false;
    }
    data_[size_] = val; // size index is last position in list so value added here
    size_++; // increase to accommodate insertion
    return true;


}

bool SequentialList::remove(unsigned int index)
{
    if (size_ > 0 && index < size_) // if there is an element in list to be removed and index is within parameters of list
    {
        for (int i = size_ - 1; i >= index; i--) // begin at end of array and loop back until reach index
        {
            data_[i] = data_[i + 1]; // move each to left therefore getting rid of index position
        }
        size_ --; // decrease list because element removed
        return true;

    }
    return false;


}

bool SequentialList::remove_front()
{
    if (size_ > 0)// only need one element in array to remove
    {
        for (int i = 0; i < size_; i++) // start at beginning and loop through each element
        {
                data_[i] = data_[i + 1]; // move each element one to left to remove first element and keep rest connected
        }
        size_ --; // decrease list because element removed
        return true;

    }
    return false;

}

bool SequentialList::remove_back()
{
    if ( size_ == 0) // can't remove element if there is no element to remove
    {
        return false;
    }
    size_ --; // decrease list because element removed
    return true; // list automatically removes end index unless otherwise specified
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    for (int i = 0; i < size_ ; i++) // loop through each element of list
    {
        if (i == index) // stop when find given index
            data_[i] = val; // insert given value at said index
    }
    // verify if was successful
    if (data_[index] == val) // if the val at index is equivalent to given val
    {
        return true; // successful
    }
    else
    {
        return false; // if not was unsuccessful
    }
}


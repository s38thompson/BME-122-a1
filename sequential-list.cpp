#include "sequential-list.h"
using namespace std;

SequentialList::SequentialList(unsigned int cap)
{
    capacity_ = cap;
    DataType *list = new DataType [cap];  // sequential-list.h says int = DataType
    data_ = list;
    size_ = 0; // initialize at 0
}

SequentialList::~SequentialList()
{
    delete[ ] data_; // data_ and name of array (list)
}

unsigned int SequentialList::size() const
{
    int length = 0;
    for( int i = 0; i < size_ ; i++); // go through every line and add one to size every time
    {
        length = length + 1;
        return length;
    }
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    // if else
}

bool SequentialList::full() const
{
    // if else
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
}

unsigned int SequentialList::search(DataType val) const
{
}

void SequentialList::print() const
{
}

bool SequentialList::insert(DataType val, unsigned int index)
{
}

bool SequentialList::insert_front(DataType val)
{
}

bool SequentialList::insert_back(DataType val)
{
}

bool SequentialList::remove(unsigned int index)
{
}

bool SequentialList::remove_front()
{
}

bool SequentialList::remove_back()
{
}

bool SequentialList::replace(unsigned int index, DataType val)
{
}


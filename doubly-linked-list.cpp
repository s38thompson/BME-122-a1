#include "doubly-linked-list.h"
#include <iostream>
#include <string>
using namespace std;

DoublyLinkedList::Node::Node(DataType data)
{
    value = data;
    next = nullptr;
    prev = nullptr;
}

DoublyLinkedList::DoublyLinkedList()
{
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
        Node* cur = head_;
        Node* prev;

        for (int i = 0; i <= size_; i++)
        {
            if (cur != nullptr)
            {
                prev = cur;
                cur = cur->next;
                delete prev;
            }
        }

        head_ = nullptr;
        tail_ = nullptr;
}

unsigned int DoublyLinkedList::size() const
{
    return size_;
}

unsigned int DoublyLinkedList::capacity() const
{
    return CAPACITY;
}

bool DoublyLinkedList::empty() const
{
    if (size_ == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool DoublyLinkedList::full() const
{
    if (size_ == capacity()) // if the size is equal to capacity no more elements can be added therefore the list is full
    {
        return true;
    }
    else
    {
        return false;
    }
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const
{
    Node *cur = head_; // start with head as current node
    if (index >= size_ || index < 0) // if index of element is not in scope of list then invalid
    {
        for (int i = 0; i <= size_; i++) // iterate through list
        {
            cur = cur->next;
        }
        return cur->value;// return last element of list
    }
    else if ( size_ == 0) // empty list
    {
        return 0;
    }
    else
    {
        for (int i = 0; i <= size_ ; i++)
        {
            if (i == index)
            {
                return (cur->value); // return value at current
            }
            cur = cur->next;
        }
    }
}
unsigned int DoublyLinkedList::search(DataType value) const
{
    Node* cur = head_;
    int position = 0;
    while (cur != nullptr)
    {
        if (cur->value == value)
        {
            return position;
        }
        position++;
        cur = cur->next;
    }
    return size_;
}

void DoublyLinkedList::print() const
{
    Node* cur = head_;
    while (cur != nullptr)
    {
        cout << cur->value << endl;
        cur = cur->next;
    }

}
DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const
{

}

bool DoublyLinkedList::insert(DataType value, unsigned int index)
{
    Node* cur = head_;
    Node* node = new Node(value);

    // can't add to list if there is no space (cap) or index isn't in list
    if (capacity() <= size_ || index > size_ || index < 0)
    {
        return false;
    }

    // if list is empty
    if (head_ == nullptr)
    {
        // head is new node
        head_ = node;
        return true;
    }

    // if inserting at front
    if (index == 0)
    {
        node->next = head_;
        head_->prev = node;
        head_ = node;
        return true;
    }
    else
    {
        // iterate through list until reach one node after index
        for(int i = 0; i <= index + 1; i++)
        {
            if ( i == index + 1)
            {
                node->prev = cur->prev;
                node->next = cur;
                cur->prev->next = node;
                cur->prev = node;
            }
            cur = cur->next;
        }
       return true;
    }

}

bool DoublyLinkedList::insert_front(DataType value)
{
    Node *node = new Node(value);

    // can't add to list if there is no space (cap)
    // or if size is less than one because would still have zero spaces
    if (capacity() <= size_ || 0 > size_)
    {
        return false;
    }

    // add element to empty list
    if (head_ == nullptr)
    {
        head_ = node;
        return true;
    }

    // insert element at front of list
    node->next = head_;
    head_->prev = node;
    head_ = node;
    return true;
}

bool DoublyLinkedList::insert_back(DataType value)
{
    // can't fit in list if not adequate space
    if (size_ >= capacity() || 0 > size_)
    {
        return false;
    }
    else
    {
        Node* node = new Node(value);
        Node* cur = head_;

        // insert node to empty list
        if (head_ == nullptr)
        {
            head_ = node;
            return true;
        }
        else
        {
            // iterate through list until reach end
            for (int i = 0; i < size_; i++)
            {
                cur = cur->next;
            }
            // add new node to the end
            cur->next = node;
            node->prev = cur;
            return true;
        }
    }
}

bool DoublyLinkedList::remove(unsigned int index)
{
    if (size_ > 0 && index < size_)
    {
        Node* cur = head_;
        Node* prev;
        int position = 0;

        // if head is index
        if ( position == index)
        {
            head_ = cur-> next;
            delete cur;
            return true;
        }
        // iterate though list
        while (cur != nullptr)
        {
            // find when position equals index
            if (position == index)
            {
                // if index is tail
                if (cur->next == nullptr)
                {
                    tail_ = prev;
                    prev->next = nullptr;
                    delete cur;
                    return true;
                }
                // general cases
                prev->next = cur->next; // previous node points to the next node
                delete cur;
                return true;
            }
            position++;
            cur = cur->next;
        }
    }
    return false;
}

bool DoublyLinkedList::remove_front()
{
   // list must have at least one element to remove
    if (size_ > 0)
    {
        Node* cur = head_;
        Node* next;

        // list is one element long
        if (size_ == 1)
        {
            head_ = cur->next;
            next->prev = cur->prev;
            delete cur;
            return true;
        }

        // if list is more than one element long
        while (cur == head_)
        {
            head_ = cur-> next;
            delete cur;
            return true;
        }
    }
    return false;
}

bool DoublyLinkedList::remove_back()
{
    // can't remove element if there is no element to remove
    if ( size_ == 0)
    {
        return false;
    }
    Node* cur = head_;
    Node* next;
    Node* prev;

    // list is one element long
    if (size_ == 1)
    {
        head_ = cur->next;
        next->prev = cur->prev;
        delete cur;
        return true;
    }

   // general case
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    tail_ = prev;
    prev->next = nullptr;
    delete cur;
    return true;
}

bool DoublyLinkedList::replace(unsigned int index, DataType value)
{
    Node* cur = head_;
    while (cur->next != nullptr)
    {
        // loop through each element of list
        for (int i = 0; i < size_ ; i++)
        {
            // stop when find given index
            if (i == index)
            {
                // insert given value at said index
                cur->value = value;
                return true;
            }
        }
        // change cur pointer to next node
        cur = cur->next;
    }
    return false;
}


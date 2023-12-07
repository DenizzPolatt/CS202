/*
* Author : Deniz Polat
* ID: 22103590 
* Section : 1 
* Homework : 3 
* Description : The header file of template Priority Queue class
*/

#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP
#include "Heap.hpp"

template <typename T>
class PriorityQueue
{
private:
    Heap<T>* h;

public:
    PriorityQueue(int size);
    ~PriorityQueue();
    bool pqIsEmpty() const;
    void pqInsert(const T& newItem);
	void pqDelete(T& priorityItem);
    T& top() const;
};

#endif
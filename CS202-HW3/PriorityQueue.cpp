/*
* Author : Deniz Polat
* ID: 22103590 
* Section : 1 
* Homework : 3 
* Description : The implementation file of template PriorityQueue class
*/

#include <iostream>
#include "PriorityQueue.hpp"
#include "Patient.hpp"

template <typename T>
PriorityQueue<T>::PriorityQueue(int size) {
    h = new Heap<T>(size);
}

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    delete h;
}


template <typename T>
bool PriorityQueue<T>::pqIsEmpty() const{
    return h->heapIsEmpty();
}

template <typename T>
void PriorityQueue<T>::pqInsert(const T& newItem){
	h->heapInsert(newItem);
}

template <typename T>
void PriorityQueue<T>::pqDelete(T& priorityItem){
	h->heapDelete(priorityItem);
}

template <typename T>
T& PriorityQueue<T>::top() const {
    if (!h->heapIsEmpty()) {
        return h->items[0]; // Return the top element of the heap
    } else {
        throw std::runtime_error("PriorityQueue is empty");
    }
}

template class PriorityQueue<Patient>;

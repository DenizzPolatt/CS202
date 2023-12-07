/*
* Author : Deniz Polat
* ID: 22103590 
* Section : 1 
* Homework : 3 
* Description : The implementation file of template Heap class
*/
#include "Heap.hpp"
#include "Patient.hpp"
#include <iostream>

template <typename T>
Heap<T>::Heap(){
    size_ = 0;
}

template <typename T>
Heap<T>::Heap(int size) : items(new T[size]){
    size_ = 0;
}

template <typename T>
Heap<T>::~Heap() {
    delete[] items;
}

template <typename T>
bool Heap<T>::heapIsEmpty() const
{
    return size_ == 0;
}

template <typename T>
void Heap<T>::heapInsert(const T& newItem)
{
	// Place the new item at the end of the heap
	items[size_] = newItem;
	// Trickle new item up to its proper position
	int place = size_;
	int parent = (place - 1)/2;
	while ( (place > 0) && (items[parent] < items[place]) ) {
		T temp = items[parent];
		items[parent] = items[place];
		items[place] = temp;
		place = parent;
		parent = (place - 1)/2;
	}
 	++size_;

}

template <typename T>
void Heap<T>::heapDelete(T& rootItem){
    rootItem = items[0];
    items[0] = items[--size_];
    heapRebuild(0);
}

template <typename T>
void Heap<T>::heapRebuild(int root)
{
    int child = 2 * root + 1; 	// index of root's left child, if any
	if ( child < size_ ) {		
		// root is not a leaf so that it has a left child
		int rightChild = child + 1; 	// index of a right child, if any
		// If root has right child, find larger child
		if ( (rightChild < size_) &&
		    (items[child] < items[rightChild]) )
			child = rightChild; 	// index of larger child

		// If root’s item is smaller than larger child, swap values
		if ( items[root] < items[child]) {
			T temp = items[root];
			items[root] = items[child];
			items[child] = temp;

			// transform the new subtree into a heap
			heapRebuild(child);
		}
    }
}

template class Heap<Patient>;





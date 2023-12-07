/*
* Author : Deniz Polat
* ID: 22103590 
* Section : 1 
* Homework : 3 
* Description : The header file of template Heap class
*/

#ifndef HEAP_HPP
#define HEAP_HPP
template <typename T>
class Heap
{
private:
	int size_; 
public:
    T* items;	// array of heap items
    Heap();
    Heap(int size);
    ~Heap();

    bool heapIsEmpty() const;
	void heapInsert(const T& newItem);
	void heapDelete(T& rootItem);
    void heapRebuild(int root);	

};

#endif 
#include <iostream>

/** 
* Title: Algorithm analysis & Sorting 
* Author : Deniz Polat
* ID: 22103590 
* Section : 1 
* Homework : 1 
* Description : This file implements the several sorting 
                algorithms for array of integers. Implemented 
                sorting algorithms are insertion sort, selection 
                sort, merge sort, wuick sort and hybrid sort.
*/

/**
 * Insertion sort algorithm
*/
void insertionSort(int *arr, const int size, int &compCount, int &moveCount)
{
    for (int i = 1; i < size; ++i) {

        int key = arr[i]; 
        int location = i; 

        for (; location > 0 && (arr[location - 1] > key); --location) 
        {
            arr[location] = arr[location - 1];
            moveCount++; 
            compCount++; 
        }

        arr[location] = key;
        moveCount++;
    }
}


int indexOfLargest(int *arr, const int size, int &compCount, int &moveCount)
{
    int i = 0; //index so far, moveCount ++
    for(int index = 1; index < size; ++index)
    {
        if(arr[index] > arr[i]) // compSize ++
        {
            i = index;
        }
        compCount++;
    }
    return i;
}

void swap(int &x, int &y, int &moveCount)
{
    int temp = x;
    x = y;
    y = temp;

    moveCount+=3;
}

/**
 * Selection sort algorithm
*/
void selectionSort(int *arr, const int size, int &compCount, int &moveCount)
{
    for (int last = size - 1; last >= 1; --last)
    {
        int largest = indexOfLargest(arr, last + 1, compCount, moveCount); 
        swap(arr[largest], arr[last], moveCount);
    }
}

void merge(int *arr, const int size, int first, int mid, int last, int &compCount, int &moveCount)
{
    int first1 = first; //beginning of first subarray
    int last1 = mid; // end of first subarray
    int first2 = mid + 1; // beginning of second subarray
    int last2 = last; // end of second subarray
    int index = first1; // next available location in temp;

    int *temp = new int[size];

    for(; (first1 <= last1) && (first2 <= last2); ++index)
    {
        if(arr[first1] < arr[first2])
        {
            temp[index] = arr[first1];
            ++first1;
            moveCount++;
            compCount++;
        }
        else {
            temp[index] = arr[first2];
            ++first2;
            moveCount++;
        }
    }

    for(; first1 <= last1; ++first1, ++index)
    {
        temp[index] = arr[first1];
        moveCount++;
    }

    for(; first2 <= last2; ++first2, ++index)
    {
        temp[index] = arr[first2];
        moveCount++;
    }

    for(index = first; index <= last; ++index)
    {
        arr[index] = temp[index];
        moveCount++;
    }

    delete[] temp;
}

void mergeSort2(int *arr, const int size, int first, int last, int &compCount, int &moveCount)
{
    if(first < last)
    {
        int mid = (first + last) / 2; //index of midpoint

        mergeSort2(arr, size, first, mid, compCount, moveCount);
        mergeSort2(arr, size, mid + 1, last, compCount, moveCount);

        merge(arr, size, first, mid, last, compCount, moveCount);
    }
}


/**
 * Merge sort algorithm
*/
void mergeSort(int *arr, const int size, int &compCount, int &moveCount)
{
    mergeSort2(arr, size, 0, size - 1, compCount, moveCount);
}

void partition(int* arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount)
{
    int pivot = arr[first]; //pivot is at the first index for every partition
    moveCount++;

    int lastS1 = first;
    int firstUnknown = first + 1;

    for(; firstUnknown <= last; ++firstUnknown)
    {
        if(arr[firstUnknown] < pivot){
            swap(arr[firstUnknown], arr[lastS1], moveCount);
        }
        compCount++;
    }

    swap(arr[first], arr[lastS1], moveCount);
    pivotIndex = lastS1;
}

void quickSortHelper(int* arr, int first, int last, int &compCount, int &moveCount)
{
    int pivotIndex;

    if(first < last)
    {
        partition(arr, first, last, pivotIndex, compCount, moveCount);
        
        quickSortHelper(arr, first, pivotIndex - 1, compCount, moveCount);
        quickSortHelper(arr, pivotIndex + 1, last, compCount, moveCount);
    }
}

/**
 * Quicksort algorithm
*/
void quickSort(int *arr, const int size, int &compCount, int &moveCount){
    quickSortHelper(arr, 0, size - 1, compCount, moveCount);
}

void bubbleSort(int *arr, const int size, int &compCount, int &moveCount)
{
    bool sorted = false;

    for(int pass = 1; (pass < size) && !sorted; ++pass)
    {
        sorted = true;
        for(int i = 0; i < size - pass; ++i)
        {
            int nextIdx = i + 1;
            if(arr[i] > arr[nextIdx])
            {
                swap(arr[i], arr[nextIdx], moveCount);
                sorted = false;
            }
            compCount++;
        }
    }
}

void hybridSort2(int *arr, const int size, int first, int last, int &compCount, int &moveCount)
{
    int partitionSize = last - first + 1;
    if (partitionSize > 20) {
        mergeSort2(arr, size, first, last, compCount, moveCount);
    } else {
        bubbleSort(arr, partitionSize, compCount, moveCount);
    }
}

/**
 * Hybrid sort algorithm
 */
void hybridSort(int *arr, const int size, int &compCount, int &moveCount) {
    hybridSort2(arr, size, 0, size - 1, compCount, moveCount);
}



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

#ifndef SORTING_H
#define SORTING_H

/**
 * Insertion sort algorithm
*/
void insertionSort(int *arr, const int size, int &compCount, int &moveCount);

/**
 * Selection sort algorithm
*/
void selectionSort(int *arr, const int size, int &compCount, int &moveCount);

/**
 * Merge sort algorithm
*/
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);

/**
 * Quicksort algorithm
*/
void quickSort(int *arr, const int size, int &compCount, int &moveCount);

/**
 * Hybrid sort algorithm
*/
void hybridSort(int *arr, const int size, int &compCount, int &moveCount);

#endif
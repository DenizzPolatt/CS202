#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cmath>
#include "sorting.h"

/** 
* Title: Algorithm analysis & Sorting 
* Author : Deniz Polat
* ID: 22103590 
* Section : 1 
* Homework : 1 
* Description: This main.cpp program implements the test 
                functions for the sorting algorithms as three 
                functions to create random, partially ascending
                and partially descending arrays.
*/

void fillRandomArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = std::rand();
    }
}

void createPartiallyAscending(int *arr, const int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    int beginIdx = 0;
    int endIdx = static_cast<int> (std::log2(size)); 
    int numberOfElements = static_cast<int> (std::log2(size));

    while(beginIdx + numberOfElements <= size) 
    {
        for(int i = beginIdx; i <= endIdx; ++i) 
        {
            std::uniform_int_distribution<> distrib(beginIdx, endIdx-1);
            arr[i] = distrib(gen);
        }

        beginIdx = endIdx + 1;
        endIdx += numberOfElements;
    }

    // fill the rest 
    for(int i = beginIdx; i < size; ++i)
    {
        std::uniform_int_distribution<> distrib(beginIdx, size-1);
            arr[i] = distrib(gen);
    }
}

void createPartiallyDescending(int *arr, const int size)
{
    createPartiallyAscending(arr, size);

    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}


int main() {
    using namespace std;
    const char separator = ' ';
    const int width = 30;

    int compCount = 0; 
    int moveCount = 0;

    cout << left << setw(width) << setfill(separator) << " ";
    cout << "Part 2-b-1: Performance analysis of random integers array\n" << endl;
    cout << left << setw(width) << setfill(separator) << " ";
    cout << left << setw(width) << setfill(separator) << "Elapsed time";
    cout << left << setw(width) << setfill(separator) << "Comp. Count";
    cout << left << setw(width) << setfill(separator) << "Move Count";
    
    #pragma region 
    //for size 1000
    int size = 1000;
    cout << "\nArray Size: " << size << endl;
    int *randomArray = new int[size];
    fillRandomArray(randomArray, size);
    
    clock_t start, end;
    start = clock();
    insertionSort(randomArray, size, compCount, moveCount);
    end = clock();

    cout << left << setw(width) << setfill(separator) << "Insertion Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(randomArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Selection Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    mergeSort(randomArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Merge Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    quickSort(randomArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Quick Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(randomArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Hybrid Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    delete[] randomArray;

    /////////////
    //for size 5000
    size = 5000;
    cout << "\nArray Size: " << size << endl;
    randomArray = new int[size];
    fillRandomArray(randomArray, size);
    
    start = clock();
    insertionSort(randomArray, size, compCount, moveCount);
    end = clock();

    cout << left << setw(width) << setfill(separator) << "Insertion Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(randomArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Selection Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    mergeSort(randomArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Merge Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    quickSort(randomArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Quick Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(randomArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Hybrid Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    delete[] randomArray;

    ////
    //for size 10000
    size = 10000;
    cout << "\nArray Size: " << size << endl;
    randomArray = new int[size];
    fillRandomArray(randomArray, size);
    
    start = clock();
    insertionSort(randomArray, size, compCount, moveCount);
    end = clock();

    cout << left << setw(width) << setfill(separator) << "Insertion Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(randomArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Selection Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    mergeSort(randomArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Merge Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    quickSort(randomArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Quick Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(randomArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Hybrid Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    delete[] randomArray;

    ////////
    //for size 20000
    size = 20000;
    cout << "\nArray Size: " << size << endl;
    randomArray = new int[size];
    fillRandomArray(randomArray, size);
    
    start = clock();
    insertionSort(randomArray, size, compCount, moveCount);
    end = clock();

    cout << left << setw(width) << setfill(separator) << "Insertion Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(randomArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Selection Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    mergeSort(randomArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Merge Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    quickSort(randomArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "\nQuick Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(randomArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "\nHybrid Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount;

    delete[] randomArray;

    #pragma endregion

    #pragma region 
    /**
     * Ascending Arrays
    */

    cout << "\n";
    cout << left << setw(width) << setfill(separator) << " ";
    cout << "Part 2-b-2: Performance analysis of partially ascending integers array\n" << endl;
    cout << left << setw(width) << setfill(separator) << " ";
    cout << left << setw(width) << setfill(separator) << "Elapsed time";
    cout << left << setw(width) << setfill(separator) << "Comp. Count";
    cout << left << setw(width) << setfill(separator) << "Move Count";
    
    //for size 1000
    size = 1000;
    cout << "\nArray Size: " << size << endl;
    int* ascendingArray = new int[size];
    createPartiallyAscending(ascendingArray, size);
    
    start = clock();
    insertionSort(ascendingArray, size, compCount, moveCount);
    end = clock();

    cout << left << setw(width) << setfill(separator) << "Insertion Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(ascendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Selection Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    mergeSort(ascendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Merge Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    quickSort(ascendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Quick Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(ascendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Hybrid Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    delete[] ascendingArray;

    /////////////
    //for size 5000
    size = 5000;
    cout << "\nArray Size: " << size << endl;
    ascendingArray = new int[size];
    createPartiallyAscending(ascendingArray, size);
    
    start = clock();
    insertionSort(ascendingArray, size, compCount, moveCount);
    end = clock();

    cout << left << setw(width) << setfill(separator) << "Insertion Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(ascendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Selection Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    mergeSort(ascendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Merge Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    quickSort(ascendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Quick Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(ascendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Hybrid Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    delete[] ascendingArray;

    ////
    //for size 10000
    size = 10000;
    cout << "\nArray Size: " << size << endl;
    ascendingArray = new int[size];
    createPartiallyAscending(ascendingArray, size);
    
    start = clock();
    insertionSort(ascendingArray, size, compCount, moveCount);
    end = clock();

    cout << left << setw(width) << setfill(separator) << "Insertion Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(ascendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Selection Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    mergeSort(ascendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Merge Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    quickSort(ascendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Quick Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(ascendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Hybrid Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    delete[] ascendingArray;

    ////////
    //for size 20000
    size = 20000;
    cout << "\nArray Size: " << size << endl;
    ascendingArray = new int[size];
    createPartiallyAscending(ascendingArray, size);
    
    start = clock();
    insertionSort(ascendingArray, size, compCount, moveCount);
    end = clock();

    cout << left << setw(width) << setfill(separator) << "Insertion Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(ascendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Selection Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    mergeSort(ascendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Merge Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    quickSort(ascendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Quick Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(ascendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Hybrid Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    delete[] ascendingArray;
    #pragma endregion

    #pragma region
    /**
     * Descending Arrays
    */
    cout << "\n";
    cout << left << setw(width) << setfill(separator) << " ";
    cout << "Part 2-b-2: Performance analysis of partially descending integers array\n" << endl;
    cout << left << setw(width) << setfill(separator) << " ";
    cout << left << setw(width) << setfill(separator) << "Elapsed time";
    cout << left << setw(width) << setfill(separator) << "Comp. Count";
    cout << left << setw(width) << setfill(separator) << "Move Count";
    
    //for size 1000
    size = 1000;
    cout << "\nArray Size: " << size << endl;
    int* descendingArray = new int[size];
    createPartiallyDescending(descendingArray, size);
    
    start = clock();
    insertionSort(descendingArray, size, compCount, moveCount);
    end = clock();

    cout << left << setw(width) << setfill(separator) << "Insertion Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(descendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Selection Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    mergeSort(descendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Merge Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    quickSort(descendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Quick Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(descendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Hybrid Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    delete[] descendingArray;

    /////////////
    //for size 5000
    size = 5000;
    cout << "\nArray Size: " << size << endl;
    descendingArray = new int[size];
    createPartiallyDescending(descendingArray, size);
    
    start = clock();
    insertionSort(descendingArray, size, compCount, moveCount);
    end = clock();

    cout << left << setw(width) << setfill(separator) << "Insertion Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(descendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Selection Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    mergeSort(descendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Merge Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    quickSort(descendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Quick Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(descendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Hybrid Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    delete[] descendingArray;

    ////
    //for size 10000
    size = 10000;
    cout << "\nArray Size: " << size << endl;
    descendingArray = new int[size];
    createPartiallyDescending(descendingArray, size);
    
    start = clock();
    insertionSort(descendingArray, size, compCount, moveCount);
    end = clock();

    cout << left << setw(width) << setfill(separator) << "Insertion Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;
    
    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(descendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Selection Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    mergeSort(descendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Merge Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    quickSort(descendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Quick Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(descendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Hybrid Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    delete[] descendingArray;

    ////////
    //for size 20000
    size = 20000;
    cout << "\nArray Size: " << size << endl;
    descendingArray = new int[size];
    createPartiallyDescending(descendingArray, size);
    
    start = clock();
    insertionSort(descendingArray, size, compCount, moveCount);
    end = clock();

    cout << left << setw(width) << setfill(separator) << "Insertion Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(descendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Selection Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    mergeSort(descendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Merge Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    quickSort(descendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Quick Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    compCount = 0; 
    moveCount = 0;
    start = clock();
    selectionSort(descendingArray, size, compCount, moveCount);
    end = clock();
    
    cout << left << setw(width) << setfill(separator) << "Hybrid Sort";
    cout << left << setw(width) << setfill(separator) << double(end - start) / CLOCKS_PER_SEC;
    cout << left << setw(width) << setfill(separator) << compCount;
    cout << left << setw(width) << setfill(separator) << moveCount << std::endl;

    delete[] descendingArray;
    #pragma endregion

    return 0;
}

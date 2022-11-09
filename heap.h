// Project #3: Word Search Part B
// 
// Group Members: Lisa Byrne, Kaite O'Flaherty, Alek Tunik
//
// Description: Header file for the heap class
// Assumption:

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector> 
#include <cmath>
#include "d_except.h"
#include "d_matrix.h"

using namespace std;

template <typename T>
class heap 
{
    public:
    //public member functions
    vector<T> heapsort(vector<T>& A);

    private:
    // private data member
    vector<T> _heap;
    // private data functions
    int parent(int i);
    int left(int i);
    int right(int i);
    T getItem(int n);
    void buildMaxHeap(const vector<T> &A);
    void initializeMaxHeap(const vector<T> &A);
    void maxHeapify(int parentIndex, int size);

    
}; // End template heap class

template <typename T>
int heap<T>::parent(int i)
// Get index of parent
{
    return floor(i/2);
} // End parent


template <typename T>
int heap<T>::left(int i)
// Get index of left child
{
    return 2*i;
}


template <typename T>
int heap<T>::right(int i)
// Get index of right child
{
    return (2*i + 1);
}


template <typename T>
T heap<T>::getItem(int n)
// Returns the nth item in the heap
{
    return _heap[n-1];
}


template <typename T>
void heap<T>::maxHeapify(int parentIndex, int size) 
// Function to recursively swap elements to reorder heap so the root is on top
{
    // initialize vars
    int l  = left(parentIndex);
    int r = right(parentIndex);
    int largest = parentIndex;

    // find largest value
    if ((l <= size) && (getItem(l) > getItem(largest)))
    // if the element in the left child is larger than the parent
    {
        // make left child largest
        largest = l;
    }
    if ((r <= size) && (getItem(r) > getItem(largest)))
    // if the element in the right child is larger than the parent
    {
        // make right child the largest
        largest = r;
    }

    // float down
    if (largest != parentIndex)
    // if heap property is not met
    {
        swap(_heap[parentIndex-1], _heap[largest-1]);
        maxHeapify(largest, size);
    }
} // End maxHeapify

template <typename T>
void heap<T>::initializeMaxHeap(const vector<T>& A)
// Function to initialize a heap
{
    for (int i = 0; i < A.size(); i++)
    {
        _heap.push_back(A[i]);
    }
} // End initializeMaxHeap


template <typename T>
void heap<T>::buildMaxHeap(const vector<T>& A)
// Function to build MAXHEAP
{
    // Turn array into heap
    initializeMaxHeap(A);

    // put heap in order
    for (int i = floor(_heap.size()/2); i > 0; i--)
    {
        maxHeapify(i, _heap.size());
    }

} // End buildMaxHeap


template <typename T>
vector<T> heap<T>::heapsort(vector<T>& A)
// Function to heap sort vector<T>
{
    // step 1: create max heap
    buildMaxHeap(A);

    // rearrange heap to be in increasing order
    for (int i = _heap.size(); i > 1; i--)
    {
        swap(_heap[0], _heap[i-1]);
        maxHeapify(1, i-1);
    }

    return _heap;
} // End heapSort
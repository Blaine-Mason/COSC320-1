// Justin Ventura COSC320
// Lab-2 Dr. Joe Anderson

#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>
//#include <bits/stdc++.h>
#include "timer.h"

// print the given array.
void printarr(int*, int);
// swap two integers by reference.
void swap (int&, int&);
// checks if array is sorted.
bool isSorted(int*, int);
// generate an array.
// 0 = random
// 1 = descending
// 2 = ascending
// true = duplicates
// false = no duppies
int* generate_array(int, bool, int);

struct Heap {
    int* arr;      // array in the structure
    int length;    // size of the array
    int heap_size; // size of the valid heap
    Heap(int& n) {
        std::cout << "Heap Created.\n";
        if (n < 1) {
            std::cout << "WARNING: Invalid array size. [1]\n";
            this->length = 1;
            arr = new int[1];
            return;
        }
        arr = new int[n];
    }
    ~Heap() {
        std::cout << "Heap destroyed.\n";
        delete [] arr;
    }
    int& operator[](int i) {
        if (i < 1 || i > length - 1) {
            std::cout << "WARNING: out of bounds. [-1]\n";
            return -1;
        }
        return arr[i];
    }
};

void MaxHeapify(struct Heap *A, int &i) {
    int l = 2*i;
    int r = (2*i + 1);
    int max;
    if (l <= A->heap_size() && A[l] > A[i]) {
        max = l;
    }
    else {
        max = i;
    }
    if (r <= A->heap_size() && A[r] > A[max]) {
        max = r;
    }
    if (max != i) {
        swap(A[i], A[max]);
        MaxHeapify(A, Largest);
    }
}

int main () {
    Timer timer;
    int *arr;
    int n, order, temp;
    bool dups;
    size_t comps = 0;

    return 0;
}

void printarr(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
bool isSorted(int* arr, int n) {
    int i = 0;
    while (i < n - 1) {
        if (*(arr + i) > *(arr + (i + 1))) {
            return false;
        }
        i++;
    }
    return true;
}
int* generate_array(int order, bool dup, int n) {
    int *arr = new int[n];
    // creates the array with duplicates.
    if (dup) {
        int j = 1;
        for (int i = 0; i < n; i++) {
            arr[i] = j;
            if (i % 2 == 0) {
                j++;
            }
        }
    }
    // otherwise make the array normally.
    else {
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
    }
    // now decide the order
    switch (order) {
        // random.
        case 0: {
                unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
                std::shuffle(arr, arr + n, std::default_random_engine(seed));
            }
            break;
        // descending.
        case 1:
            std::reverse(arr, arr + n);
    }
    return arr;
}
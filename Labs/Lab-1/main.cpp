// Justin Ventura COSC320
// Joe Anderson Lab 1

// My timer class from COSC220
#include "timer.h"
#include <bits/stdc++.h>
#include <iostream>
#include <chrono>

void display(long&);
int swap(int&, int&);
bool isSorted(int*, int&);
long bubbleSort(int*, int&);
long selectionSort(int*, int&);
long insertionSort(int*, int&);
int* generate_array(int order, bool dup, int n);
long runsort(long (*sort)(int*, int&), int* arr, int& n);

int main() {
    Timer timer;
    int *arr;
    int n = 100;
    std::cout << "----- Bubble Sort (trash) -----\n";

    std::cout << "TRIAL ONE: 100 elements.\n";
    for (int i = 0; i < 6; i++) {
        long numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(bubbleSort, arr, n);
        timer.end_timer();
        timer.display_time();
        display(numswaps);
        delete [] arr;
    }
    n *= 10;
    std::cout << "TRIAL TWO: 1000 elements.\n";
    for (int i = 0; i < 6; i++) {
        long numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(bubbleSort, arr, n);
        timer.end_timer();
        timer.display_time();
        display(numswaps);
        delete [] arr;
    }
    n *= 10;
    std::cout << "TRIAL THREE: 10000 elements.\n";
    for (int i = 0; i < 6; i++) {
        long numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(bubbleSort, arr, n);
        timer.end_timer();
        timer.display_time();
        display(numswaps);
        delete [] arr;
    }
    n *= 10;
    std::cout << "TRIAL FOUR: 100000 elements.\n";
    for (int i = 0; i < 6; i++) {
        long numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(bubbleSort, arr, n);
        timer.end_timer();
        timer.display_time();
        display(numswaps);
        delete [] arr;
    }
    n = 1000;

    std::cout << "----- Selection Sort -----\n";
    std::cout << "TRIAL ONE: 1000 elements.\n";
    for (int i = 0; i < 6; i++) {
        long numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(selectionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        display(numswaps);
        delete [] arr;
    }
    n *= 10;
    std::cout << "TRIAL TWO: 10000 elements.\n";
    for (int i = 0; i < 6; i++) {
        long numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(selectionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        display(numswaps);
        delete [] arr;
    }
    n *= 10;
    std::cout << "TRIAL THREE: 100000 elements.\n";
    for (int i = 0; i < 6; i++) {
        long numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(selectionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        display(numswaps);
        delete [] arr;
    }
    n *= 10;
    std::cout << "TRIAL FOUR: 1000000 elements.\n";
    for (int i = 0; i < 6; i++) {
        long numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(selectionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        display(numswaps);
        delete [] arr;
    }
    n = 10000;

    std::cout << "----- Insertion Sort -----\n";
    std::cout << "TRIAL ONE: 10000 elements.\n";
    for (int i = 0; i < 6; i++) {
        long numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(insertionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        display(numswaps);
        delete [] arr;
    }
    n *= 10;
    std::cout << "TRIAL TWO: 100000 elements.\n";
    for (int i = 0; i < 6; i++) {
        long numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(insertionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        display(numswaps);
        delete [] arr;
    }
    n *= 10;
    std::cout << "TRIAL THREE: 1000000 elements.\n";
    for (int i = 0; i < 6; i++) {
        long numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(insertionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        display(numswaps);
        delete [] arr;
    }
    n *= 10;
    std::cout << "TRIAL FOUR: 10000000 elements.\n";
    for (int i = 0; i < 6; i++) {
        long numswaps = 0;
        arr = generate_array((i % 3), (i % 2 == 0), n);
        timer.start_timer();
        numswaps = runsort(insertionSort, arr, n);
        timer.end_timer();
        timer.display_time();
        display(numswaps);
        delete [] arr;
    }
    n *= 10;

    return 0;
}

void display(long& swaps) {
    std::cout << "# swaps: " << swaps << "\n";
}
int swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
bool isSorted(int* arr, int& n) {
    int i = 0;
    while (i < n - 1) {
        if (*(arr + i) > *(arr + (i + 1))) {
            return false;
        }
    }
    return true;
}
long bubbleSort(int* arr, int& n) {
    long count = 0;
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; i++) {
            if (arr[j] > arr[j+1]) {
                count++;
                swapped = true;
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
long selectionSort(int* arr, int& n) {
    long count = 0;
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++)
        if (arr[j] < arr[min])
            min = j;
        count++;
        swap(arr[min], arr[i]);
    }
}
long insertionSort(int* arr, int& n) {
    long count = 0;
    int temp, j;
    for (int i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] >= temp) {
            count++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// 0 = random
// 1 = descending
// 2 = ascending
// true = duplicates
// false = no duppies
int* generate_array(int order, bool dup, int n) {
    int *arr = new int[n];
    // creates the array with duplicates.
    if (dup) {
        // keep the number of duplicates random...
        int temp = 1;
        int temp2 = ((n % (n / 7)) - (3 * order + 1)) % 10;
        // fuck division by zero buddy
        if (temp2 == 0) temp2++;
        for (int i = 0; i < n; i++) {
            *(arr + i) = temp;
            if (i % temp2 == 0) {
                temp++;
            }
        }
    }
    // otherwise make the array normally.
    else {
        for (int i = 0; i < n; i++) {
            *(arr + i) = i;
        }
    }
    // now decide the order
    switch (order) {
        // random.
        case '0':
            {
                unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
                std::shuffle(arr, arr + n, std::default_random_engine(seed));
                return arr;
            }
            break;
        // descending.
        case '1':
            // std::cout << "reversing array...\n";
            int j = n, i = 0;
            while (j > i) {
                swap(arr[i], arr[j - i]);
                i++;
                j--;
            }
            break;
        // if sorted do nothing.
    }
    return arr;
}
long runsort(long (*sort)(int*, int&), int* arr, int& n) {
    long swaps = sort(arr, n);
    return swaps;
}

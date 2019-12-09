/*
    Allen Harper
    CS3 Final Project

    DOCS: https://docs.google.com/document/d/1b4gWCHerOWO7S1fVtcSsCD-SPfFIQRdvOxC5uebrZSw/edit

    TODO:
        [X] Number Genorator - Create outfile for each of these
            [X] 100k ints
            [X] 500k ints
            [X] 1M ints
        
        Sort Algorithms:
        [X] Bubble sort 
        [X] Selection sort 
        [X] Insertion sort 
        [X] Shellsort 
        [X] Quicksort 
        [X] Mergesort 
        [X] Heapsort 
        [X] algorithm.h/sort 
        [X] algorithm.h/stable_sort

        Search Algorithms:
        [X] Sequential search
        [X] Binary search
        [X] Binary search tree

        Runtime Averages:
        [X] Run each Sort Algorithm 10 times & get average run time
        [X] Run each Search Algorithm 10 times & get average run time

        Output Stats To File:
        [X] Output average running time in ascending order of each Algorithm
            - Fastest to Slowest
            - Outfile name: timeComplexity.txt
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include "bst.h"

using namespace std;

void swap(int *ele1, int *ele2){
    int temp = *ele1;
    *ele1 = *ele2;
    *ele2 = temp;
}

void bubbleSort(int arr[], int n) { 
    // REMOVE: https://www.geeksforgeeks.org/bubble-sort/
    int i, j; 
    bool swapped; 
    
    for (i = 0; i < n-1; i++) 
    { 
        swapped = false; 
        for (j = 0; j < n-i-1; j++) 
        { 
            if (arr[j] > arr[j+1]) 
            { 
            swap(&arr[j], &arr[j+1]); 
            swapped = true; 
            } 
        } 
    
        // IF no two elements were swapped by inner loop, then break 
        if (swapped == false) 
            break; 
    }
}

void selectionSort(int arr[], int n) {  
    // REMOVE: https://www.geeksforgeeks.org/selection-sort/
    int i, j, min_idx;  

    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  

        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    }  
}   

void insertionSort(int arr[], int n) {  
    // REMOVE: https://www.geeksforgeeks.org/insertion-sort/
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  

        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  

void shellSort(int arr[], int n) { 
    // REMOVE: https://www.geeksforgeeks.org/shellsort/
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < n; i += 1) 
        { 
            int temp = arr[i]; 

            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
            
            arr[j] = temp; 
        } 
    } 
} 

int partition (int arr[], int low, int high)  {  
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)  
    {  
        if (arr[j] < pivot)  
        {  
            i++; 
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}
void quickSort(int arr[], int low, int high) {  
    // REMOVE: https://www.geeksforgeeks.org/quick-sort/
    if (low < high)  
    {  
        int pi = partition(arr, low, high);  

        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  

void merge(int arr[], int l, int m, int r) { 
    int i, j, k; 
    int left_n = m - l + 1; 
    int right_n =  r - m; 

    // int L[left_n];
    // int R[right_n]; 
    int *L = new int[left_n];
    int *R = new int[right_n];

    for (i = 0; i < left_n; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < right_n; j++) 
        R[j] = arr[m + 1+ j]; 

    i = 0;
    j = 0;
    k = l;
    while (i < left_n && j < right_n) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 

    while (i < left_n) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < right_n) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int arr[], int l, int r) { 
    // REMOVE: https://www.geeksforgeeks.org/merge-sort/
    if (l < r) 
    { 
        int m = l+(r-l)/2; 

        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
}

void heapify(int arr[], int n, int i) { 
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 

    if (l < n && arr[l] > arr[largest]) 
        largest = l; 

    if (r < n && arr[r] > arr[largest]) 
        largest = r; 

    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 
void heapSort(int arr[], int n) { 
    // REMOVE: https://www.geeksforgeeks.org/heap-sort/
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 

    for (int i=n-1; i>=0; i--) 
    { 
        swap(arr[0], arr[i]); 

        heapify(arr, i, 0); 
    } 
}

void algorithmsSTL_Sort(int arr[], int n){
    sort(arr, arr + n);
}

void algorithmsSTL_Stable_Sort(int arr[], int n){
    stable_sort(arr, arr + n);
}

int sequentialSearch(int arr[], int n, int key) {
    int index = 0;
    while (index < n ){
        if (arr[index] == key)
            return index;
        else
            index ++;
    }
    return -1;
}

void binarySearch(){
    // TODO
    cout << "Binary Search" << endl;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;
    while (low <= high) { 
        int mid = (low + high) / 2;
        if (arr[mid] == key) 
            return mid;
        else if (arr[mid] > key) 
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return -1;
}

Node<int> *binarySearchTree(BST<int> &tree, int key, Node<int> *n)
{
    n = tree.find(key);
    return n;
}

double findAvg(vector<double> v){
    double total = 0.0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        total = total + v[i];
    }
    return (total/n);
}

void readData(string fileName, int nums[], int n){ // read random ints from files
    cout << endl << fileName << endl;
    ifstream inf;
    inf.open(fileName);

    if (!inf){
        cout << "Cound not open input file.";
        exit(1);
    }

    int num;
    int i = 0;

    for (int z = 0; z < n; z++) {
        inf >> num;
        nums[z] = num;
    }
    inf.close();
}



int main() {   
    int n, arrSize;
    string file;
    clock_t start;

    
    for (int i = 2; i <= 3; i++) {
        if (i == 0) { // test of only 100 nums
            file = "100Test.txt";
            arrSize = 100;
        }
        else if (i == 1) {
            file = "100k.txt";
            arrSize = 100000;
        }
        else if (i == 2) {
            file = "500k.txt";
            arrSize = 500000;
        }
        else if (i == 3) {
            file = "1mil.txt";
            arrSize = 1000000;
        }

        vector<double> bubbleTimeElapsed;
        vector<double> selectionTimeElapsed;
        vector<double> insertionTimeElapsed;
        vector<double> shellTimeElapsed;
        vector<double> quickTimeElapsed;
        vector<double> mergeTimeElapsed;
        vector<double> heapTimeElapsed;
        vector<double> STLsortTimeElapsed;
        vector<double> STLstanleSortTimeElapsed;
        vector<double> squentialSearchTimeElapsed;
        vector<double> binarySearchTimeElapsed;
        vector<double> binarySearchTreeTimeElapsed;

        
        for (int j = 0; j < 1; j++) { // run each algorithm 10 times
            /*
                Gross, I know. I wanted to do an array of function pointes, then just itterate 
                thorugh each index of the array of functions. However, I just couldn't get it to 
                work propperly. This would have cleaned the code up signifigantly but sadly I 
                could not figure it out. Ram If you read this and happen to know how I might 
                create an array of the sorting functions, where I am able to call each func 
                with their respective parameters, then please get back to me. Thank you.

                My goal was to have something along the lines of this sudo code...

                <code>
                    typedef void (*f_t)();

                    void selectionSort(int arr[], int n){
                        // Does something...
                    }

                    void bubbleSort(int arr[], int n){
                        // Does something...
                    }

                    void insertionSort(int arr[], int n){
                        // Does something...
                    }

                    void quickSort(int arr[], int low, int high){
                        // Does something...
                    }

                    int main(){
                        f_t functions[]={ selectionSort, bubbleSort, insertionSort, quickSort, ...all functions here };
                        for (int a = 0 ; a < sizeOfarray ; a++)
                            functions[a](argument1, argument2);
                    }
                </code>

                One problem of the code above aside from the fact I didn't compile in the first place was 
                the fact that I could not specialize what parameters I passed for functions that require 
                different arguments. 
                
                I wanted to do something along the lines of...
                <code>
                    typedef void (*f_t)();

                    void selectionSort(int arr[], int n){
                        // Does something...
                    }

                    void bubbleSort(int arr[], int n){
                        // Does something...
                    }

                    void insertionSort(int arr[], int n){
                        // Does something...
                    }

                    void quickSort(int arr[], int low, int high){
                        // Does something...
                    }

                    int main(){
                        f_t functions[]={ selectionSort(argument1, argument2), bubbleSort(argument1, argument2), insertionSort(argument1, argument2), quickSort(argument1, argument2, argument3), ...all functions here };
                        for (int a = 0 ; a < sizeOfarray ; a++)
                            functions[a];
                    }
                </code>
                What I am trying to demistrate here is that I can pre determin the parameters 
                passed to each func in functions[] then call that function when I iterate 
                throught the array.

            */
            int *arr = new int[arrSize];

            readData(file, arr, arrSize); // reset array
            cout << "Bubble Sort" << endl;
            start = clock();
            bubbleSort(arr, arrSize);
            bubbleTimeElapsed.push_back((clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

            readData(file, arr, arrSize); // reset array
            cout << "Selection Sort" << endl;
            start = clock();
            selectionSort(arr, arrSize);
            selectionTimeElapsed.push_back((clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

            readData(file, arr, arrSize); // reset array
            cout << "Insertion Sort" << endl;
            start = clock();
            insertionSort(arr, arrSize);
            insertionTimeElapsed.push_back((clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

            readData(file, arr, arrSize); // reset array
            cout << "Shell Sort" << endl;
            start = clock();
            shellSort(arr, arrSize);
            shellTimeElapsed.push_back((clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

            readData(file, arr, arrSize); // reset array
            cout << "Quick Sort" << endl;
            start = clock();
            quickSort(arr, 0, arrSize-1);
            quickTimeElapsed.push_back((clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

            readData(file, arr, arrSize); // reset array
            cout << "Merge Sort" << endl;
            start = clock();
            mergeSort(arr, 0, arrSize-1);
            mergeTimeElapsed.push_back((clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

            readData(file, arr, arrSize); // reset array
            cout << "Heap Sort" << endl;
            start = clock();
            heapSort(arr, arrSize);
            heapTimeElapsed.push_back((clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

            readData(file, arr, arrSize); // reset array
            cout << "Algorithm STL Sort" << endl;
            start = clock();
            algorithmsSTL_Sort(arr, arrSize);
            STLsortTimeElapsed.push_back((clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

            readData(file, arr, arrSize); // reset array
            cout << "Algorithm STL Stable Sort" << endl;
            start = clock();
            algorithmsSTL_Stable_Sort(arr, arrSize);
            STLstanleSortTimeElapsed.push_back((clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

            readData(file, arr, arrSize); // reset array
            start = clock();
            sequentialSearch(arr, arrSize, rand()%100 + 1);
            squentialSearchTimeElapsed.push_back((clock() - start) / (double)(CLOCKS_PER_SEC / 1000));

            start = clock();
            binarySearch(arr, arrSize, rand()%100 + 1); // arr already sorted
            binarySearchTimeElapsed.push_back((clock() - start) / (double)(CLOCKS_PER_SEC / 1000));
            
            // BST<int> tree;
            for(int i=0; i < arrSize; i++) {
                tree.insert(arr[i]);
            }
            Node<int> *n;
            start = clock();
            Node<int> *foundNode = binarySearchTree(tree, rand()%100 + 1, n);
            binarySearchTreeTimeElapsed.push_back((clock() - start) / (double)(CLOCKS_PER_SEC / 1000));


            delete [] arr;
        }
        // calc avgs
        double bubbleTimeElapsedAvg = findAvg(bubbleTimeElapsed); 
        double selectionTimeElapsedAvg = findAvg(selectionTimeElapsed); 
        double insertionTimeElapsedAvg = findAvg(insertionTimeElapsed); 
        double shellTimeElapsedAvg = findAvg(shellTimeElapsed); 
        double quickTimeElapsedAvg = findAvg(quickTimeElapsed); 
        double mergeTimeElapsedAvg = findAvg(mergeTimeElapsed); 
        double heapTimeElapsedAvg = findAvg(heapTimeElapsed); 
        double STLsortTimeElapsedAvg = findAvg(STLsortTimeElapsed); 
        double STLstanleSortTimeElapsedAvg = findAvg(STLstanleSortTimeElapsed); 
        double squentialSearchTimeElapsedAvg = findAvg(squentialSearchTimeElapsed);
        double binarySearchTimeElapsedAvg = findAvg(binarySearchTimeElapsed);
        double binarySearchTreeTimeElapsedAvg = findAvg(binarySearchTreeTimeElapsed);

        // print to out file
        ofstream fout;
        fout.open("timeComplexity.txt", std::ios_base::app);

        fout << file << endl;
        // fout << "    Average time for Binary Search Tree:    " << binarySearchTreeTimeElapsedAvg << " ms" << endl;
        // fout << "    Average time for Binary Search:         " << binarySearchTimeElapsedAvg << " ms" << endl;
        // fout << "    Average time for Sequential Search:     " << squentialSearchTimeElapsedAvg << " ms" << endl;
        // fout << "    Average time for Quick Sort:            " << quickTimeElapsedAvg << " ms" << endl;
        // fout << "    Average time for STL Sort:              " << STLsortTimeElapsedAvg << " ms" << endl;
        // fout << "    Average time for STL Stable Sort:       " << STLstanleSortTimeElapsedAvg << " ms" << endl;
        // fout << "    Average time for Shell Sort:            " << shellTimeElapsedAvg << " ms" << endl;
        // fout << "    Average time for Merge Sort:            " << mergeTimeElapsedAvg << " ms" << endl;
        // fout << "    Average time for Heap Sort:             " << heapTimeElapsedAvg << " ms" << endl;
        fout << "    Average time for Insertion Sort:        " << insertionTimeElapsedAvg << " ms" << endl;
        fout << "    Average time for Selection Sort:        " << selectionTimeElapsedAvg << " ms" << endl;
        fout << "    Average time for Bubble Sort:           " << bubbleTimeElapsedAvg << " ms" << endl;
        fout.close();
    }

    return 0;
}

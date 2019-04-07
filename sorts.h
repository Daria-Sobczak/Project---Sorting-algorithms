#pragma once

// Sortowanie przez scalanie
void merge(int *tab, int left, int middle, int right);
void MergeSort(int *tab, int left, int right);

// Sortowanie szybkie

//template <typename T>
void quicksort(int *tab, int first, int last);
//template <typename T>
void QuickSort(int *tab, int n);

// Sortowanie Shella
void ShellSort(int *tab, int size);

// Sortowanie przez kopcowanie
void buildHeap(int *tab, int index, int rozmiar);
void HeapSort(int *tab, int rozmiar);



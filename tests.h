#pragma once

#define SIZE1 10000
#define SIZE2 50000
#define SIZE3 100000
#define SIZE4 500000
#define SIZE5 1000000
#define NUMBER_OF_TAB 100

// Funkcje inicjalizuj¹ce tablice
void allTabsRandom(); // Wszystkie tablice losowe
void allTabsPartSorted(float percent); // Wszytskie tablice posortowane czesciowo
void allTabsSortedDescending(); // Wszytskie tablice posortowane malejaco

/////////////// Funkcje mierz¹ce czas ////////////////

// Dla sortowania przez scalanie:
void surveyOfMergeSort1(); // Mierzy czas dla tablic posortowanych losowo
void surveyOfMergeSort2(); // Mierzy czas dla tablic posortowanych malejaco
void surveyOfMergeSort3(float percent); // Mierzy czas dla tablic posortowanych czesciowo

// Dla sortowania szybkiego:
void surveyOfQuickSort1(); // Mierzy czas dla tablic posortowanych losowo
void surveyOfQuickSort2(); // Mierzy czas dla tablic posortowanych malejaco
void surveyOfQuickSort3(float percent); // Mierzy czas dla tablic posortowanych czesciowo

// Dla sortowania przez kopcowanie:
void surveyOfHeapSort1(); // Mierzy czas dla tablic posortowanych losowo
void surveyOfHeapSort2(); // Mierzy czas dla tablic posortowanych malejaco
void surveyOfHeapSort3(float percent); // Mierzy czas dla tablic posortowanych czesciowo

// Dla sortowania Shella
void surveyOfShellSort1(); // Mierzy czas dla tablic posortowanych losowo
void surveyOfShellSort2(); // Mierzy czas dla tablic posortowanych malejaco
void surveyOfShellSort3(float percent); // Mierzy czas dla tablic posortowanych czesciowo
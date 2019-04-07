#include "pch.h"
#include "sorts.h"

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <typeinfo>

using namespace std;


int temp[1000000];


void merge(int *tab, int left, int middle, int right)
{
	int i, j;
	
	
	//zapisuje lew¹ czêsæ podtablicy w tablicy tymczasowej
	for (i = middle + 1; i > left; i--)
		temp[i - 1] = tab[i - 1];

	//zapisuje praw¹ czêsæ podtablicy w tablicy tymczasowej w odwrotnej kolejnosci
	for (j = middle; j < right; j++)
		temp[right + middle - j] = tab[j + 1];

	//scalenie dwóch podtablic tymczasowych i zapisanie ich we w³asciwej tablicy
	for (int k = left; k <= right; k++)
		if (temp[j] < temp[i])
			tab[k] = temp[j--];
		else
			tab[k] = temp[i++];

}


void MergeSort(int *tab, int left, int right)
{
	//gdy mamy jeden element, to jest on juz posortowany
	if (right <= left) 
		return;

	//znajdowanie srodka podtablicy
	int middle = (right + left) / 2;

	//dzielenie tablicy na czesc lewa i prawa
	MergeSort(tab, left, middle);
	MergeSort(tab, middle + 1, right);

	//scala dwie posortowane tablice
	merge(tab, left, middle, right);
}

//template <typename T>
void quicksort(int *tab, int first, int last)
{
	int lower = first + 1;
	int upper = last;
	swap(tab[first], tab[(first + last) / 2]); // element osiowy umieszczany jest na poczatku
	int bound = tab[first];

	while (lower <= upper)
	{
		while (tab[lower] < bound)
			lower++;
		while (bound < tab[upper])
			upper--;
		if (lower < upper)
			swap(tab[lower++], tab[upper--]);
		else
			lower++;
	}
	swap(tab[upper], tab[first]); // upper wskazuje polozenie skrajnego prawego elementu pierwszej podtablicy (nie jest wiekszy od granicy) i zsoatje zaminiony z elementem osiowym
	if (first < upper - 1)
		quicksort(tab, first, upper - 1); // wywoalanie dla lewej podtablicy
	if (upper + 1 < last)
		quicksort(tab, upper + 1, last); // wywoalnie dla prawej podtablicy
}


//template <typename T>
void QuickSort(int *tab, int n)
{
	int i, max;

	if (n < 2)
		return; // to juz jest posortowane
	for (i = 1, max = 0; i < n; i++)
		if (tab[max] < tab[i]) // znajdywanie najwiekszego elementu
			max = i;
	swap(tab[n - 1], tab[max]); // umieszczenie najwiekszego elementu na koncu
	quicksort(tab, 0, n - 2); // wywolanie funkcji sortujacej dla tablicy o 1 mniejszej (pomijamy ostatni)
}


void ShellSort(int *tab, int size)
{
	for (int podtablica = size / 2; podtablica > 0; podtablica /= 2)
	{
		for (int i = podtablica; i < size; i += 1)
		{
			int temp = tab[i]; int j;
			for (j = i; j >= podtablica && tab[j - podtablica] > temp; j -= podtablica)
				tab[j] = tab[j - podtablica];

			tab[j] = temp;
		}
	}
}


void buildHeap(int *tab, int index, int size)
{
	int j;
	while (index <= size / 2)
	{
		j = 2 * index;
		if (j + 1 <= size && tab[j + 1] > tab[j]) // drugi jest wiekszy 
			j = j + 1;
		if (tab[index] < tab[j]) // jesli trzeba zamien dziecko z jego rodzicem 
		{
			int temp = tab[index];
			tab[index] = tab[j];
			tab[j] = temp;
		}
		else break;
		index = j; //przechodzimy nizej
	}
}

void HeapSort(int *tab, int size)
{
	int i;

	for (i = size / 2; i > 0; --i) // utworzenie kopca 
		buildHeap(tab - 1, i, size);
	for (i = size - 1; i > 0; --i)
	{
		int temp = tab[0];
		tab[0] = tab[i]; // przesuniecie najwiekszego elementu  do tab[i]
		tab[i] = temp;
		buildHeap(tab - 1, 1, i); // przywrocenie wlasnosci kopca
	}

}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


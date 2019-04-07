#include "pch.h"
#include "tests.h"
#include "sorts.h"
//#include "sorts.cpp"

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <typeinfo>


int tab_10k[NUMBER_OF_TAB][SIZE1];
int tab_50k[NUMBER_OF_TAB][SIZE2];
int tab_100k[NUMBER_OF_TAB][SIZE3];
int tab_500k[NUMBER_OF_TAB][SIZE4];
int tab_milion[NUMBER_OF_TAB][SIZE5];

using namespace std;

void allTabsRandom()
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		for (int a = 0; a < SIZE1; a++)
			tab_10k[i][a] = rand() % SIZE1;

		for (int a = 0; a < SIZE2; a++)
			tab_50k[i][a] = rand() % SIZE2;

		for (int a = 0; a < SIZE3; a++)
			tab_100k[i][a] = rand() % SIZE3;


		for (int a = 0; a < SIZE4; a++)
			tab_500k[i][a] = rand() % SIZE4;

		for (int a = 0; a < SIZE5; a++)
			tab_milion[i][a] = rand() % SIZE5;

	}

}


void allTabsPartSorted(float percent)
{
	allTabsRandom();

	int *wsk; // wskaŸnik pomocniczny wskazuj¹cy na poczatek tablicy


	int length = (int)(percent / 100) * SIZE1;
	for (unsigned int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_10k[i][0];
		std::sort(wsk, wsk + length);
	}

	length = (int)(percent / 100) * SIZE2;
	for (unsigned int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_50k[i][0];
		std::sort(wsk, wsk + length);
	}

	length = (int)(percent / 100) * SIZE3;
	for (unsigned int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_100k[i][0];
		std::sort(wsk, wsk + length);
	}

	length = (int)(percent / 100) * SIZE4;
	for (unsigned int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_500k[i][0];
		std::sort(wsk, wsk + length);
	}

	length = (int)(percent / 100) * SIZE5;
	for (unsigned int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_milion[i][0];
		std::sort(wsk, wsk + length);
	}

}

void allTabsSortedDescending()
{
	allTabsRandom();

	int *wsk;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_10k[i][0];
		std::sort(wsk, wsk + SIZE1, std::greater<int>());
	}

	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_50k[i][0];
		std::sort(wsk, wsk + SIZE2, std::greater<int>());
	}

	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_100k[i][0];
		std::sort(wsk, wsk + SIZE3, std::greater<int>());
	}

	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_500k[i][0];
		std::sort(wsk, wsk + SIZE4, std::greater<int>());
	}

	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_milion[i][0];
		std::sort(wsk, wsk + SIZE5, std::greater<int>());
	}

}

///////////////////////////////////////////////////// MERGESORT /////////////////////////////////////////////////////////


void surveyOfMergeSort1()
{
	int * wsk; // wskaznik pomocniczy

	allTabsRandom();

	ofstream record("MergeSortRandom.txt");
	record << "Tablice 10k" << "\n";

	// Tablice o wielkosci 10k
	cout << "Start  testu dla 100 tablic 10k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_10k[i][0];

		auto start = std::chrono::system_clock::now();
		MergeSort(wsk, 0, SIZE1 - 1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 10k" << endl;

	record << "\n";
	record << "Tablice 50k " << "\n";
	// Tablice o wielkosci 50k
	cout << "Start  testu dla 100 tablic 50k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_50k[i][0];

		auto start = std::chrono::system_clock::now();
		MergeSort(wsk, 0, SIZE2 - 1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 50k" << endl;

	record << "\n";
	record << "Tablice 100k " << "\n";
	// Tablice o wielkosci 100k
	cout << "Start  testu dla 100 tablic 100k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_100k[i][0];

		auto start = std::chrono::system_clock::now();
		MergeSort(wsk, 0, SIZE3 - 1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 100k" << endl;

	record << "\n";
	record << "Tablice 500k " << "\n";
	// Tablice o wielkosci 500k
	cout << "Start  testu dla 100 tablic 500k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_500k[i][0];

		auto start = std::chrono::system_clock::now();
		MergeSort(wsk, 0, SIZE4 - 1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 500k" << endl;

	record << "\n";
	record << "Tablice 1000000" << "\n";
	// Tablice o wielkosci milion
	cout << "Start  testu dla 100 tablic 1000000" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_milion[i][0];

		auto start = std::chrono::system_clock::now();
		MergeSort(wsk, 0, SIZE5 - 1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 1000000" << endl;

	record.close();
}



void surveyOfMergeSort2()
{
	int * wsk; // wskaznik pomocniczy

	allTabsSortedDescending();

	ofstream record("MergeSorted.txt");
	record << "Tablice 10k" << "\n";
	// Tablice o wielkosci 10k
	cout << "Start  testu dla 100 tablic 10k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_10k[i][0];

		auto start = std::chrono::system_clock::now();
		MergeSort(wsk, 0, SIZE1 - 1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 10k" << endl;
	
	record << "\n";
	record << "Tablice 50k \n";
	// Tablice o wielkosci 50k
	cout << "Start  testu dla 100 tablic 50k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_50k[i][0];

		auto start = std::chrono::system_clock::now();
		MergeSort(wsk, 0, SIZE2 - 1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 50k" << endl;

	record << "\n";
	record << "Tablice 100k \n";
	// Tablice o wielkosci 100k
	cout << "Start  testu dla 100 tablic 100k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_100k[i][0];

		auto start = std::chrono::system_clock::now();
		MergeSort(wsk, 0, SIZE3 - 1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 100k" << endl;

	record << "\n";
	record << "Tablice 500k \n";
	// Tablice o wielkosci 500k
	cout << "Start  testu dla 100 tablic 500k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_500k[i][0];

		auto start = std::chrono::system_clock::now();
		MergeSort(wsk, 0, SIZE4 - 1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 500k" << endl;

	record << "\n";
	record << "Tablice 1000000 \n";
	// Tablice o wielkosci milion
	cout << "Start  testu dla 100 tablic 1000000" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_milion[i][0];

		auto start = std::chrono::system_clock::now();
		MergeSort(wsk, 0, SIZE5 - 1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 1000000" << endl;

	record.close();
	
}



void surveyOfMergeSort3(float percent)
{
	int * wsk; // wskaznik pomocniczy

	allTabsPartSorted(percent);
	cout << "Pomiar w przypadku tablic posortowanych w " << percent << " %" << endl;

	ofstream record("MergeSort99,7%.txt");
	record << "Tablice 10k" << "\n";
	// Tablice o wielkosci 10k
	cout << "Start  testu dla 100 tablic 10k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_10k[i][0];

		auto start = std::chrono::system_clock::now();
		MergeSort(wsk, 0, SIZE1 - 1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 10k" << endl;

	record << "\n";
	record << "Tablice 50k \n";
	// Tablice o wielkosci 50k
	cout << "Start  testu dla 100 tablic 50k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_50k[i][0];

		auto start = std::chrono::system_clock::now();
		MergeSort(wsk, 0, SIZE2 - 1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 50k" << endl;

	record << "\n";
	record << "Tablice 100k \n";
	// Tablice o wielkosci 100k
	cout << "Start  testu dla 100 tablic 100k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_100k[i][0];

		auto start = std::chrono::system_clock::now();
		MergeSort(wsk, 0, SIZE3 - 1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 100k" << endl;

	record << "\n";
	record << "Tablice 500k \n";
	// Tablice o wielkosci 500k
	cout << "Start  testu dla 100 tablic 500k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_500k[i][0];

		auto start = std::chrono::system_clock::now();
		MergeSort(wsk, 0, SIZE4 - 1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 500k" << endl;

	record << "\n";
	record << "Tablice 1000000 \n";
	// Tablice o wielkosci milion
	cout << "Start  testu dla 100 tablic 1000000" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_milion[i][0];

		auto start = std::chrono::system_clock::now();
		MergeSort(wsk, 0, SIZE5 - 1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 1000000" << endl;

	record.close();
}

/////////////////////////////////////////////////////// QUICKSORT ////////////////////////////////////////////


void surveyOfQuickSort1()
{
	int * wsk; // wskaznik pomocniczy

	allTabsRandom();

	ofstream record("QuickSortRandom.txt");
	record << "Tablice 10k" << "\n";
	// Tablice o wielkosci 10k
	cout << "Start  testu dla 100 tablic 10k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_10k[i][0];

		auto start = std::chrono::system_clock::now();
		QuickSort(wsk, SIZE1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 10k" << endl;

	record << "\n";
	record << "Tablice 50k \n";
	// Tablice o wielkosci 50k
	cout << "Start  testu dla 100 tablic 50k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_50k[i][0];

		auto start = std::chrono::system_clock::now();
		QuickSort(wsk, SIZE2);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 50k" << endl;

	record << "\n";
	record << "Tablice 100k \n";
	// Tablice o wielkosci 100k
	cout << "Start  testu dla 100 tablic 100k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_100k[i][0];

		auto start = std::chrono::system_clock::now();
		QuickSort(wsk, SIZE3);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 100k" << endl;

	record << "\n";
	record << "Tablice 500k \n";
	// Tablice o wielkosci 500k
	cout << "Start  testu dla 100 tablic 500k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_500k[i][0];

		auto start = std::chrono::system_clock::now();
		QuickSort(wsk, SIZE4);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 500k" << endl;

	record << "\n";
	record << "Tablice 1000000 \n";
	// Tablice o wielkosci 1000000
	cout << "Start  testu dla 100 tablic 1000000" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_milion[i][0];

		auto start = std::chrono::system_clock::now();
		QuickSort(wsk, SIZE5);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 1000000" << endl;

	record.close();
}

/*

void surveyOfQuickSort2()
{
	int * wsk; // wskaznik pomocniczy

	allTabsSortedDescending();

	ofstream record("QuickSorted.txt");
	record << "Tablice 10k" << "\n";

	// Tablice o wielkosci 10k
	cout << "Start  testu dla 100 tablic 10k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_10k[i][0];

		auto start = std::chrono::system_clock::now();
		QuickSort(wsk, SIZE1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 10k" << endl;

	record << "\n";
	record << "Tablice 50k \n";
	// Tablice o wielkosci 50k
	cout << "Start  testu dla 100 tablic 50k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_50k[i][0];

		auto start = std::chrono::system_clock::now();
		QuickSort(wsk, SIZE2);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 50k" << endl;

	record << "\n";
	record << "Tablice 100k \n";
	// Tablice o wielkosci 100k
	cout << "Start  testu dla 100 tablic 100k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_100k[i][0];

		auto start = std::chrono::system_clock::now();
		QuickSort(wsk, SIZE3);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 100k" << endl;

	record << "\n";
	record << "Tablice 500k \n";
	// Tablice o wielkosci 500k
	cout << "Start  testu dla 100 tablic 500k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_500k[i][0];

		auto start = std::chrono::system_clock::now();
		QuickSort(wsk, SIZE4);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 500k" << endl;

	record << "\n";
	record << "Tablice 1000000 \n";
	// Tablice o wielkosci 1000000
	cout << "Start  testu dla 100 tablic 1000000" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_milion[i][0];

		auto start = std::chrono::system_clock::now();
		QuickSort(wsk, SIZE5);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 1000000" << endl;

	record.close();
}



void surveyOfQuickSort3(float percent)
{
	int * wsk; // wskaznik pomocniczy

	allTabsPartSorted(percent);
	
	ofstream record("QuickSort99,7%.txt");
	record << "Tablice 10k" << "\n";
	cout << "Pomiar w przypadku tablic posortowanych w " << percent << " %" << endl;
	// Tablice o wielkosci 10k
	cout << "Start  testu dla 100 tablic 10k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_10k[i][0];

		auto start = std::chrono::system_clock::now();
		QuickSort(wsk, SIZE1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 10k" << endl;

	record << "\n";
	record << "Tablice 50k \n";
	// Tablice o wielkosci 50k
	cout << "Start  testu dla 100 tablic 50k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_50k[i][0];

		auto start = std::chrono::system_clock::now();
		QuickSort(wsk, SIZE2);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 50k" << endl;

	record << "\n";
	record << "Tablice 100k \n";
	// Tablice o wielkosci 100k
	cout << "Start  testu dla 100 tablic 100k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_100k[i][0];

		auto start = std::chrono::system_clock::now();
		QuickSort(wsk, SIZE3);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 100k" << endl;

	record << "\n";
	record << "Tablice 500k \n";
	// Tablice o wielkosci 500k
	cout << "Start  testu dla 100 tablic 500k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_500k[i][0];

		auto start = std::chrono::system_clock::now();
		QuickSort(wsk, SIZE4);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 500k" << endl;

	record << "\n";
	record << "Tablice 1000000 \n";
	// Tablice o wielkosci 1000000
	cout << "Start  testu dla 100 tablic 1000000" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_milion[i][0];

		auto start = std::chrono::system_clock::now();
		QuickSort(wsk, SIZE5);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 1000000" << endl;

	record.close();
}
*/


/////////////////////////////////////////////// HEAPSORT ////////////////////////////////////////////////



void surveyOfHeapSort1()
{
	int * wsk; // wskaznik pomocniczy

	allTabsRandom();

	ofstream record("HeapSortRandom.txt");
	record << "Tablice 10k" << "\n";
	// Tablice o wielkosci 10k
	cout << "Start  testu dla 100 tablic 10k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_10k[i][0];

		auto start = std::chrono::system_clock::now();
		HeapSort(wsk, SIZE1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 10k" << endl;

	record << "\n";
	record << "Tablice 50k \n";
	// Tablice o wielkosci 50k
	cout << "Start  testu dla 100 tablic 50k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_50k[i][0];

		auto start = std::chrono::system_clock::now();
		HeapSort(wsk, SIZE2);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 50k" << endl;

	record << "\n";
	record << "Tablice 100k \n";
	// Tablice o wielkosci 100k
	cout << "Start  testu dla 100 tablic 100k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_100k[i][0];

		auto start = std::chrono::system_clock::now();
		HeapSort(wsk, SIZE3);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 100k" << endl;

	record << "\n";
	record << "Tablice 500k \n";
	// Tablice o wielkosci 500k
	cout << "Start  testu dla 100 tablic 500k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_500k[i][0];

		auto start = std::chrono::system_clock::now();
		HeapSort(wsk, SIZE4);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 500k" << endl;

	record << "\n";
	record << "Tablice 1000000 \n";
	// Tablice o wielkosci 1000000
	cout << "Start  testu dla 100 tablic 1000000" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_milion[i][0];

		auto start = std::chrono::system_clock::now();
		HeapSort(wsk, SIZE5);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 1000000" << endl;

	record.close();
}


void surveyOfHeapSort2()
{
	int * wsk; // wskaznik pomocniczy

	allTabsSortedDescending();

	ofstream record("HeapSorted.txt");
	record << "Tablice 10k" << "\n";

	// Tablice o wielkosci 10k
	cout << "Start  testu dla 100 tablic 10k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_10k[i][0];

		auto start = std::chrono::system_clock::now();
		HeapSort(wsk, SIZE1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 10k" << endl;

	record << "\n";
	record << "Tablice 50k \n";
	// Tablice o wielkosci 50k
	cout << "Start  testu dla 100 tablic 50k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_50k[i][0];

		auto start = std::chrono::system_clock::now();
		HeapSort(wsk, SIZE2);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 50k" << endl;

	record << "\n";
	record << "Tablice 100k \n";
	// Tablice o wielkosci 100k
	cout << "Start  testu dla 100 tablic 100k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_100k[i][0];

		auto start = std::chrono::system_clock::now();
		HeapSort(wsk, SIZE3);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 100k" << endl;

	record << "\n";
	record << "Tablice 500k \n";
	// Tablice o wielkosci 500k
	cout << "Start  testu dla 100 tablic 500k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_500k[i][0];

		auto start = std::chrono::system_clock::now();
		HeapSort(wsk, SIZE4);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 500k" << endl;

	record << "\n";
	record << "Tablice 1000000 \n";
	// Tablice o wielkosci 1000000
	cout << "Start  testu dla 100 tablic 1000000" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_milion[i][0];

		auto start = std::chrono::system_clock::now();
		HeapSort(wsk, SIZE5);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 1000000" << endl;

	record.close();
}




void surveyOfHeapSort3(float percent)
{
	int * wsk; // wskaznik pomocniczy

	allTabsPartSorted(percent);
	cout << "Pomiar w przypadku tablic posortowanych w " << percent << " %" << endl;

	ofstream record("HeapSort99,7%.txt");
	record << "Tablice 10k" << "\n";
	// Tablice o wielkosci 10k
	cout << "Start  testu dla 100 tablic 10k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_10k[i][0];

		auto start = std::chrono::system_clock::now();
		HeapSort(wsk, SIZE1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 10k" << endl;

	record << "\n";
	record << "Tablice 50k \n";
	// Tablice o wielkosci 50k
	cout << "Start  testu dla 100 tablic 50k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_50k[i][0];

		auto start = std::chrono::system_clock::now();
		HeapSort(wsk, SIZE2);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 50k" << endl;

	record << "\n";
	record << "Tablice 100k \n";
	// Tablice o wielkosci 100k
	cout << "Start  testu dla 100 tablic 100k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_100k[i][0];

		auto start = std::chrono::system_clock::now();
		HeapSort(wsk, SIZE3);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 100k" << endl;

	record << "\n";
	record << "Tablice 500k \n";
	// Tablice o wielkosci 500k
	cout << "Start  testu dla 100 tablic 500k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_500k[i][0];

		auto start = std::chrono::system_clock::now();
		HeapSort(wsk, SIZE4);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 500k" << endl;

	record << "\n";
	record << "Tablice 1000000 \n";
	// Tablice o wielkosci 1000000
	cout << "Start  testu dla 100 tablic 1000000" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_milion[i][0];

		auto start = std::chrono::system_clock::now();
		HeapSort(wsk, SIZE5);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
		record << durationTime << "\n";
	}
	cout << "Koniec testu dla tabic 1000000" << endl;

	record.close();
}


///////////////////////////////////////////// SHELLSORT /////////////////////////////////////////////////

void surveyOfShellSort1()
{
	int * wsk; // wskaznik pomocniczy

	allTabsRandom();

	// Tablice o wielkosci 10k
	cout << "Start  testu dla 100 tablic 10k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_10k[i][0];

		auto start = std::chrono::system_clock::now();
		ShellSort(wsk, SIZE1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
	}
	cout << "Koniec testu dla tabic 10k" << endl;

	// Tablice o wielkosci 50k
	cout << "Start  testu dla 100 tablic 50k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_50k[i][0];

		auto start = std::chrono::system_clock::now();
		ShellSort(wsk, SIZE2);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
	}
	cout << "Koniec testu dla tabic 50k" << endl;

	// Tablice o wielkosci 100k
	cout << "Start  testu dla 100 tablic 100k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_100k[i][0];

		auto start = std::chrono::system_clock::now();
		ShellSort(wsk, SIZE3);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
	}
	cout << "Koniec testu dla tabic 100k" << endl;

	// Tablice o wielkosci 500k
	cout << "Start  testu dla 100 tablic 500k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_500k[i][0];

		auto start = std::chrono::system_clock::now();
		ShellSort(wsk, SIZE4);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
	}
	cout << "Koniec testu dla tabic 500k" << endl;

	// Tablice o wielkosci milion
	cout << "Start  testu dla 100 tablic 1000000" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_milion[i][0];

		auto start = std::chrono::system_clock::now();
		ShellSort(wsk, SIZE5);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
	}
	cout << "Koniec testu dla tabic 1000000" << endl;
}



void surveyOfShellSort2()
{
	int * wsk; // wskaznik pomocniczy

	allTabsSortedDescending();

	// Tablice o wielkosci 10k
	cout << "Start  testu dla 100 tablic 10k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_10k[i][0];

		auto start = std::chrono::system_clock::now();
		ShellSort(wsk, SIZE1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
	}
	cout << "Koniec testu dla tabic 10k" << endl;

	// Tablice o wielkosci 50k
	cout << "Start  testu dla 100 tablic 50k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_50k[i][0];

		auto start = std::chrono::system_clock::now();
		ShellSort(wsk, SIZE2);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
	}
	cout << "Koniec testu dla tabic 50k" << endl;

	// Tablice o wielkosci 100k
	cout << "Start  testu dla 100 tablic 100k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_100k[i][0];

		auto start = std::chrono::system_clock::now();
		ShellSort(wsk, SIZE3);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
	}
	cout << "Koniec testu dla tabic 100k" << endl;

	// Tablice o wielkosci 500k
	cout << "Start  testu dla 100 tablic 500k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_500k[i][0];

		auto start = std::chrono::system_clock::now();
		ShellSort(wsk, SIZE4);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
	}
	cout << "Koniec testu dla tabic 500k" << endl;

	// Tablice o wielkosci milion
	cout << "Start  testu dla 100 tablic 1000000" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_milion[i][0];

		auto start = std::chrono::system_clock::now();
		ShellSort(wsk, SIZE5);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
	}
	cout << "Koniec testu dla tabic 1000000" << endl;
}





void surveyOfShellSort3(float percent)
{
	int * wsk; // wskaznik pomocniczy

	allTabsPartSorted(percent);
	cout << "Pomiar w przypadku tablic posortowanych w " << percent << " %" << endl;

	// Tablice o wielkosci 10k
	cout << "Start  testu dla 100 tablic 10k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_10k[i][0];

		auto start = std::chrono::system_clock::now();
		ShellSort(wsk, SIZE1);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
	}
	cout << "Koniec testu dla tabic 10k" << endl;

	// Tablice o wielkosci 50k
	cout << "Start  testu dla 100 tablic 50k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_50k[i][0];

		auto start = std::chrono::system_clock::now();
		ShellSort(wsk, SIZE2);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
	}
	cout << "Koniec testu dla tabic 50k" << endl;

	// Tablice o wielkosci 100k
	cout << "Start  testu dla 100 tablic 100k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_100k[i][0];

		auto start = std::chrono::system_clock::now();
		ShellSort(wsk, SIZE3);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
	}
	cout << "Koniec testu dla tabic 100k" << endl;

	// Tablice o wielkosci 500k
	cout << "Start  testu dla 100 tablic 500k" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_500k[i][0];

		auto start = std::chrono::system_clock::now();
		ShellSort(wsk, SIZE4);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
	}
	cout << "Koniec testu dla tabic 500k" << endl;

	// Tablice o wielkosci milion
	cout << "Start  testu dla 100 tablic 1000000" << endl;
	for (int i = 0; i < NUMBER_OF_TAB; i++)
	{
		wsk = &tab_milion[i][0];

		auto start = std::chrono::system_clock::now();
		ShellSort(wsk, SIZE5);
		auto end = std::chrono::system_clock::now();

		std::chrono::duration<double> diff = end - start;
		double durationTime = diff.count();
		cout << "Wynik: " << durationTime << endl;
	}
	cout << "Koniec testu dla tabic 1000000" << endl;
}
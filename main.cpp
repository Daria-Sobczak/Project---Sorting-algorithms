// main.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "sorts.h"
//#include "sorts.cpp"
#include "tests.h"
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;

int main()
{
	//surveyOfMergeSort1();
	//surveyOfMergeSort2();
	//surveyOfMergeSort3(99.7);
	surveyOfQuickSort1();
	//surveyOfQuickSort2();
	//surveyOfQuickSort3(99.7);
	//surveyOfHeapSort1();
	//surveyOfHeapSort2();
	//surveyOfHeapSort3(99.7);
	//surveyOfShellSort1();


	/*
	
	for (int j = 0; j < 100; j++) {
		int n = 1000000;
		int tab[1000000];
		int *tab_copy=new int[n];
		for (int i = 0; i < n; i++)
		{
			tab[i] = (rand());
			tab_copy[i] = tab[i];
		}
		int *wsk;
		wsk = &tab[0];
		std::sort(wsk, wsk + n, std::greater<int>());
		auto start = std::chrono::system_clock::now();
		HeapSort(wsk, n);
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> diff = end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
		double durationTime = diff.count(); // zmierzony czas zapisa do pliku lub zagregowa, zapisa liczb badanych elementw
		cout << "Wynik: " << durationTime << endl;
		//std::sort(tab_copy, tab_copy + n);
		//if (std::equal(tab_copy, tab_copy + n, tab, tab + n))
			//cout << "  OK" << endl;

			
	}
	*/
	
	
	cout << "KONIEC" << endl;
}


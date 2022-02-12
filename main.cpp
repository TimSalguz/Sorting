#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include <algorithm>
#include <chrono>
#include "functions.hpp"
#include "classes.hpp"

using namespace std::chrono_literals;


namespace ts
{
	void swapSort(int *array, int count)
	{
	for(long i = 1; i < count; ++i)
		for(long j = 0; j < count-1; ++j)
			if(array[j]>array[i])
				std::swap(array[i], array[j]);
	}

	void bubbleSort(int *array, int count)
	{
	for(long j = 0; j < count; j++)
		for(long i = 0; i < count; ++i)
			if(array[i]>array[i+1])
				std::swap(array[i], array[i+1]);
	}

	void qSort(int *x, int a, int b)
	{
		if (a >= b) {
        return;
    }
		int m = rand() % (b - a + 1) + a;
		int k = x[m];
		int l = a-1;
		int r = b+1;
		while(1)
		{
			do
			{
				l = l + 1; 
			}
			while (x[l] < k);

			do
			{
				r = r - 1; 
			}
			while (x[r] > k);
			
			if (l >= r)
				break;
			
			std::swap(x[l], x[r]);
		}
		
		r = l;
		l = l - 1;
		qSort(x, a, l);
		qSort(x, r, b);
	}


	}

int main()
{                                                         
	const long minrandom = 0;                            
	const long maxrandom = 100;                         
	long count = 1000000;                                       
	std::ofstream befout("input.txt");
	std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
	int *array = new int[count];
	// FILL ARRAY
	for (int i = 0; i < count; ++i)
	{
		array[i] = ts::Random(i, minrandom, maxrandom);
	}

	std::cout << "BEFORE SORT: " << std::endl;
	for (int i = 0; i < count; ++i)
	{
		befout << array[i] << std::endl;
	}


	ts::Timer timer;


	ts::bubbleSort(array, count);
	//std::sort(array, array+count);

	



	//SORTING
	// for (int i = 0; i < count; ++i)
	// {
	// 	if ((array[i]%2) != 0)
	// 	{
	// 		tempArray[j] = array[i];
	// 		j++;
	// 	}
	// 	else
	// 	{
	// 		tempArray[j] = array[i];
	// 		j++;
	// 		tempArray[j] = array[i];
	// 		j++;
	// 	}
	// }
	// array = tempArray;
	// count += chet;
    std::cout << "Time elapsed: " << timer.elapsed() << '\n';



	std::cout << "AFTER SORT: " << std::endl;
	for (int i = 0; i < count; ++i)
	{
		fout << array[i] << std::endl;
	}

	delete[] array;
    return 0;
}
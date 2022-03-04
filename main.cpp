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
	for (int i = 1; i < count; i++)
	{
		if (array[i] >= array[i - 1])
		{
			continue;
		}
		int j = i - 1;
		while (j >= 0 && array[j] > array[j + 1])
		{
			std::swap(array[j], array[j + 1]);
			j = j - 1;
		}
	}

}

	void qSort(int *x, int a, int b)
	{
		if (a >= b) {
        return;
    }
		int m = (rand()*rand()) % (b - a + 1) + a;
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

	void binarySearch(int *array, int count, int find)
	{
	int maxElem = count;
	int minElem = 0;
	for(; ; )
	{
		int promCount = maxElem-minElem;
		int oldPromCount = promCount;
		promCount /= 2;

		std::cout << "promcount = " << array[promCount] << std::endl;
		std::cout << "promcount = " << promCount << std::endl;
		std::cout << "oldpromcount = " << oldPromCount << std::endl;

		if(maxElem-minElem == 0)
			break;
		if(maxElem-minElem == 1)
			if (array[minElem] == find)
			{
				std::cout << "FOUNDED! Element number " << minElem << std::endl;
				break;
			}
			else if (array[maxElem] == find)
			{
				std::cout << "FOUNDED! Element number " << maxElem << std::endl;
				break;
			}
			else
			{
				std::cout << "Element " << find << " not found!" << std::endl;
				break;
			}
		if(array[minElem] == find)
		{
			std::cout << "FOUNDED! Element number " << minElem << std::endl;
			break;
		}
		if(find > array[minElem+promCount])
		{
			minElem += promCount;
			std::cout << ">Min = " << minElem << " Max = " << maxElem << std::endl;
		}
		else if (array[minElem+promCount] == find)
		{
			std::cout << "FOUNDED! Element number " << minElem+promCount << std::endl;
			break;
		}
		else
		{
			maxElem -= promCount;
			std::cout << "<Min = " << minElem << " Max = " << maxElem << std::endl;
		}
	}
	}

	}

int main()
{                                                         
	const long minrandom = 0;                            
	const long maxrandom = 10000000;                         
	long count = 100000;    
	std::ifstream fin("input.txt");
    std::ofstream foutsort("sorted.txt");
	int *array = new int[count];
	// FILL ARRAY
	// std::ofstream fout("input.txt");
	// for (int i = 0; i < count; ++i)
	// {
	// 	array[i] = ts::Random(i, minrandom, maxrandom);
	// }
	// for (int i = 0; i < count; ++i)
	// {
	// 	fout << array[i] << std::endl;
	// }

	for (int i = 0; i < count; ++i)
	{
		fin >> array[i];
	}
	

	ts::Timer timer;

	//std::cout << findMax(array, count, 0, INT_MAX) << std::endl;
	//ts::bubbleSort(array, count);
	std::sort(array, array+count);

	int find = 977578;
	std::cout << "we want to find: " << find << std::endl;
	ts::binarySearch(array, count, find);


    std::cout << "Time elapsed: " << timer.elapsed() << '\n';



	std::cout << "AFTER SORT: " << std::endl;
	for (int i = 0; i < count; ++i)
	{
		foutsort << array[i] << std::endl;
	}

	delete[] array;
    return 0;
}
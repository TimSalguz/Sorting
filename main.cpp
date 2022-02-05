#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include <algorithm>
#include <chrono>
#include "functions.hpp"
#include "classes.hpp"

using namespace std::chrono_literals;

int main()
{
	const long minrandom = 0;
	const long maxrandom = 100;
	long count = 1000000;
	std::ofstream befout("input.txt");
	std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
	int *array = new int[count];
	//FILL ARRAY
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
	int chet = 0;
	for (int i = 0; i < count; ++i)
	{
		if((array[i] % 2) == 0)
			chet++;
	}
	int *tempArray = new int[count+chet];
	int j = 0;
	//SORTING
	for (int i = 0; i < count; ++i)
	{
		if ((array[i]%2) != 0)
		{
			tempArray[j] = array[i];
			j++;
		}
		else
		{
			tempArray[j] = array[i];
			j++;
			tempArray[j] = array[i];
			j++;
		}
	}
	array = tempArray;
	count += chet;
    std::cout << "Time elapsed: " << timer.elapsed() << '\n';



	std::cout << "AFTER SORT: " << std::endl;
	for (int i = 0; i < count; ++i)
	{
		fout << array[i] << std::endl;
	}

	delete[] array;
    return 0;
}
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
	long count = 10;


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

	//SORTING
	for (int i = 0; i < count; ++i)
	{
		if(array[i] % 2 == 0)
		{
			//Делаю массив больше на 1
			int *tempArray = new int[count+1];
			for (int j = 0; j < count; ++j)
			{
				tempArray[j] = array[j];
			}
			delete[] array;
			count++;

			//Дублирую элемент, перенося все вправо
			for(int k = count-1; k > 1; k--) //каунт = 11, поэтому беру 10й элемент, потом беру 9й
			{
				array[k] = array[k-1]; //10й элемент равен 9му, потом 9 элемент равен 8му
			}
			std::cout << count;
			i++;
		}
	}

    std::cout << "Time elapsed: " << timer.elapsed() << '\n';

	std::cout << "AFTER SORT: " << std::endl;
	for (int i = 0; i < count; ++i)
	{
		fout << array[i] << std::endl;
	}

	delete[] array;
    return 0;
}
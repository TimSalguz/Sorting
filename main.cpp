#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include <algorithm>

using namespace std;

int main()
{
	const long minrandom = 0;
	const long maxrandom = 100000000;
	const long count = 10000000;

	ofstream befout("input.txt");
	ifstream fin("input.txt");
    ofstream fout("output.txt");

    std::mt19937 mersenne(time(0));
	int random;

	int *array = new int[count];

	//FILL ARRAY
	for (int i = 0; i < count; i++)
	{
		for (; ;)
		{
			random = mersenne()%maxrandom+1;
			if(random < minrandom)
			{
				random = mersenne()%maxrandom+1;
			}
			else
				break;
		}
		array[i] = random;
		random = 0;
	}

	std::cout << "BEFORE SORT: " << std::endl;
	for (int i = 0; i < count; i++)
	{
		befout << array[i] << std::endl;
	}

	//SORTING
	std::sort(array, array+count);

	std::cout << "AFTER SORT: " << std::endl;
	for (int i = 0; i < count; i++)
	{
		fout << array[i] << std::endl;
	}

	delete[] array;
    return 0;
}
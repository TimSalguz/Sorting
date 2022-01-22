#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include <algorithm>

using namespace std;

int main()
{
	const int minrandom = 0;
	const int maxrandom = 100000;
	const int count = 100000;

	ifstream fin("input.txt");
    ofstream fout("output.txt");

    std::mt19937 mersenne(time(0));
	int random;

	int array[count];
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

	//std::cout << "BEFORE SORT: " << std::endl;
	//for (int i = 0; i < count; i++)
	//{
		//std::cout << array[i] << std::endl;
	//}

	std::sort(array, array+count);

	std::cout << "AFTER SORT: " << std::endl;
	for (int i = 0; i < count; i++)
	{
		fout << array[i] << std::endl;
	}
    return 0;
}
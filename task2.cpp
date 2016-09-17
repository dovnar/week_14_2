#include <iostream>
using namespace std;
int* distributesArray(int* arr, int const* size);
void printArray(int* arr, int const* size);
int main()
{
	int const size{ 20 };
	int arr[size]{ -12,0,-1,15,0,16,-5,-4,3,0,5,-15,0,2,0,-2,-8,8,4,0 };
	printArray(arr, &size);
	distributesArray(arr, &size);
}

int* distributesArray(int * arr, int const* size)
{
	int sizeNull = 0;
	int sizePlus = 0;
	int sizeMinus = 0;
	for (int i = 0; i < *size; i++)
	{
		if (*(arr +i) > 0)
		{
			sizePlus++;
		}
		else if (*(arr + i) < 0)
		{
			sizeMinus++;
		}
		else
		{
			sizeNull++;
		}
	}
	int* arrPlus = new int[sizePlus];
	int* arrMinus = new int[sizeMinus];
	int* arrNull = new int[sizeNull];
	for (int i = 0, j = 0, l = 0, k = 0; i < *size; i++)
	{
		if (*(arr + i) > 0)
		{
			*(arrPlus + j) = *(arr + i);
			j++;

		}
		else if (*(arr + i) < 0)
		{
			*(arrMinus + l) = *(arr + i);
			l++;
		}
		else
		{
			*(arrNull + k) = *(arr + i);
			k++;
		}
	}
	printArray(arrPlus, &sizePlus);
	printArray(arrMinus, &sizeMinus);
	printArray(arrNull, &sizeNull);
	return 0;
}

void printArray(int * arr, int const* size)
{
	for (int i = 0; i < *size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}

#include <iostream>

using namespace std;

int* deletePrimesInArray(int* arr, int* size);
void printArray(int* arr, int size);

int main()
{
	int size{ 20 };
	int* arr = new int[size] { 7, 3, 15, 6, 14, 13, 43, 12, 18, 21, 54, 51, 26, 1, 35, 62, 29, 42, 34, 27 };
	printArray(arr, size);
	arr = deletePrimesInArray(arr, &size);
	printArray(arr, size);
}

int* deletePrimesInArray(int * arr, int * size)
{
	int size1 = 0;
	for (int i = 0; i < *size; i++)
	{
		for (int j = 1, k = 0; j <= *(arr + i); j++)
		{
			if (*(arr + i) % j == 0)
			{
				k++;
			}
			if (j == *(arr + i) &&
				k > 2)
			{
				size1++;
			}
			else if(j == *(arr + i) &&
				k <= 2)
			{
				*(arr + i) = 0;
			}
		}
	}
	int* arr1 = new int [size1];
	for (int i = 0, j = 0; i < *size; i++)
	{
		if (*(arr+i) != 0)
		{
			*(arr1 + j) = *(arr + i);
			j++;
		}
	}
	*size = size1;
	return arr1;
}

void printArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl;
}
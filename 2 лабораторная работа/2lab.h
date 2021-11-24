#include <iostream>
#include <stdio.h>
#include <chrono>
#include <thread>

using namespace std;


int BinarySearch(int array[], int find)
{

	int left = 0;
	int right = sizeof(int);
	int middle = 0; // middle of array. index
	bool answer = false;
	while (array[middle] != find)
	{
		if (array[middle] > find)
			right = middle;
		else
			left = middle;
		middle = (right + left) / 2;
		answer = true;
	}
	if (answer)
		cout << "Element has index = " << middle;
	else cout << "Incorrect data" << endl;
	return middle;
}

void QuickSort(int array[], int unconstnum)
{
	auto start = chrono::high_resolution_clock::now();
	int index_of_main = 0;
	bool answer = true;
	while (answer == true)
	{
		for (int i = index_of_main + 1; i < unconstnum; i++)
		{
			int remember = array[i];
			if (array[i] <= array[index_of_main])
			{
				for (int j = i; j < unconstnum - 1; j++)
				{
					array[j] = array[j + 1];
				}
				for (int j = unconstnum - 1; j > index_of_main; j--)
				{
					array[j] = array[j - 1];
				}
				array[index_of_main] = remember;
				index_of_main++;
			}
		}
		answer = false;
		for (int i = 0; i < unconstnum - 1; i++)
		{
			for (int j = i; j < unconstnum; j++)
			{
				if (array[i] > array[j])
				{
					answer = true;
					index_of_main = i;
				}
			}
		}
	}

	this_thread::get_id();
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << unconstnum << " elements " << duration.count() << " sec" << endl;

}

void InsertionSort(int array1[], int unconstnum)
{
	auto start = chrono::high_resolution_clock::now();
	int i = 0; int j;
	for (i = 1; i < unconstnum; i++)
		for (j = i; j > 0; j--) // пока j>0 и элемент j-1 > j, x-массив int
			if (array1[j - 1] > array1[j])
				swap(array1[j - 1], array1[j]);
			else break;
	this_thread::get_id();
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << unconstnum << " elements " << duration.count() << " sec" << endl;
}

void BogoSort(int array[], int n)
{
	bool answer = true;
	while (answer == true)
	{
		for (int i = 0; i < n; i++)
		{
			swap(array[i], array[(rand() % n)]);
		}
		answer = false;
		for (int i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				answer = true;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}

void CountingSort(char arrchar[], const int charconst)
{
	int* arrcount;
	arrcount = (int*)malloc(charconst * sizeof(int));
	int end = charconst - 1;
	int i; int j;
	for (i = 0; i < charconst; i++)
	{
		arrcount[i] = 1;
	}
	for (i = 0; i < charconst; i++)
	{
		for (j = i + 1; j < charconst; j++)
		{
			if (arrchar[i] == arrchar[j])
			{
				arrcount[i] ++;
				int k = j;
				while (k != charconst - 1)
				{
					arrchar[k] = arrchar[k + 1];
					k++;
				}
				arrchar[end] = 0;
				arrcount[end] = 0;
				end--;
			}
		}
	}
	int count = 0;
	for (i = 0; i < charconst; i++)
	{
		if (arrcount[i] != 0)
		{
			count++;
		}
	}
	for (i = 0; i <= end; i++)
		for (j = i; j > 0; j--) // пока j>0 и элемент j-1 > j, x-массив int
			if (arrchar[j - 1] > arrchar[j])
			{
				swap(arrchar[j - 1], arrchar[j]);
				swap(arrcount[j - 1], arrcount[j]);
			}
			else break;

	char* newarr;
	newarr = (char*)malloc(charconst * sizeof(char));
	j = 0;
	i = 0;
	while (j < count)
	{
		while (arrcount[j] != 0)
		{
			newarr[i] = arrchar[j];
			i++;
			arrcount[j]--;
		}
		j++;
	}
	for (i = 0; i < charconst; i++)
	{
		arrchar[i] = newarr[i];
	}
	for (int i = 0; i < charconst; i++)
	{
		cout << arrchar[i] << " ";
	}
	cout << endl;
}



int main()
{
	setlocale(LC_ALL, "Ru");
	int n = 6;
	int* a;  // указатель на массив
	// Выделение памяти
	a = (int*)malloc(n * sizeof(int));
	// Ввод элементов массива
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 30;
	}
	QuickSort(a, n);
	cout << "BinarySearch\n Array: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	int find;
	cout << endl;
	cout << "Enter element of array you want to get" << endl;
	cin >> find;
	BinarySearch(a, find);
	cout << endl;
	cout << "_____________" << endl << endl;
	const int num = 100000;
	int unconstnum = 10;
	for (int i = 0; i < unconstnum; i++)
	{
		a[i] = rand() % 30;
	}
	cout << "QuickSort\nArray: " << endl;
	for (int i = 0; i < unconstnum; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	QuickSort(a, unconstnum);
	for (int i = 0; i < unconstnum; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 30;
	}
	cout << endl;
	cout << "_____________" << endl << endl;
	cout << "InsertionSort\nArray: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	InsertionSort(a, unconstnum);
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}cout << endl;
	cout << "_____________" << endl << endl;
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 30;
	}
	cout << endl;

	cout << "BogoSort\nArray: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	BogoSort(a, n); cout << endl;
	cout << "_____________" << endl << endl;
	const int charconst = 6;
	char arraychar[charconst] = { 'c','1','d','b','c','a' };
	cout << endl;
	cout << "CountingSort\nArray: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arraychar[i] << " ";
	}
	cout << endl;
	CountingSort(arraychar, charconst);


	cout << endl;

	cout << "Running time of algorithms " << endl;

	cout << "QuickSort" << endl;


	unconstnum = 10;
	while (unconstnum != num)
	{
		// Выделение памяти
		a = (int*)malloc(unconstnum * sizeof(int));
		// Ввод элементов массива
		for (int i = 0; i < unconstnum; i++)
		{
			a[i] = rand() % 30;
		}
		QuickSort(a, unconstnum);
		unconstnum *= 10;
	}
	cout << "___________________" << endl;
	cout << endl << "InsertionSort" << endl;
	unconstnum = 10;
	while (unconstnum != num)
	{
		// Выделение памяти
		a = (int*)malloc(unconstnum * sizeof(int));
		// Ввод элементов массива
		for (int i = 0; i < unconstnum; i++)
		{
			a[i] = rand() % 30;
		}
		InsertionSort(a, unconstnum);
		unconstnum *= 10;
	}


	return 0;
}
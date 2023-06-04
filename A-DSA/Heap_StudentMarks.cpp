#include <iostream>
#include<climits>

using namespace std;

void MaxHeap_Logic(int a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2 * i;
	while (j <= n)
	{
		if (j < n && a[j + 1] > a[j])
			j = j + 1;
		if (temp > a[j])
			break;
		else if (temp <= a[j])
		{
			a[j / 2] = a[j];
			j = 2 * j;
		}
	} 
	a[j / 2] = temp;
	return;
}
void MinHeap_Logic(int a[], int i, int n)
{
	int j, temp;
	temp = a[i];
	j = 2 * i;
	while (j <= n)
	{
		if (j < n && a[j + 1] < a[j])
		{
			j = j + 1;
		}
			
		if (temp < a[j])
		{
			break;
		}
			
		else if (temp >= a[j])
		{
			a[j / 2] = a[j];
			j = 2 * j;
		}
	}
	a[j / 2] = temp;
	return;
}
void MaxHeap_Sort(int a[], int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		MaxHeap_Logic(a, 1, i - 1);
	}
}
void MInHeap_Sort(int a[], int n)
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;
		MinHeap_Logic(a, 1, i - 1);
	}
}
void Build_MaxHeap(int a[], int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
		MaxHeap_Logic(a, i, n);
}
void Build_MinHeap(int a[], int n)
{
	int i;
	for (i = n / 2; i >= 1; i--)
	{
		MinHeap_Logic(a, i, n);
	}
		
}
int main_heap()
{
	int array_size;
	cout << "\n\t\t\t~~~ WELCOME TO REPORT CARD DASHBOARD (2022-2023) ~~~\n";

	cout << "\n\t~~ENTER THE NUMBER OF STUDENTS IN SE- COMPUTER SCIENCE : ";
	cin >> array_size;

	array_size++;

	int arr[100];
	for (int i = 1; i < array_size; i++)
	{
		cout << "\n~ENTER THE MARKS OF THE STUDENT " << i << " : ";
		cin >> arr[i];
	}

	Build_MaxHeap(arr, array_size - 1);
	MaxHeap_Sort(arr, array_size - 1);

	int max, min;

	cout << "\n\t ~~LIST OF STUDENTS (LOWEST --> HIGHEST) :  ";

	for (int i = 1; i < array_size; i++)
	{
		cout << arr[i] << ", ";
	}
		
	min = arr[1];
	Build_MinHeap(arr, array_size - 1);
	MInHeap_Sort(arr, array_size - 1);

	cout << "\n\t ~~LIST OF STUDENTS (HIGHEST --> LOWEST) : ";

	max = arr[1];

	for (int i = 1; i < array_size; i++)
	{
		cout << arr[i] << ", ";
	}
	
	cout << "\n\n\t\t\t~~DUCK  OF THE CLASS SCORED ---> " << min << endl;
	cout << "\t\t\t~~TOPPER OF THE CLASS SCORED ---> " << max << endl;

	return 0;
}

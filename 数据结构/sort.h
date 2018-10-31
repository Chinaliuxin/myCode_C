
#ifndef __SORT_H__
#define __SORT_H__ 1

#include<assert.h>
#include <stdio.h>

int PartSort(int a[], int left, int right);
void QuickSort(int a[], int left, int right);

void swap(int* first, int *second)
{
	*first = *first^*second;
	*second = *first^*second;
	*first = *first^*second;
}

int PartSort(int a[], int left, int right)
{
	int key = a[right];
	int begin = left, end = right - 1;
	while (begin < end)
	{
		while (begin < end&&a[begin] <= key)
		{
			++begin;
		}
		while (begin < end&&a[end] >= key)
		{
			--end;
		}
		if (begin < end)
		{
			swap(&a[begin],& a[end]);
		}
	}
	if (a[begin] > a[right])
	{
		swap(&a[begin],& a[right]);
		return begin;
	}
	else{
		return right;
	}
}
void QuickSort(int a[], int left, int right)
{
	assert(a);
	if(left < right)
	{
		int flag = PartSort(a, left, right);
		QuickSort(a, left, flag - 1);
		QuickSort(a, flag + 1, right);
	}

}







#endif
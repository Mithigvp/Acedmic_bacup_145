#include <stdio.h>
#include <conio.h>

void main()
{
	int partition(int a[], int l, int r);
	void quick_sort(int a[], int l, int r);

	int arr[10], i, n;

	printf("\n enter the number of element in the array :: ");
	scanf("%d", &n);

	printf("\n enter the element in array ::\n ");
	for(i=0; i<n; i++)
	{
		printf(" arr[%d] = ", i);
		scanf("%d", &arr[i]);
	}

	quick_sort(arr, 0, n-1);

	printf("\n the sorted array is :: \n ");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	getch();
}

int partition(int a[], int l, int r)
{
	int left, right, temp, loc, flag;

	loc = left = l;
	right =  r;
	flag= 0;

	while(flag != 1)
	{
		while((a[loc] <=a [right]) && (loc != right))
		{
			right--; 
		}

		if( loc== right)
		{
			flag = 1;
		}
		else if(a[loc] > a[right])
		{
			temp = a[loc];
			a[loc] = a[right];
			a[right] = temp;
			loc = right;
		}
		if(flag != 1)
		{
			while((a[loc] >=a [left]) && (loc != left))
			{
				left++; 
			}

			if( loc == left)
			{
				flag = 1;
			}
			else if(a[loc] < a[left])
			{
				temp = a[loc];
				a[loc] = a[left];
				a[left] = temp;
				loc = left;
			}
		}
	}
	return loc;
} 
void quick_sort(int a[], int l, int r)
{
	int loc;
	if(l < r)
	{
		loc = partition(a,l,r);
		quick_sort(a, l, loc-1);
		quick_sort(a, loc+1, r);
	}
}

#include <stdio.h>
#include <conio.h>

void merge(int a[], int l, int m, int r);
void merge_sort(int a[], int l, int r);

void main()
{
	int arr[10], i, n;

	printf("\n enter the number of element in the array :: ");
	scanf("%d", &n);

	printf("\n enter the element in array ::\n ");
	for(i=0; i<n; i++)
	{
		printf(" arr[%d] = ", i);
		scanf("%d", &arr[i]);
	}

	merge_sort(arr, 0, n-1);

	printf("\n the sorted array is :: \n ");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
	getch();
}

void merge(int a[], int l, int m, int r)
{
	int i=l, j=m+1, in=l, temp[10], k;
	
	while((i<=m) && (j<=r))
	{
		if(a[i] < a[j])
		{
			temp[in] = a[i];
			i++;
		}
		else
		{
			temp[in] = a[j];
			j++;	
		}
		in++;
	} 
	
	if(i>m)
	{
		while(j<=r)
		{
			temp[in]= a[j];
			j++;
			in++;
		}
	}
	else
	{
		while(i<=m)
		{
			temp[in] = a[i];
			i++;
			in++;
		}	
	}
	

	for(k=l; k<in; k++)
	{
		a[k] = temp[k];
	}
} 
void merge_sort(int a[], int l, int r)
{
	int m;
	if(l < r)
	{
		m = (l + r)/2;
		merge_sort(a, l, m);
		merge_sort(a, m+1, r);
		merge(a, l, m, r); 
	}
}

#include<stdio.h>

void swap(int *a,int *b){
	int temp = *a;
		*a = *b;
		*b = temp;
}

void heapify(int a[] , i , n){
	int max = i;
	int left = (2 * i)+1;
	int right = (2 * i) + 2;
	
	if(left < n && a[left] > a[max]){
		max = left;
	}
	
	if(right < n && a[right] > a[max]){
		max = right;
	}
	
	if(max != 1){
		swap(&a[max], &a[i]);
		heapify(a, i , max);
	}
}

void heapsort(int a[] , int n){
	int i;
	for(i = n/2-1; i >= 0; i-- ){
		heapify(a , i, n);
	}
	for(i = n-1; i >= 0; i--){
		swap(a[0], a[i]);
		
		heapify(a , n, 0);
	}

}

void main(){


}
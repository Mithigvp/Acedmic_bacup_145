#include <stdio.h>

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void MaxHeapify(int a[],int n, int i){
    int largest = i;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;

    if (l < n && a[l] > a[largest]){
        largest = l;
    }

    if (r < n && a[r] > a[largest]){
        largest = r;
    }

    if (largest != i){
        swap(&a[largest],&a[i]);
        MaxHeapify(a,n,largest);
    }
}

void heapsort(int a[],int n){
    int i;
    for( i = n/2 - 1; i >= 0; i--){
        MaxHeapify(a,n,i);
    }
    for( i = n - 1; i > 0; i--){
        swap(&a[0],&a[i]);
        MaxHeapify(a,i,0);
    }
}

void main(){
    int n,i;
    printf("Enter No. of The Elements : ");
    scanf("%d",&n);
    int a[n];
    for (i = 0; i < n; i++){
        printf("Enter %d Element value : ",i+1);
        scanf("%d",&a[i]);
    }

    heapsort(a,n);

    printf("\nHeap Sort Sorted Array : ");
    for (int i = 0; i < n; i++){
        printf("%d ",a[i]);
    }
}
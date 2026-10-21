#include<stdio.h>
#include<conio.h>

int findLargest(int data[], int n);
void radixSort(int data[], int n);

void main()
{
    int data[10], i, n;

    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);

    printf("\nEnter the elements of the array ");
    for(i=0; i<n; i++)
    {
        printf("\n data[%d] = ", i);
        scanf("%d", &data[i]);
    }

    radixSort(data, n);

    printf("\nThe sorted array is : \n");

    for(i=0; i<n; i++)
        printf("%d\t", data[i]);

    getch();
}

int findLargest(int data[], int n)
{
    int maximum = data[0], i;

    for(i=1; i<n; i++)
    {
        if(data[i] > maximum)
            maximum = data[i];
    }

    return maximum;
}

void radixSort(int data[], int n)
{
    int digitBucket[10][10], countBucket[10];
    int i, j, index, remainder;
    int noOfPasses = 0, divisor = 1;
    int maximum, pass,value;

    maximum = findLargest(data, n);

    while(maximum > 0)
    {
        noOfPasses++;
        maximum /= 10;
    }

    for(pass=0; pass<noOfPasses; pass++)
    {
        for(i=0; i<10; i++)
            countBucket[i] = 0;

        for(i=0; i<n; i++)
        {
            remainder = (data[i] / divisor) % 10;

            digitBucket[remainder][countBucket[remainder]] = data[i];

            countBucket[remainder]++;
        }

        index = 0;

        for(value=0; value<10; value++)
        {
            for(j=0; j<countBucket[value]; j++)
            {
                data[index] = digitBucket[value][j];
                index++;
            }
        }

        divisor *= 10;
    }
}
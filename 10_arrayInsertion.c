#include<stdio.h>

void display(int arr[], int uSize){
    int i;
    printf("Displaying the array ..\n");
    for (i = 0; i < uSize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n"); 
}

int indexInsertion(int arr[],int element, int size, int index,int capacity){
    printf("Inserting element %d at index no %d in the array of capacity %d\n",element, index, capacity);
    if(size >= capacity){
        return -1;
    }
    int i;
    for ( i = size; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 0;
}

int main()
{
    // int arr[100] = {7,12,24,36,88};
    // int element, size = 5;
    // display(arr,size);
    // indexInsertion(arr,54,5,3,100);
    // size += 1;
    // display(arr, size);
    // return 0;


    int arr[50];
    int uSize;
    printf("Enter your used size = ", uSize);
    scanf("%d",&uSize);
    printf("Enter the array elements ...\n");
    int i;
    for( i = 0; i < uSize; i++){
        printf("Element %d : ",i);
        scanf("%d",&arr[i]);
    }
    display(arr, uSize);
    indexInsertion(arr,54,5,3,100);
    uSize += 1;
    display(arr, uSize);
    return 0;
}

#include<stdio.h>

int binarySearch(int arr[],int size, int element){
   int low, mid, high;
   low = 0;
   high = size -1;
   while (low <= high)
   {
        mid = (low+high)/2;
        if (element == arr[mid])
        {
            return mid;
        }
        if (element > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }     
   }
    return -1;
}

int main()
{
    int arr[] = {2,5,7,9,12,25};
    int size = sizeof(arr)/sizeof(int);
    int element = 125;
    int searchIndex = binarySearch(arr, size, element);
    printf("%d element found at index %d\n", element, searchIndex);
    return 0;
}
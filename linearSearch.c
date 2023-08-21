#include<stdio.h>
void linearSearch(int arr[],int size,int element){
    for (int i = 0; i < size-1; i++)
    {
        if(arr[i] == element)
        printf("%d element found at index %d \n", element, i);
    }
    if (!linearSearch)
    {
        printf("Element not found");
    }
    // return -1;
}
int main()
{
    int arr[100] = {10,12,23,14,25,6};
    int element = 6;
    int size = (sizeof(arr))/sizeof(int);
    linearSearch(arr,size,element);
    // int searchInd = linearSearch(arr,size,element);
    // printf("The %d element found at index %d\n", element, searchInd);
    return 0;
}
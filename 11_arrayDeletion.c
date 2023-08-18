#include<stdio.h>
void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void arrayDeletion(int arr[], int size, int index){
    if(index <0 || index > size+1){
        printf("Deletion Invalid");
    }
    for(int i = index; i < size-1;i++){
        arr[i] = arr[i+1];
    }
}

int main()
{
    int arr[100] = {7,15,26,89,99};
    int size = 5, capacity = 100, index = 0;
    display(arr,size);
    arrayDeletion(arr,size,index);
    size -= 1;
    display(arr,size);
    return 0;
}
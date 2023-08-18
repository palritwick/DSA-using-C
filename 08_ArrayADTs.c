#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int*)malloc(a->used_size*sizeof(int));
};

void show(struct myArray *a){
    for (int i = 0; i < a->used_size; i++)
    {      
        printf("%d ", (a->ptr)[i]);
    }
    printf("\n");
}
void setVal(struct myArray *a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter Element %d : ",i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main()
{
    struct myArray marks;
    createArray(&marks,10,5);
    printf("Setting the value...\n");
    setVal(&marks);
    printf("Displaying the value in the stack array...\n");
    show(&marks);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct value{
    int data;
    int counter;
}value;

void swap(value* x, value* y){
    value temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

value* selection_sort(value* arr, int n)
{
    value* copy = malloc(n*sizeof(value));
    for(int i =0; i<n; i++){
        copy[i] = arr[i];
    }

    int min_idx;
    for(int i=0; i<n; i++){
        min_idx=i;
        for(int j=i+1; j<n; j++){
            if(copy[min_idx].data > copy[j].data){
                min_idx = j;
            }
        }
        copy[min_idx].counter++;
        copy[i].counter++;
        swap(&copy[min_idx], &copy[i]);
    }
    return copy;
}

value* bubble_sort(value* arr, int n){
    value* copy = malloc(n*sizeof(value));
    for(int i =0; i<n; i++){
        copy[i] = arr[i];
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(copy[j].data>copy[j+1].data){
                copy[j].counter++;
                copy[j+1].counter++;
                swap(&copy[j], &copy[j+1]);
            }
        }
    }
    return copy;
}



int main(void)
{
    value arr1[9];
    value arr2[9];

    arr1[0].data = 97;
    arr1[1].data = 16;
    arr1[2].data = 45;
    arr1[3].data = 63;
    arr1[4].data = 13;
    arr1[5].data = 22;
    arr1[6].data = 7;
    arr1[7].data = 58;
    arr1[8].data = 72;

    arr2[0].data = 90;
    arr2[1].data = 80;
    arr2[2].data = 70;
    arr2[3].data = 60;
    arr2[4].data = 50;
    arr2[5].data = 40;
    arr2[6].data = 30;
    arr2[7].data = 20;
    arr2[8].data = 10;

    for(int i=0; i<9; i++){
        arr1[i].counter = 0;
        arr2[i].counter = 0;
    }

    value* bsort1 = bubble_sort(arr1, 9);
    value* bsort2 = bubble_sort(arr2, 9);

    value* ssort1 = selection_sort(arr1, 9);
    value* ssort2 = selection_sort(arr2, 9);

    int total = 0;
    
    printf("array1 Bubble Sort:\n");
    for(int i=0; i<9; i++){
        total += bsort1[i].counter;
        printf("%d: %d\n", bsort1[i].data, bsort1[i].counter);
    }
    printf("Total: %d\n", total/2);
    total = 0;
    free(bsort1);

    printf("array2 Bubble Sort:\n");
    for(int i=0; i<9; i++){
        total += bsort2[i].counter;
        printf("%d: %d\n", bsort2[i].data, bsort2[i].counter);
    }
    printf("Total: %d\n", total/2);
    total = 0;
    free(bsort2);

    printf("array1 Selection Sort:\n");
    for(int i=0; i<9; i++){
        total += ssort1[i].counter;
        printf("%d: %d\n", ssort1[i].data, ssort1[i].counter);
    }
    printf("Total: %d\n", total/2);
    total = 0;
    free(ssort1);

    printf("array2 Selection Sort:\n");
    for(int i=0; i<9; i++){
        total += ssort2[i].counter;
        printf("%d: %d\n", ssort2[i].data, ssort2[i].counter);
    }
    printf("Total: %d\n", total/2);
    free(ssort2);
    


    return 0;
}
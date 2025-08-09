#include <stdio.h>

void bubble_sort(int*, int);

int main(){
    int nums[] = {56, 43, 75, 22, 1, 9, 45};
    int size = sizeof(nums) / sizeof(*nums);

    bubble_sort(nums, size);

    printf("The sorted array is:-\n");
    for (int i = 0; i < size; i++){
        printf("%d ", *(nums + i));
    }
    printf("\n");

    return 0;
}

void bubble_sort(int *nums, int size){
    for (int i = 0; i < size - 1; i++){
        for(int *p = nums; p < nums + size - 1 - i; p++){
            if (*(p + 1) < *p){
                int temp = *(p + 1);
                *(p + 1) = *p;
                *p = temp;
            }
        }
    }
}
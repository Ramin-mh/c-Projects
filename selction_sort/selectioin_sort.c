#include <stdio.h>

void selection_sort(int *nums, int size);

int main(){
    int nums[] = {12, 45, 30, 2, 58, 55, 4, 2, 90};
    int size = sizeof(nums) / sizeof(*nums);  

    selection_sort(nums, size);

    printf("The sorted array is:-\n");
    for (int i = 0; i < size; i++){
        printf("%d ", *(nums + i));
    }
    printf("\n");
}
    
void selection_sort(int *nums, int size){
    for (int i = 0; i < size; i++){
        int *min_ptr = nums + i;

        for (int *p = nums + i + 1; p < nums + size; p++){
            if (*p < *min_ptr){
                min_ptr = p;
            }
        }

        if (min_ptr != nums + i){
            int temp = *(nums + i);
            *(nums + i) = *min_ptr;
            *min_ptr = temp;
        }
    }
}
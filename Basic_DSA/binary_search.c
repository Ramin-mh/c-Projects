#include <stdio.h>

int binary_search(int*, int, int);

int main(){
    int nums[] = {12, 24, 25, 54, 56, 70, 99};
    int n = sizeof(nums) / sizeof(*nums);
    int target = 25;
    
    int index = binary_search(nums, n, target);    
    printf("%d\n", index);

    return 0;
}

int binary_search(int *nums, int n, int target){
    int f = 0;
    int l = n - 1;

    while (f <= l){
        int mid = (f + l) / 2;
        if (*(nums + mid) == target){
            return mid;
        } 
        else if (*(nums + mid) < target){
            f = mid + 1;
        }
        else {
            l = mid - 1;
        }
        
    }

    return -1;
}
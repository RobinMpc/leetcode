#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target) {
    int min = nums[0];
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] < min)
            min = nums[i];
    }
    int max = target - min;
    int len = max - min + 1;   
    int *table = (int*)malloc(len*sizeof(int));
    int *indice = (int*)malloc(2*sizeof(int));
    for (i = 0; i < len; i++) {
        table[i] = -1;         
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i]-min < len) {
            if (table[target-nums[i]-min] != -1) {        
                indice[0] = table[target-nums[i] - min];
                indice[1] = i;
                return indice;
            }
            table[nums[i]-min] = i;
        }
    }
    free(table);
    return indice;

}

int main()
{
    int nums[4] = {5, 2, 3, 1};
    int *result = twoSum(nums, 4, 8);
    printf("%d    %d", *result, *(result+1));
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *returnArray = malloc(2*sizeof(int));
    for (int i = 0; i < numsSize-1; i++) {
        int currentNum = *(nums+i);
        int lookingFor = target-currentNum;
        for (int j = i+1; j < numsSize; j++) {
            if (lookingFor == *(nums+j)) {
                *returnArray = i;
                *(returnArray+1) = j;
                return returnArray;
            }
        }
    }
    return NULL;
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int *result = NULL;
    
    //分别返回值需要的空间
    result = malloc(sizeof(int) *2);
    if (result == NULL) {
        returnSize = 0;
        return result;
    }
    memset(result, 0, sizeof(int) *2);
    //暴力法进行计算，这里j其实可以从i+1开始，因为前面
    //已经比较过了。
    for (i=0; i<numsSize; i++) {
        for (j=0; j<numsSize; j++) {
            if (i != j && (nums[i] + nums[j] == target)) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    
    returnSize = 0;
    return result;
}

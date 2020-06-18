int compare(const void *arg1, const void *arg2){
    return (*(int *)arg1 - *(int *)arg2);
}

int findLHS(int* nums, int numsSize){
    if(numsSize == 0) return 0;
        
    qsort(nums, numsSize, sizeof(int), compare);
    int result = 0, count = 1, prev = 0;
    for(int i = 1; i < numsSize; i++) {
        if(nums[i] == nums[i-1]) count ++;
        else {
            if(prev && prev + count > result) 
                result = prev + count;
            prev = (nums[i] - nums[i-1] == 1) ? count : 0;
            count = 1;
        }
    }
        
    return fmax(result, prev ? count + prev : 0);
}

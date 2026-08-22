int maxSubArray(int* nums, int numsSize) {

    int current = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < numsSize; i++) {

        if (current + nums[i] < nums[i]) {
            current = nums[i];
        }
        else {
            current = current + nums[i];
        }

        if (current > maxSum) {
            maxSum = current;
        }
    }

    return maxSum;
}

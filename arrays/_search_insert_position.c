int searchInsert(int* nums, int numsSize, int target) {
    int l=0,flagh=0,k;
    int h=numsSize-1;
    while(l<=h){
        int m=(l+h)/2;
        if(nums[m]>=target){
                flagh=1;
                return m;
        }
        else if(nums[m]>target){
            h=m-1;
        }
        else if(nums[m]<target){
            l=m+1;
        }
    }
    if(flagh==0){
        if(target>nums[numsSize-1]){
            return k=numsSize;
        }
    }
    return k;
}

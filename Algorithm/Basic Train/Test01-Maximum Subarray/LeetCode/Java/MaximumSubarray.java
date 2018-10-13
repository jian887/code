class Solution {
    public int maxSubArray(int[] nums) {
    if (nums.length==0) {
        return -1;
    }
    
    int max = nums[0];
    int lastsum = nums[0];
    for (int i = 1; i<nums.length; i++) {
        if (lastsum + nums[i] < nums[i]) {
            lastsum = nums[i];
        } else {
            lastsum += nums[i];
        }
        max = Math.max(max, lastsum);
    }
    return max;
}
}
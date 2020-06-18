class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        sort(nums.begin(), nums.end());
        int result = 0, count = 1, prev = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) count ++;
            else {
                if(prev && prev + count > result) 
                    result = prev + count;
                prev = (nums[i] - nums[i-1] == 1) ? count : 0;
                count = 1;
            }
        }
        
        return max(result, prev ? count + prev : 0);
    }
};

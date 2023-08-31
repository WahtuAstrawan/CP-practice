class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return false;
        }

        vector<int> leftMin(n);
        vector<int> rightMax(n);

        leftMin[0] = nums[0];
        for(int i = 1; i < n; i++){
            leftMin[i] = min(leftMin[i - 1], nums[i]);
        }

        rightMax[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        for(int i = 1; i < n - 1; i++){
            int mid = nums[i];
            if(leftMin[i - 1] < mid && mid < rightMax[i + 1]){
                return true;
            }
        }
        return false;
    }
};

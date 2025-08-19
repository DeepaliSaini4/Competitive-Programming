class Solution {
public:
   
    long long zeroFilledSubarray(vector<int>& nums) {
        long long  tail = 0;
        long long  head = -1;
        long long ans = 0;
        long long n = nums.size();
        while(tail<n){
            while(head+1<n && nums[head+1]==0){
                head++;
            }
            ans+=(head-tail+1);
            if(head<tail){
                tail++;
                head = tail-1;
            }else{
                tail++;
            }
        }
        return ans;
    }
};

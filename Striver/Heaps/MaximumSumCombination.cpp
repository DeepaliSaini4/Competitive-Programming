/*
Given two integer arrays nums1 and nums2 and an integer k, return the maximum k valid sum combinations from all possible sum combinations using the elements of
nums1 and nums2.
A valid sum combination is made by adding one element from nums1 and one element from nums2. Return the answer in non-increasing order.
*/
class Solution {
public:
  vector<int> maxSumCombinations(vector<int> &nums1, vector<int> &nums2, int k) {
        sort(nums1.begin(),nums1.end(),greater<int>());
        sort(nums2.begin(),nums2.end(),greater<int>());
        priority_queue<tuple<int,int,int>>pq;
        pq.push(nums1[0]+nums2[0],0,0);
        set<pair<int,int>>s;
        s.insert({0,0});//the indexes that i have taken into consideration 
        vector<int>result;
        while(!pq.empty() && k--){
            auto[sum,i,j] = pq.top();
            pq.pop();
            result.push_back(sum);
            //trying a new sum combo by moving next element in nums1
            if(i+1<nums1.size() && !s.count({i+1,j})){
                pq.push({nums1[i+1]+nums2[j],i+1,j});
                s.insert({i+1,j});
            }
            if(j+1<nums2.size() && !s.count({i,j+1})){
                pq.push({nums1[i]+nums2[j+1],i,j+1});
                s.insert({i,j+1});
            }
        }
        return result;
  }
};

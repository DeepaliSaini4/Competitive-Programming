class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>qu;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->qu = priority_queue<int,vector<int>,greater<int>>();
        this->k=k;
        for(auto it:nums){
            qu.push(it);
        }
        while(qu.size()>k){
            qu.pop();
        }
    }
    
    int add(int val) {
        qu.push(val);
        if(qu.size()>k){
            qu.pop();
        }
        return qu.top();
    }
};

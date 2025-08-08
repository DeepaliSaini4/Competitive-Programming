class MedianFinder {
public:
    priority_queue<int>pq1;
    priority_queue<int,vector<int>,greater<int>>pq2;

    MedianFinder() {
        pq1 = priority_queue<int>();
        pq2 = priority_queue<int,vector<int>,greater<int>>();
    }
    
    void addNum(int num) {
        if(pq1.size()==0){
            pq1.push(num);
        }else{
            if(pq1.size()==pq2.size()){
                if(num>pq2.top()){
                    pq1.push(pq2.top());
                    pq2.pop();
                    pq2.push(num);
                }else{
                    pq1.push(num);
                }
            }else{
                if(num>=pq1.top()){
                    pq2.push(num);
                }else{
                    pq2.push(pq1.top());
                    pq1.pop();
                    pq1.push(num);
                }
            }
        }
    }

    double findMedian() {
        if(pq1.size()==pq2.size()){
            return (double)(pq1.top()+pq2.top())/2;
        }
        return double(pq1.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

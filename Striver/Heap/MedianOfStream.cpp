class MedianFinder {
public:
    priority_queue<int> p1;
    priority_queue<int, vector<int>, greater<int>> p2;
    MedianFinder() {
        this->p1 = priority_queue<int>();
        this->p2 = priority_queue<int, vector<int>, greater<int>>();
    }

    void addNum(int num) {
        if (p1.size() == 0) {
            p1.push(num);
        } else {
            if (p1.size() == p2.size()) {
                if(num>p2.top()){
                    p1.push(p2.top());
                    p2.pop();
                    p2.push(num);
                }else{
                    p1.push(num);
                }
            } else {
                if (num >= p1.top()) {
                    p2.push(num);
                } else {
                    p2.push(p1.top());
                    p1.pop();
                    p1.push(num);
                }
            }
        }
    }

    double findMedian() {
        if ((p1.size() + p2.size()) % 2 != 0) {
            return (double)p1.top();
        }

        return (double)(p1.top() + p2.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

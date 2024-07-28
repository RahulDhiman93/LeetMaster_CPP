class MedianFinder {
    priority_queue<int, vector<int>, less<int>> sh;
    priority_queue<int, vector<int>, greater<int>> lh;
public:
    MedianFinder() {
        sh={};
        lh={};
    }
    
    void addNum(int num) {
        sh.push(num);
        
        if(!sh.empty() && !lh.empty() && sh.top() > lh.top()) {
            lh.push(sh.top());
            sh.pop();
        }

        if(sh.size() > lh.size()+1) {
            lh.push(sh.top());
            sh.pop();
        }

        if(lh.size() > sh.size()+1) {
            sh.push(lh.top());
            lh.pop();
        }
    }
    
    double findMedian() {
        if (sh.size() > lh.size()) {
            return (double) sh.top();
        } else if (lh.size() > sh.size()) {
            return (double) lh.top();
        }

        return (double) (sh.top() + lh.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
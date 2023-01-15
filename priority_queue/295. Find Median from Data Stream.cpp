//===類似題===
296. Best Meeting Point
480. Sliding Window Median
1825. Finding MK Average
2102. Sequentially Ordinal Rank Tracker

//===思路===
(*)將數列分成兩部分,較大數列是一個partition, 另外一個partition是較小的數
(*)用兩個priority_queue來區這兩個partition.

當small_q的size大於 large_q的size, 代表全部是奇數個, 所以取small的top即可
當small_q的size等於large_1的size, 代表全部是偶數個, 所以取(small.top()-large.top())/; 
large.top()是加上負號的數值,所以top的數, 是絕對值較小的數
//======
class MedianFinder {
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        
        if(small.size()<large.size()){
            small.push(-large.top());
            large.pop();
        }
    }

    double findMedian() {
        return small.size()>large.size()? small.top(): (double)(small.top()-large.top())/2;
    }
private:
    priority_queue<int> small, large;
};


//===fail: time limit exceed ====
class MedianFinder {
public:
    MedianFinder() {
    }
    void addNum(int num) {
        vector<int>::iterator it;
        it=lower_bound(nums.begin(),nums.end(),num);    
        nums.insert(nums.begin()+(it-nums.begin()),num);
    }
    double findMedian() {
        if(nums.size()%2){
            return (double)nums[(nums.size()-1)/2];
        }else{
             int i=(nums.size()-1)/2, j=i+1;
             return (double)(nums[i]+nums[j])/2;
        }
    }
private:
    vector<int> nums;   
};

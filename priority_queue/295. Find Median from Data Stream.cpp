//===類似題===

//===思路===

//======








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

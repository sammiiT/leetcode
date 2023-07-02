//===類似題===
35. Search Insert Position
2055. Plates Between Candles
2089. Find Target Indices After Sorting Array
//===思路===
(*)lower_bound和upper_bound求解
//======
vector<int> helper0(vector<int>& nums, int target) {
    int first=0, last=0;
    vector<int> res(2,-1);
    if(!nums.size()) return res;
    
    first = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    if(first>=nums.size() || nums[first]!=target) return vector<int>(2,-1);
     //[2,2] 3

    last = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
    if(nums[last-1]==target) {
        res[0]=first;
        res[1]=last-1;
    }
//沒有此else描述也正確        
    else{
        res[0]=res[1]=first;
    }
   return res;   
}

//===思路===
(*)binary search求解
//======
    int binarySearch(vector<int>& nums, int target, int l, int r){
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]<target){
                l=m+1;
            }else if(nums[m]>target){
                r=m-1;
            }else{//nums[m]==taret
                return m;
            }
        }
        return -1;
    }

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res({-1,-1});
    int id;
    
    id = binarySearch(nums, target, 0, nums.size()-1);//先找有沒有target存在
    if(id==-1) return res;
    
    //find left,如果存在,以此點為基準, 找左半邊
    int tmp = id;
    while(tmp>=0){
        res[0]=tmp;
        tmp=binarySearch(nums, target, 0, tmp-1);
    }
    
    //find right//如果target有存在, 以此點為基準, 找右半邊
    tmp = id;
    while(tmp>=0){
        res[1]=tmp;
        tmp = binarySearch(nums,target,tmp+1,nums.size()-1);
    }
    return res;
}

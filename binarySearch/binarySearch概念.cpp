(*)找不到,回傳-1
int binarySearch(vector<int>& nums, int target){
    int l = 0;
    int r = nums.size()-1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(nums[m]<target){
            l = m+1;
        }else if(nums[m]>target){
            r = m-1;
        }else{
            return m;
        }
    }
    return -l;//找不到,回傳-1
}

(*)若找不到,要回傳一個位置
int binarySearch(vector<int>& nums, int target){
    int l = 0;
    int r = nums.size()-1;
    int m;
    while(l<=r){
        m = l+(r-l)/2;
        if(nums[m]<target){
            l = m+1;
        }else if(nums[m]>target){
            r = m-1;
        }else{
            return m;
        }
    }
    return m;//找不到,回傳-1
}

//==============================================================
int binarySearch(vector<int>& nums, int target){//用在最靠近的element
    int l = 0;  
    int r = nums.size()-1;
    int m = 0;
    
// while(l<=r) 無法跳出迴圈    
    while(l<r){//最後l超過r, 不能回傳l或r
        m = l + (r-l)/2;
//        if(nums[m]<=target){//等於的時候, l 不能(m+1)
        if(nums[m]<target){
            l = m+1;
//            cout<<"l="<<l<<" r="<<r<<" m="<<m<<endl;
        }else{//nums[m]>=target=> r移動可以不用減1, 因為個數的會造成m移動
            r = m;//等於放在nums[m]> target區間
//            cout<<"l "<<l<<" r="<<r<<" m="<<m<<endl;
        }
    }
    return r;//return r就是靠近 right的那一個index
}

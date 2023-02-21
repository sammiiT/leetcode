//===類似題===
1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
2365. Task Scheduler II

//===思路===
(*)如果依序每一個1的位址都跟相鄰最近的1有 k的間隔, 則1和1之間倆倆絕對有k的間隔
1.遍歷數列一次
2.初始第一個1的boundary設定為條件 1<= nums.length <= 10^5 的範圍;並取負值
2.2則取到第一個1絕對會滿足條件
//====
bool helper0(vector<int>& nums, int k){
    int j = (nums.size()+1)*(-1);
    for(int i=0; i<nums.size(); i++){
        if(nums[i]==1){
            if((i-j-1)>=k) j=i;
            else return false;
        }
    }
    return true;
}
bool kLengthApart(vector<int>& nums, int k) {
    return helper0(nums,k);
}

//===思路2===
(*)宣告一變數count,計算0的數目
1.計算第一個1出現的index
2.求出第一個1出現的位址之後, 先跳到下一個位置(沒有此動作,會運算錯誤)
-- i=i+1;    
3.開始遍歷剩下的的元素,如果遇到0,將count++
遇到1,判斷count是否滿足題意,若滿足則重新reset count
若不滿題意,則直接回傳false;
//===
bool helper1(vector<int>& nums, int k) {
    int count =0;
    int i,j;
    for(i=0;i<nums.size();i++)
        if(nums[i]) break;
    if(i==nums.size()) return true;

    i+=1;//跳到下一個,不從第一個1算起
    for(;i<nums.size();i++){
        if(nums[i]==0) count++;
        else{
           if(count<k) return false;
           count=0;
        }
    }
    return true;
}    


    

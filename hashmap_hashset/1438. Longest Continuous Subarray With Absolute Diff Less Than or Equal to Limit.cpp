//===類似題===
1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows
2294. Partition Array Such That Maximum Difference Is K
2444. Count Subarrays With Fixed Bounds

//===思路===
(*)用到multiset; //因為multiset可以幫忙作排列??, vector不會作排列
- 在呼叫其對應的method時, 才會作排列動作;

(*)用sliding_window方法
1.遍歷陣列,並將元素加入multiset中
2.若multiset的最後一個數值不滿足題目條件,則sliding_window後idx往前移一個step
從multiset中刪除step所移除的元素
最後將長度記錄在res中; res = max(res, window_right-window-left+1);


(*)
rbegin(st)等效於st.rbegin()
begin(st)等效於st.begin()

  //========
int helper0(vector<int>& nums, int limit){
    multiset<int> st;
    int j = 0;//window_left
    int res = 0;
    for(int i=0; i<nums.size(); i++){//i=window_right
        st.insert(nums[i]);//每插入一個,就跟window內所有的element做比較

        while(*rbegin(st)-*begin(st) > limit){//跟window內所有的element做比較
//        while(*(st.rbegin())-*(st.begin()) > limit){
            st.erase(st.equal_range(nums[j]).first);//每次erase完之後, begin()數值都不一樣,但rbegin()
            j++;
        }
        res = max(res,i-j+1);
    }
    return res;
}

int longestSubarray(vector<int>& nums, int limit) {
    return helper0(nums,limit);     
}

//====failed ====
輸入:  
nums = [1,5,6,7,8,10,6,5,6]
limit = 4

-當 6,7,8,10,6,5由以下算法,會發生錯誤, 因為以window_left做基準,所以(6,5)滿足,但(10,5)不滿足
-錯誤點在, 每插入一個,並沒有跟其他的點做比較,只跟window left做比較
int helper0(vector<int>& nums, int limit){
    int j = 0;//window_left
    int i = 0;//window_right
    int res = 0;
    for(i=0; i<nums.size(); i++){
        if(abs(nums[j]-nums[i]) <= limit) continue;//每插入一個,並沒有跟其他的點做比較,只跟window left做比較
        res = max(res, i-j);
        do{
            j++;
        }while(abs(nums[j]-nums[i])>limit);//前面(window_left)減後面(wiindow_right)
    }
    res = max(res,i-j);
    return res;
}

//---修正-----
修改過後滿足條件,但time limit exceed
{1,5,6,7,8,10,6,5,6}
int helper1(vector<int>& nums, int limit){
    int j = 0;//window_left
    int i = 0;//window_right
    int res = 0;
    for(int i=0;i<nums.size();i++){
        int p = j;
        while(p<i){
            if(abs(nums[i]-nums[p])<=limit){
                p++; continue;
            }else{
                p++;
                j=p;
            }
        }
        res = max(res,i-j+1);
    }
    return res;
}




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

(*)程式邏輯說明:
- 此multi-set 有 3,5,6,7,8,11
-其中3有二個, 5有三個, 6有三個, 7有一個,8有四個, 11有六個; 在multi-set中的所有數值表示在array中的所有數值 
+-----------------------+
|  5     8  8      6    |
| 5  5    8  8    6  6  |
|                       | 
|  3 3      11  11      |
|         11  11  11    |
|   7         11        |   
+-----------------------+

-當multi-set中的最大,最小差值 > limit; 不滿足 abs<=limt; 表示要從window_left開始移動
 (*rbegin(st)-*begin(st) > limit)
其中 *rbgein(st)為最大值, *begin(st)為最小值

-window_left移動到 abs<=limit; 其中nums[window_left]為multi-set中的一個element
-將multi-set中的nums[window_left]移除可表示為;
--st.erase(st.equal_range(nums[window_left]).first)
--其中 st.equal_range(nums[window_left]).first 代表 多數中的第一個數值
--如 5,5,5 中的第一個

-每移除一個, window_left就往右移一個單位; window_left++ 

-sliding loop計算後, 在multi-set中的數,最小的一定會滿足 abs<=limit

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




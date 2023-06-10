//===類似題====
155. Min Stack
1601. Maximum Number of Achievable Transfer Requests
1235. Maximum Profit in Job Scheduling
1996. The Number of Weak Characters in the Game

//===思路===
1.最小值會發生在非遞增的區間;如
[4,5,6,7,0,1,2] => 發生在(m+1)~n ;不包含m 
[5,6,7,0,1,2,4] => 發生在0~m ;包含m

2.一定發生在非遞增的區間, 所以先找非遞增區間; 所以在判斷上先執行
if(nums[m]>nums[r])//非遞增區間, l每次m+1,往右邊慢慢逼近最小值
    l = m+1;

3.走到最後,還是會到遞增區間
在遞增區間, r要往左邊逼近,最後逼近到m

4.
[0,1,2,2,2]
發生等於的情況, r--
r最後會減到m的位址

//======
int helper0(vector<int>& nums){
    int l=0, r = nums.size()-1;
    if(nums[l]>=nums[r]){
        while(l<r){
            int m = l+(r-l)/2;
            if(nums[m]>nums[r]){
                l = m+1;        
            }else if(nums[m]==nums[r]){//不能將這一條移除,移除這一條會出錯
                --r;                   //[3,3,1,3]=>r會直接跳到index_1的位址, 最小值就跳過了
            }else{//nums[m]<nums[r]
                r = m;//r=m 有可能是最小的那一個, 所以不能用r = m-1跳過
                      //且包含m的情況下才會有非遞增區間 
            }        
        }
        return nums[r];
    }
    return nums[0];
}
    
int findMin(vector<int>& nums) {
    //return helper_1(nums);
    return helper0(nums);
}
//====fail====
int helper1(vector<int>& nums){
    int l=0, r = nums.size()-1;
    if(nums[l]>=nums[r]){
        while(l<r){
            int m = l+(r-l)/2;
            if(nums[m]>nums[r]){
                l = m+1;        
            }
/*            else if(nums[m]==nums[r]){//拿掉這一個會出錯 [3,3,1,3]
                --r;                    //會把最小值跳過
            }*/
            else{//nums[m]<nums[r]
                r = m;//r=m 有可能是最小的那一個, 所以不能用r = m-1跳過
                      //且包含m的情況下才會有非遞增區間 
            }        
        }
        return nums[r];
    }
    return nums[0];
}

//===思路====
(*)沒有明確的target, 要取遞增方向 或 遞減方向 來定義"判斷條件"
要取遞增方向: l = m+1;
- nums[m]<nums[r] 


要取遞減方向: r = m;
- nums[m]>nums[r]

因為有重複數字發生
r--; //[3,3,1,3]
取到first-middle = 3, 與nums[r]=3
所以r要退一個位置=> r--;


int helper3(vector<int>& nums){
    int l = 0, r = nums.size()-1;
    int m;
    
if(nums[l]>=nums[r]){
    while(l<r){
        m = l+(r-l)/2;
        if(nums[m]>nums[r]){
            l = m+1;
        }else if(nums[m]<nums[r]){
            r = m;
        }else{
            r--;
//          r = m;//[3,3,1,3] incorrect
        }
    }
    return nums[r];
}
return nums[0];
}    




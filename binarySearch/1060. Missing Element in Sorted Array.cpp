//=== more challenge

//=== 思路 ====
(*)binary search
一個區間的missig element個數,可以定義為
missing = nums[end]-nums[start]-(end-start);

binary_search跳出條件:
(start+1<end); 數列的index不能相連,不能是continuous

int missingElement(vector<int>& nums, int k) {
  int start = 0, end = nums.size()-1;
  int missing = nums[end] - nums[start] -(end-start);//missing count
  if(missing<k) return nums[end]+k-missing;
  
  while(start+1 < end){
    int mid = start + (end-start)/2;
    missing = nums[mid]-nums[start]-(mid-start);
    if(missing<k){
      k-=missing;
      start = mid; // 不用start=mid+1; 因為在while(start+1<end) 已經做了這個步驟
    }else{//missing >=k
      end = mid;
    }
  }
  return nums[start]+k;
}


//=== 思路2 ===
(*)兩個數值相差1, 則之間沒有missing element
nums[i]-nums[i-1]==1 , 沒有missing element

(*) 兩數值相差>1, 則之間有missing elemnt
- 計算 累加的missing slement是否有超過 k
count + (nums[i]-nums[i-1]-1)>=k
代表第kth個 missing element出現在此區間;所以
nums[i-1]+ (k-count) 即為解

- 若沒有超過, 累加missing element個數
count += (nums[i]-nums[i-1]-1);

(*)如果計算到最後一個區間, 累加的missing element都沒有超過k; 則回傳
nums[nums.size()-1]+(k-count)

(**) 概念:
數列個數, 數列位置index 的差異和計算
  
int missingElement(vector<int>& nums, int k) {
    int count = 0;
    int res = 0;
    
    for(int i=1; i<nums.size(); ++i){
        int tmp = nums[i]-nums[i-1]-1;
        if(tmp==0) continue;
        if((count+tmp)>=k){
            res = nums[i-1] + (k-count);
            break;        
        }else{//count+tmp<k;
            count += tmp;
        }
    }
    return (res==0)?(nums[nums.size()-1]+(k-count)):res;
}

//===類似題===
498. Diagonal Traverse
503. Next Greater Element II
556. Next Greater Element III
739. Daily Temperatures

//===思路====
(*) 建立兩個map
- 一個map紀錄原數列,每一個元素出現的位置
- 另外一個map紀錄"經過sort後的數列", 每一個元素出現的位置

nums1 = [4,1,2];
nums2 = [1,3,4,2];=> 經過sort [1,2,3,4]
         
(*)遍歷子數列num1
-找出子數列元素在sort陣列中的位置; 代表判斷比此數大的數,在nums2(不經排列)中,距離最短的數
-nums1[1]=1,在sort中為[0]
--for(x=0;x<sort.size();i++)//每一個比1大的數,相對於nums2[0]==1的距離
  1[0]~ 2[3] => 3
  1[0]~ 3[1] => 1 距離最短,取3
  1[0]~ 4[2] => 2
  
-如果沒有,則取(-1)  
//======
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int,int> mp;//val, index
    unordered_map<int,int> srt;//val,index sort
    vector<int> t = nums2;
    vector<int> res;
    int n = nums2.size();

    sort(t.begin(),t.end());

    for(int i=0;i<n;i++) {
        mp[nums2[i]]=i;
        srt[t[i]]=i;
    }
    
    for(int i=0;i<nums1.size();i++){
        int distance = INT_MAX;
        int ngrt;
        bool found = 0;
        int x = srt[nums1[i]];//t[x] = (sort_value > nums1[i])
        int y = mp[nums1[i]];   //position
        
        for(;x<t.size();x++){//在sort陣列中, 比nums1[i]數值大的所有位置
            int p = mp[t[x]];//對應在原數列中,大於nums1[i]的位址
            if(y<p){//如果此位置是在"右邊", 則判斷是否為最短距離
                if((p-y)<distance){
                    distance = (p-y);
                    ngrt = t[x];
                    found = 1;
                }
            }
        }
        if(found) res.push_back(ngrt);
        else res.push_back(-1);//no next greater value;        
    }
    return res;
}

//===思路2====
(*)可以用stack計算, stack思路可以加快執行效率
(*)建立unordered_map, 建立對應的數值和next_greater_element關係
- nums2 = [4,3,2,1,5]

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int,int> mp;//element_value, first_greater_value
    vector<int> stk;
    
    for(int i=0;i<nums2.size();i++){
         while(!stk.empty() && stk.back()<nums2[i]){
             mp[stk.back()] = nums2[i];
             stk.pop_back();
         }
         stk.push_back(nums2[i]);
    }
    for(int i=0;i<nums1.size();i++){
        if(mp.count(nums1[i])) res.push_back(mp[nums1[i]]);
        else res.push_back(-1);
    }
    return res;
}


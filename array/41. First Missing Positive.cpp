//====類似題====
42. Trapping Rain Water
765. Couples Holding Hands
2336. Smallest Number in Infinite Set

//====思路====
1.建立一priority queue 將所有的數值由小排到大
1.1 直接陣列做sorting(題目沒說不可以做sorting)
2.建立一map, 排除重複的數值
3. 從priority_queue 開始找lost值

//=====
int helper0(vector<int>& nums){
//priority_queue<T, vector<T>, greater<T> > pq;  改成由小排到大
        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_map<int,int> m;
        int counter = 1;
        
        for(int i=0;i<nums.size();i++){
            if(m.count(nums[i])) continue;//如果重複,就排除
            m[nums[i]]=1;//紀錄沒有出現過的數
            if(nums[i]>0) pq.push(nums[i]);//只把>0的數放入priority_queue      
        }  
        while(!pq.empty()){//搜尋lost的數值
            if(counter!=pq.top()){ 
                break;
            }    
            pq.pop();
            counter++;
        }
        return counter;
}
//=====思路===
1.直接陣列做sorting(題目沒說不可以做sorting)
2.在陣列最前面插入一非positive的數
3.尋找lost值
//======
int helper1(vector<int>& nums){
        int count=1;
        sort(nums.begin(),nums.end());//從小排到大
        nums.insert(nums.begin(),nums.end());//最前面插入一個非positive的數
        for(int i=0;i<nums.size();i++){//開始尋找lost值
            if(nums[i]<=0) continue;
            if(nums[i]==nums[i-1]) continue;
            if(count!=nums[i]) break;
            count++;
        }
        return count;
}
//====思路

//===
/*int helper2(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int i = 1;
        for(int x: nums) if(x == i) i++;
        return i;        
}*/

int firstMissingPositive(vector<int>& nums) {
        return helper0(nums);    
}

//===類似題===
350. Intersection of Two Arrays II
1213. Intersection of Three Sorted Arrays
2215. Find the Difference of Two Arrays
2085. Count Common Words With One Occurrence

//===思路====

//=====
 vector<int> helper0(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        vector<int> res;
        
        for(int i=0; i<nums1.size(); i++){
            map[nums1[i]]=1;
        }
        for(int i=0; i<nums2.size(); i++){
            if(map.count(nums2[i])){
                res.push_back(nums2[i]);
                map.erase(nums2[i]);//刪除目的是為了防止重複數值
                //map[nums2[i]]-=1;
            }
        }
        return res;
    }

vector<int> helper1(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int,int> m;
    vector<int> res;
    for(int i=0;i<nums1.size();++i){
        m[nums1[i]]++;
    }
    for(int j=0; j<nums2.size(); ++j){
        if(m[nums2[j]]){
            res.push_back(nums2[j]);
            m.erase(nums2[j]);
        }
    }
    return res;
}
vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
            return helper1(nums1,nums2);
//        return helper0(nums1,nums2);
}
//===思路2===
(*)利用binary search判斷其中一個陣列中的元素,是否有出現在另外一個陣列
- 另外一個陣列需要先作排列,才能用此算法
//=====
int binarySearch(vector<int>& nums, int target){
   int l = 0;
    int r = nums.size()-1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(nums[m]>target){
            r = m-1;
        }else if(nums[m]<target){
            l = m+1;
        }else{
            return m;
        }
    }
    return -1;
}
    
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    unordered_map<int,int> m;
    sort(nums2.begin(),nums2.end());//nums2先做排列
    for(int i = 0; i<nums1.size(); i++){//nums1的每一個與nums2比較,查看是否有存在
        if(binarySearch(nums2,nums1[i])!=-1){
            if(!m.count(nums1[i])){//不存在key,即加入map, 這一個目的是為了防止重複數值被push_back到res中
                m[nums1[i]]=1;
                res.push_back(nums1[i]);
            }
        }
    }
    return res;
}

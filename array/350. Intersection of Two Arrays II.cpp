//====類似題=====
351. Android Unlock Patterns
2215. Find the Difference of Two Arrays
2143. Choose Numbers From Two Arrays in Range
2248. Intersection of Multiple Arrays
//===思路=====
(*)unordered_map<int,int> m;
- 若有值帶入map中, map就會建立key,對應的值為0
m[5];//會建立key=5到map中    
//=======
vector<int> helper0(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int,int> m;
    vector<int> res;
    for(int i=0;i<nums1.size();++i){
        m[nums1[i]]++;
    }
    for(int j=0; j<nums2.size(); ++j){
        if(m[nums2[j]]){
            res.push_back(nums2[j]);
            --m[nums2[j]];//減去第二個陣列出現相同字元的個數
        }
    }
    return res;
}

vector<int> helper2(vector<int>& nums1, vector<int>& nums2){
    vector<int> res;
    unordered_map<int,int> mp;
    for(int num:nums1) mp[num]++;
    for(int i=0;i<nums2.size();++i){
        if(mp.count(nums2[i]) && mp[nums2[i]]){
            res.push_back(nums2[i]);
            mp[nums2[i]]--;
        }
    }
    return res;
}
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    return helper0(nums1,nums2);
}

//===failed===
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    unordered_map<int,int> m;
        
    for(auto a:nums1) m[a]++;
        
    for(auto a:nums2){
//        if(m[a]--) res.push_back(a);//這一段會有錯誤,因為map有數值帶入就會產生key
        if(m[a]){
            res.push_back(a);
            m[a]--;
        }
    }
    return res;
}

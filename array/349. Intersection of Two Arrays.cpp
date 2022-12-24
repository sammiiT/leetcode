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
                map.erase(nums2[i]);//
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

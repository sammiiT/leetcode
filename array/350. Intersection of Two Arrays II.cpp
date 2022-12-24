//====類似題=====
351. Android Unlock Patterns
2215. Find the Difference of Two Arrays
2143. Choose Numbers From Two Arrays in Range
2248. Intersection of Multiple Arrays

//===思路=====

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

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        return helper0(nums1,nums2);
    }

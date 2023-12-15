//===類似題===
1898. Maximum Number of Removable Characters
1665. Minimum Initial Energy to Finish Tasks
1901. Find a Peak Element II
309. Best Time to Buy and Sell Stock with Cooldown

//===思路===
(*)宣告一array, 每一個元素紀錄最大的數值; 用max(x,y)
(*)遍歷triplets, 並取出每一個element,做max(x,y)比較
-在比較的過程中, 如果元素[i]大於target[i], 則排除不比較

(*)最後的array是否等於target; 如果等於,則回傳true
//=====
bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    vector<int> res(3,0);
    for(int i=0;i<triplets.size();++i){
        if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2]){
            res[0]=max(res[0],triplets[i][0]);
            res[1]=max(res[1],triplets[i][1]);
            res[2]=max(res[2],triplets[i][2]);
        }
    }    
    return (res==target);    
}

//====寫法2====
(*)概念同寫法1

bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    int n = triplets.size();
    vector<int> tmp(triplets[0].size(),0); 
    
    for(int i=0 ;i<n; ++i){
        int p,q,r;
        if((p=max(tmp[0],triplets[i][0]))>target[0]) continue;
        if((q=max(tmp[1],triplets[i][1]))>target[1]) continue;
        if((r=max(tmp[2],triplets[i][2]))>target[2]) continue;
        
        if(p==target[0]&&q==target[1]&&r==target[2]) return true;    
        tmp[0]=p;
        tmp[1]=q;
        tmp[2]=r;
    }
    return false;
}

//===類似題===
1782. Count Pairs Of Nodes
2779. Maximum Beauty of an Array After Applying Operation
1346. Check If N and Its Double Exist
//===思路===

truct cmp{
    bool operator()(int& a, int& b){
        if(abs(a)==abs(b)){
            return (a<b);//larger value a put in pq.top();
        } else if(abs(a)>abs(b)){
            return true;
        } else {//abs(a)<abs(b)
            return false;
        } 
    }
};
int findClosestNumber(vector<int>& nums) {
        priority_queue<int,vector<int>,cmp> pq;
        for(int num:nums){ pq.push(num);}
        return pq.top();
}

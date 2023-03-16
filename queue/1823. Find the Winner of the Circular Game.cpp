//===類似題===
1824. Minimum Sideway Jumps
2328. Number of Increasing Paths in a Grid
1037. Valid Boomerang
1170. Compare Strings by Frequency of the Smallest Character
//===思路1====
(*)用vector做題
(*)vector.size()會變動; 因為每次都會erase一個數值
(*)超出vector邊界後的index
i = (i+k-1)%nums.size();
k-1的目的是因為將當下的點算在內
如果i+k,代表位移k個距離


//====
int helper0(int n, int k){//
    vector<int> nums;
    for(int i=1; i<=n; i++) nums.push_back(i);
    int j = 0;
    while(nums.size()>1){
        j=(j+(k-1))%nums.size();
        nums.erase(nums.begin()+j);
    }
    return nums.back();
}

//===思路2==
(*)用queue做題

//===
int helper1(int n, int k){//queue
    queue<int> q;
    for(int i=1; i<=n; i++) q.push(i);
    while(q.size()>1){
        for(int i=0;i<k-1;i++) {
            int t = q.front();
            q.pop();
            q.push(t);
        }
        q.pop();
    }
    return q.front();
}

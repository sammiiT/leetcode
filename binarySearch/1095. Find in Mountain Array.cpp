//===類似題====
1096. Brace Expansion II
852. Peak Index in a Mountain Array
1671. Minimum Number of Removals to Make Mountain Array
2100. Find Good Days to Rob the Bank

//===思路===
(*) mountain array (單一一個mountain)
-可以利用binary search方式求出peak index
(*)找到peak index之後, 分為左半部, 右半部 搜尋target


//===
int helper(MountainArray &mountainArr,int target, int l, int r, bool isAsc){
    while(l<r){
        int m = l + (r-l)/2;
        int cur = mountainArr.get(m); 
        if(cur==target) return m;
        else if(cur < target){
            if(isAsc) l = m+1;
            else r = m;
        }
        else{//mountainArr.get(m)>target
            if(isAsc) r = m;
            else l = m+1;
        }
    }
    return (mountainArr.get(r)==target)? r: -1;
}


int findInMountainArray(int target, MountainArray &mountainArr) {
    int l=0, r=mountainArr.length()-1,peak = -1;
    while(l<r){
        int m = l +(r-l)/2;
        if(mountainArr.get(m)<mountainArr.get(m+1)) l = m+1;
        else //mountainArr.get(m)>=mountainArr.get(m+1)
            r = m;
    }//l==r,  not out of range
    peak = r;
//    peak = l;
    if(mountainArr.get(peak)==target) return peak;
    int idx1 = helper(mountainArr,target,0,peak-1,true);
    int idx2 = helper(mountainArr,target, peak+1, mountainArr.length()-1, false);

    return (idx1==-1)?idx2:idx1;
}

//===failed 超出搜尋次數 =====

//會超出搜尋次數定義
int findInMountainArray(int target, MountainArray &mountainArr) {
    int min_idx =-1;
    int mx = 0;
    
    for(int i =1; i<mountainArr.length(); i++){
        if(mountainArr.get(i-1)==target){
            min_idx = i-1;
        }
        if(mountainArr.get(i)<mountainArr.get(i-1)) {
            mx = i-1;
            break;
        }
    }
    int l = mx , r = mountainArr.length();
    while(l<r){
        int m = l+(r-l)/2;
        if(mountainArr.get(m)<=target) r = m;
        else //mountainArr.get(m)>target
            l = m+1;
    }
    return (min_idx<0)?(mountainArr.get(r)==target? r : -1):min_idx;
}


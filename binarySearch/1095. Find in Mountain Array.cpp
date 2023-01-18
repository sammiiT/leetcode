//===類似題====
1096. Brace Expansion II
852. Peak Index in a Mountain Array
1671. Minimum Number of Removals to Make Mountain Array
2100. Find Good Days to Rob the Bank

//===思路===

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


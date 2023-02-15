//===類似題===
375. Guess Number Higher or Lower II
375. Guess Number Higher or Lower II

//===思路===
(*)binary search: 一定有解算法
(*)binary search: lower_bounded 算法
//=====一定有解算法====
int helper1(int n){
    int l=1,r=n;
    int m = 0;
    while(l<=r){
        m = l+(r-l)/2;
        int test = guess(m);
        if(test==-1){//num>target(pick)
              r=m-1;  
        }else if(test==1){//nums<target(pick)
              l=m+1;  
        }else if(test==0){//target == m
            break;
        }
    }
    return m;
}
//=====lower_bounded算法====
int helper0(int n){
    int l=1,r=n;
    while(l<r){
        int m = l+(r-l)/2;
        int test = guess(m);
        if(test==0){
            return m;
        }else if(test==-1){//num>pick(target)
            r = m;
        }else if(test==1){//num<pick(target)
            l = m+1;
        }
    }
    return r;
}

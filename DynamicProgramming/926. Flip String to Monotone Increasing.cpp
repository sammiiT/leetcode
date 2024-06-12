//=== more challenge ===
2712. Minimum Cost to Make All Characters Equal

//=== 思路 ===
(*)兩個dp, 一個按照index ; 初始值在當下的index上
  一個不按照index, 將原本位置的 dp值 update到不同於 index的位置上; 邊界(初始值)在另外的index上

(*)左邊的1和右邊的0 相加, 最小的值就是解
  
int minFlipsMonoIncr(string s) {
    int n = s.size(), res = INT_MAX;
    vector<int> cnt0(n+1),cnt1(n+1);

    for(int i=1,j=n-1; j>=0; ++i,--j){
        cnt1[i]=cnt1[i]+cnt1[i-1]+(s[i-1]=='1'?1:0);
        cnt0[j]=cnt0[j]+cnt0[j+1]+(s[j]=='0'?1:0);
    }        
    for(int i=0; i<=n; ++i) res = min(res,cnt0[i]+cnt1[i]);
    return res;
}

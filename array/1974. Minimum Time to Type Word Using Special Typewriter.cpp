//===類似題====
1975. Maximum Matrix Sum
1320. Minimum Distance to Type a Word Using Two Fingers

//===思路===
path1 = abs(start-end)%n
path2 = abs(n-path1)
res += min(path1,path2)+1;//加1是要type的動作

1.用for迴圈, 不用while(index不用自己控制)
2. initial condition = start = 'a';
3. 每次計算  end=s[i], start是initial condition且每次運算後會做一次update     
3.1 path1 = abs((start-'a')-(s[i]-'a'))%26
    path2 = abs(26-path1)
4. res += min(path1,path2) +1;// +1是type的動作    
5. start = s[i];//執行完之後要更新一次start  

(*)差值不用作取餘數, 加法才會超過邊界 => 修改helper0
//====
int helper0(string word) {
    int res = 0;
    char start = 'a';
    
    for(int i=0; i<word.size(); i++){
        int path1 = abs((start-'a')-(word[i]-'a'))%26;//差值不用作取餘數, 加法才會超過邊界
        int path2 = abs(26-path1);
        res = res + min(path1,path2)+1;
        start = word[i];
    }        
    return res;
}

int helper1(string word) {
    int res = 0;
    char start = 'a';
    
    for(int i=0; i<word.size(); i++){
        int path1 = abs((start-'a')-(word[i]-'a'));//差值不用作取餘數, 加法才會超過邊界
        int path2 = abs(26-path1);
        res = res + min(path1,path2)+1;
        start = word[i];
    }        
    return res;
}




 int minTimeToType(string word) {
    return helper0(word); 
 }
//========
int minTimeToType(string w) {
        int ans=1;
        ans+=min(abs(w[0]-'a'),26-abs(w[0]-'a'));
        for(int i=1;i<w.size();++i){
            ++ans;
            int dist=abs(w[i]-w[i-1]);
            ans+=min(dist,26-dist);
        }
        return ans;
}
